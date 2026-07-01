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
    cout<< "isBuy : "<< isBuy<< endl;
    cout<< "quantity : "<< quantity<< endl;
    cout<< "timestamp : "<< timestamp<< endl;
}

int Order::getId(){
    return id;
}

double Order::getPrice()
{
    return price;
}

int Order::getQuantity()
{
    return quantity;
}

bool Order::getIsBuy()
{
    return isBuy;
}

int Order::getTimestamp()
{
    return timestamp;
}