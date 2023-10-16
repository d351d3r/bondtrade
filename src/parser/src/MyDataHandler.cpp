#include "MyDataHandler.hpp"

MyDataHandler::MyDataHandler() : MicexISSDataHandler() {}

void MyDataHandler::do_handler(const json& market_data) {
    std::vector<std::tuple<std::string, double, int>> new_data;
    for (const auto& entry : market_data) {
        std::string secid = entry[0];
        double close = entry[1].is_null() ? 0.0 : entry[1].get<double>();
        int trades = entry[2].is_null() ? 0 : entry[2].get<int>();
        new_data.emplace_back(secid, close, trades);
    }
    data.add_history(new_data);
}
