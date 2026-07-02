#pragma once

class Trade
{
private:
    int buyOrderId;
    int sellOrderId;
    double price;
    int quantity;

public:
    Trade(int buyOrderId, int sellOrderId, double price, int quantity);

    void print() const;
};