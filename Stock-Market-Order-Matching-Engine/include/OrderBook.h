#pragma once

#include<vector>
#include"Order.h"

class OrderBook{
    private:
        std::vector<Order> orders;

    public:
        OrderBook();
        void addOrder(const Order& order);
};