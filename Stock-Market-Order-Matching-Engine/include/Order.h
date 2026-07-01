#pragma once

class Order{
    private:
        int id;
        double price;
        int quantity;
        bool isBuy;
        int timestamp;

    public:
        Order(int id, double price, int quantity, bool isBuy, int timestamp);
        void print();
        int getId();
        double getPrice();
        int getQuantity();
        bool getIsBuy();
        int getTimestamp();
};