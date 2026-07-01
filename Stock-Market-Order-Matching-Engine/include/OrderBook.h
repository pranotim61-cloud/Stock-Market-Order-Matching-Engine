#pragma once

#include<vector>
#include"Order.h"

class OrderBook{
    private:
        std::vector<Order> order;

    public:
        OrderBook();
};