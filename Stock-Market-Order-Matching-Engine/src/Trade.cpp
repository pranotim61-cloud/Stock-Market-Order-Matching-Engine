#include <iostream>
#include "../include/Trade.h"

using namespace std;

Trade::Trade(int buyOrderId, int sellOrderId, double price, int quantity){
    this->buyOrderId = buyOrderId;
    this->sellOrderId = sellOrderId;
    this->price = price;
    this->quantity = quantity;
}

void Trade::print() const{
    cout << "Trade Executed\n";
    cout << "Buy Order ID : " << buyOrderId << endl;
    cout << "Sell Order ID : " << sellOrderId << endl;
    cout << "Price : " << price << endl;
    cout << "Quantity : " << quantity << endl;
}