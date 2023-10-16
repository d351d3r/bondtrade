#include "MicexAuth.hpp"
#include <curl/curl.h>
#include <iostream>

MicexAuth::MicexAuth(Config& config) : config(config) {
    auth();
}

bool MicexAuth::is_real_time() {
    return !passport.empty();
}

size_t MicexAuth::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

size_t header_callback(char* buffer, size_t size, size_t nitems, void* userdata) {
    std::string header(buffer, size * nitems);
    if (header.find("Set-Cookie: MicexPassportCert=") != std::string::npos) {
        std::string cookie = header.substr(header.find('=') + 1);
        if (cookie.back() == '\r' || cookie.back() == '\n') cookie.pop_back();
        *(static_cast<std::string*>(userdata)) = cookie;
    }
    return size * nitems;
}

void MicexAuth::auth() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, config.auth_url.c_str());

        if(!config.proxy_url.empty()) {
            curl_easy_setopt(curl, CURLOPT_PROXY, config.proxy_url.c_str());
        }

        std::string userPass = config.user + ":" + config.password;
        curl_easy_setopt(curl, CURLOPT_USERPWD, userPass.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &passport);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
}
