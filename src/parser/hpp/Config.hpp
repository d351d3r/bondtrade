//
// Created by Anatolii Cherednichenko on 16.10.2023.
//

#ifndef BONDTRADE_CONFIG_HPP
#define BONDTRADE_CONFIG_HPP
#include <string>

class Config {
public:
    Config(std::string user, std::string password, std::string proxy_url, int debug_level);
    std::string user, password, proxy_url, auth_url;
    int debug_level;
};

#endif //BONDTRADE_CONFIG_HPP
