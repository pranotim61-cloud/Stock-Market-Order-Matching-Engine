#include<iostream>
#include "../include/Order.h"
using namespace std;

Order::Order(int id, double price, int quantity, bool isBuy, int timestamp){
    this->id=id;
    this->price= price;
    this->quantity = quantity;
    this->originalQuantity = quantity;
    this->isBuy = isBuy;
    this->timestamp = timestamp;
}

void Order::print() const{
    cout << "ID: " << id
         << " | " << (isBuy ? "BUY " : "SELL")
         << " | Price: " << price
         << " | Qty: " << quantity << "/" << originalQuantity
         << " | t=" << timestamp
         << endl;
}

int Order::getId() const{
    return id;
}

double Order::getPrice() const{
    return price;
}

int Order::getQuantity() const{
    return quantity;
}

int Order::getOriginalQuantity() const{
    return originalQuantity;
}

bool Order::getIsBuy() const{
    return isBuy;
}

int Order::getTimestamp() const{
    return timestamp;
}

void Order::setQuantity(int quantity){
    this->quantity = quantity;
}