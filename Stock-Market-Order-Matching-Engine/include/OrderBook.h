#pragma once

#include<vector>
#include"Order.h"
using namespace std;

class OrderBook{
    private:
        vector<Order> buyOrders;
        vector<Order> sellOrders;

    public:
        OrderBook();
        void addOrder(const Order& order);
        void matchOrders();
};