#include<iostream>
#include"../include/OrderBook.h"
#include <algorithm>
using namespace std;

OrderBook::OrderBook(){
}

void OrderBook::addOrder(const Order& order){
    if(order.getIsBuy()){
        buyOrders.push_back(order);
    }
    else{
        sellOrders.push_back(order);
    }
}

void OrderBook::matchOrders(){
    if(buyOrders.empty() || sellOrders.empty()){
        return;
    }

    Order& buy= buyOrders.front();
    Order& sell = sellOrders.front();

    if (buy.getPrice() >= sell.getPrice()){
        int tradedQuantity = std::min(buy.getQuantity(), sell.getQuantity());

        Trade trade(buy.getId(), sell.getId(), sell.getPrice(),tradedQuantity);
        tradeHistory.push_back(trade);
        trade.print();

        buy.setQuantity(buy.getQuantity() - tradedQuantity);
        sell.setQuantity(sell.getQuantity() - tradedQuantity);

        if(buy.getQuantity() == 0){
            buyOrders.erase(buyOrders.begin());
        }

        if(sell.getQuantity() == 0){
            sellOrders.erase(sellOrders.begin());
        }

        std::cout << "Trade Executed!" << std::endl;
        std::cout << "Quantity: "<< tradedQuantity<< std::endl;
    }
}