#pragma once


class Order{
    private:
        int id;
        double price;
        int quantity;
        int originalQuantity;
        bool isBuy;
        int timestamp;

    public:
        Order(int id, double price, int quantity, bool isBuy, int timestamp);

        void print() const;

        int getId() const;
        double getPrice() const;
        int getQuantity() const;
        int getOriginalQuantity() const;
        bool getIsBuy() const;
        int getTimestamp() const;

        void setQuantity(int quantity);
};