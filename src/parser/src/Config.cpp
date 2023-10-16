#include "Config.hpp"

Config::Config(std::string user, std::string password, std::string proxy_url, int debug_level)
        : user(user), password(password), proxy_url(proxy_url), debug_level(debug_level) {
    auth_url = "https://passport.moex.com/authenticate";
}
