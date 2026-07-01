#include<iostream>
#include "include/Order.h"

using namespace std;

int main(){
    Order order(1, 100.5, 50, true, 1);

    order.print();

    return 0;
}