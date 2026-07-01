#include"../include/OrderBook.h"

OrderBook::OrderBook(){
}

void OrderBook::addOrder(const Order& order){
    orders.push_back(order);
}