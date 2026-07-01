#include<iostream>
#include "include/Order.h"

using namespace std;

int main(){

    int id;
    double price;
    int quantity;
    bool isBuy;
    int timestamp;

    cout<< "Enter Order ID: " ;
    cin>> id;

    cout<< "Enter Price: " ;
    cin>> price;

    cout<< "Enter Quantity: " ;
    cin>> quantity;

    cout<< "Enter Order Type (1 = Buy, 0 = Sell): " ;
    cin>> isBuy;

    cout<< "Enter Timestamp: " ;
    cin>> timestamp;

    Order order(id, price, quantity, isBuy, timestamp);

    cout<< "\nOrder Details\n";
    order.print();

    return 0;
}