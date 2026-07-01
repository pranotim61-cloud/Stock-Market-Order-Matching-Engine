#include<iostream>
#include "../include/Order.h"
using namespace std;

Order::Order(int id, double price, int quantity, bool isBuy, int timestamp){
    this->id=id;
    this->price= price;
    this->isBuy= isBuy;
    this->quantity= quantity;
    this->timestamp= timestamp;
}

void Order::print(){
    cout<< "id : "<< id<< endl;
    cout<< "price : "<< price<< endl;
    cout<< "Type: "<< (isBuy ? "BUY" : "SELL") << endl;
    cout<< "quantity : "<< quantity<< endl;
    cout<< "timestamp : "<< timestamp<< endl;
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

bool Order::getIsBuy() const{
    return isBuy;
}

int Order::getTimestamp() const{
    return timestamp;
}