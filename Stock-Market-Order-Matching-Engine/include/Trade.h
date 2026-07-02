#pragma once

class Trade
{
private:
    int buyOrderId;
    int sellOrderId;
    double price;
    int quantity;
    int timestamp;

public:
    Trade(int buyOrderId, int sellOrderId, double price, int quantity, int timestamp);

    void print() const;

    int getBuyOrderId() const;
    int getSellOrderId() const;
    double getPrice() const;
    int getQuantity() const;
    int getTimestamp() const;
};