#pragma once

#include <map>
#include <deque>
#include <unordered_map>
#include <vector>
#include "Order.h"
#include "Trade.h"

class OrderBook{
    private:
        std::map<double, std::deque<Order>, std::greater<double>> buyLevels;
        std::map<double, std::deque<Order>, std::less<double>> sellLevels;

        struct OrderLocation {
            bool isBuy;
            double price;
        };
        std::unordered_map<int, OrderLocation> orderIndex;

        std::vector<Trade> tradeHistory;
        int tradeTimestampCounter;

        void executeTrade(Order& buyOrder, Order& sellOrder, double tradePrice);
        void matchOrder(Order incoming);

    public:
        OrderBook();

        void addOrder(Order order);
        bool cancelOrder(int id);
        bool modifyOrder(int id, int newQuantity);

        void printBook() const;
        void printTradeHistory() const;
};
