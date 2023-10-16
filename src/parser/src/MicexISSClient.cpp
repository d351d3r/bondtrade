#include "MicexISSClient.hpp"
#include <curl/curl.h>

MicexISSClient::MicexISSClient(Config& config, MicexAuth& auth, MicexISSDataHandler& handler)
        : config(config), auth(auth), handler(handler) {}

bool MicexISSClient::get_history_securities(const std::string& engine, const std::string& market,
                                            const std::string& board, const std::string& date) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    std::string url = "http://iss.moex.com/iss/history/engines/" + engine + "/markets/" + market + "/boards/" + board + "/securities.json?date=" + date;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Устанавливаем пустой файл cookie для включения обработки cookies
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, MicexAuth::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return false;
        }

        json jres = json::parse(readBuffer);
        handler.do_handler(jres["history"]["data"]);

        curl_easy_cleanup(curl);
    }
    return true;
}


MicexISSDataHandler* MicexISSClient::get_data_handler() {
    return &handler;
}
