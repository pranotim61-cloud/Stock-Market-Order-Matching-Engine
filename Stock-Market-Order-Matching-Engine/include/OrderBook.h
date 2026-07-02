#pragma once

#include<vector>
#include"Order.h"
#include"Trade.h"
using namespace std;

class OrderBook{
    private:
        vector<Order> buyOrders;
        vector<Order> sellOrders;
        vector<Trade> tradeHistory;

    public:
        OrderBook();
        void addOrder(const Order& order);
        void matchOrders();
};