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
        int getId() const;
        double getPrice() const;
        int getQuantity() const;
        bool getIsBuy() const;
        int getTimestamp() const;
};