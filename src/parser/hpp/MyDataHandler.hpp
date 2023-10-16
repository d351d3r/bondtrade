#pragma once
#include "MicexISSDataHandler.hpp"
#include "MyData.hpp"

class MyDataHandler : public MicexISSDataHandler {
public:
    MyDataHandler();
    void do_handler(const json& market_data) override;

private:
    MyData data;
};
