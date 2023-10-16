#pragma once
#include <string>
#include <vector>
#include <tuple>

class MyData {
public:
    void add_history(const std::vector<std::tuple<std::string, double, int>>& new_data);
    void print_history();

private:
    std::vector<std::tuple<std::string, double, int>> history;
};
