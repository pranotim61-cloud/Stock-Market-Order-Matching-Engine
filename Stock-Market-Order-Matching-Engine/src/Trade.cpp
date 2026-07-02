#include <iostream>
#include "../include/Trade.h"

using namespace std;

Trade::Trade(int buyOrderId, int sellOrderId, double price, int quantity, int timestamp){
    this->buyOrderId = buyOrderId;
    this->sellOrderId = sellOrderId;
    this->price = price;
    this->quantity = quantity;
    this->timestamp = timestamp;
}

void Trade::print() const{
    cout << "TRADE  buy=" << buyOrderId
         << " sell=" << sellOrderId
         << " price=" << price
         << " qty=" << quantity
         << " t=" << timestamp
         << endl;
}

int Trade::getBuyOrderId() const { return buyOrderId; }
int Trade::getSellOrderId() const { return sellOrderId; }
double Trade::getPrice() const { return price; }
int Trade::getQuantity() const { return quantity; }
int Trade::getTimestamp() const { return timestamp; }