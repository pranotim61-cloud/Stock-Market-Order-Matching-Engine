#include<iostream>
#include"../include/OrderBook.h"
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

    Order buy= buyOrders.front();
    Order sell = sellOrders.front();

    if(buy.getPrice() >= sell.getPrice()){
        std::cout << "Trade Executed!" << std::endl;
    }
}