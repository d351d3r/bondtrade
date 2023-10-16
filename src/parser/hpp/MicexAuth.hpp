#pragma once
#include "Config.hpp"
#include <string>

class MicexAuth {
public:
    MicexAuth(Config& config);
    bool is_real_time();

private:
    Config& config;
    std::string passport;
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    void auth();
};
