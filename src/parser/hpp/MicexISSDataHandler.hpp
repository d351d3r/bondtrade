#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class MicexISSDataHandler {
public:
    virtual void do_handler(const json& data) = 0;
};
