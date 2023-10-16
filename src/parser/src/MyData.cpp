#include "MyData.hpp"
#include <iostream>
#include <cstdio>

void MyData::add_history(const std::vector<std::tuple<std::string, double, int>>& new_data) {
    history.insert(history.end(), new_data.begin(), new_data.end());
}

void MyData::print_history() {
    std::cout << std::string(49, '=') << std::endl;
    std::printf("|%15s|%15s|%15s|\n", "SECID", "CLOSE", "TRADES");
    std::cout << std::string(49, '=') << std::endl;
    for (const auto& sec : history) {
        std::printf("|%15s|%15.2f|%15d|\n", std::get<0>(sec).c_str(), std::get<1>(sec), std::get<2>(sec));
    }
    std::cout << std::string(49, '=') << std::endl;
}
