#include <iostream>
#include <algorithm>
#include "../include/OrderBook.h"
using namespace std;

OrderBook::OrderBook(){
    tradeTimestampCounter = 0;
}

void OrderBook::executeTrade(Order& buyOrder, Order& sellOrder, double tradePrice){
    int tradedQty = min(buyOrder.getQuantity(), sellOrder.getQuantity());

    Trade trade(buyOrder.getId(), sellOrder.getId(), tradePrice, tradedQty, tradeTimestampCounter++);
    tradeHistory.push_back(trade);
    trade.print();

    buyOrder.setQuantity(buyOrder.getQuantity() - tradedQty);
    sellOrder.setQuantity(sellOrder.getQuantity() - tradedQty);
}

void OrderBook::matchOrder(Order incoming){
    if (incoming.getIsBuy()){

        while (incoming.getQuantity() > 0 && !sellLevels.empty()){
            auto bestLevel = sellLevels.begin();
            double bestSellPrice = bestLevel->first;
            if (incoming.getPrice() < bestSellPrice) break;

            deque<Order>& level = bestLevel->second;
            while (incoming.getQuantity() > 0 && !level.empty()){
                Order& resting = level.front();
                executeTrade(incoming, resting, resting.getPrice());
                if (resting.getQuantity() == 0){
                    orderIndex.erase(resting.getId());
                    level.pop_front();
                }
            }
            if (level.empty()) sellLevels.erase(bestLevel);
        }

        if (incoming.getQuantity() > 0){
            double p = incoming.getPrice();
            buyLevels[p].push_back(incoming);
            orderIndex[incoming.getId()] = {true, p};
        }
    }
    else{
        while (incoming.getQuantity() > 0 && !buyLevels.empty()){
            auto bestLevel = buyLevels.begin();
            double bestBuyPrice = bestLevel->first;
            if (incoming.getPrice() > bestBuyPrice) break;

            deque<Order>& level = bestLevel->second;
            while (incoming.getQuantity() > 0 && !level.empty()){
                Order& resting = level.front();
                executeTrade(resting, incoming, resting.getPrice());
                if (resting.getQuantity() == 0){
                    orderIndex.erase(resting.getId());
                    level.pop_front();
                }
            }
            if (level.empty()) buyLevels.erase(bestLevel);
        }

        if (incoming.getQuantity() > 0){
            double p = incoming.getPrice();
            sellLevels[p].push_back(incoming);
            orderIndex[incoming.getId()] = {false, p};
        }
    }
}

void OrderBook::addOrder(Order order){
    if (order.getQuantity() <= 0){
        cout << "Rejected order " << order.getId() << ": quantity must be positive." << endl;
        return;
    }
    if (order.getPrice() <= 0){
        cout << "Rejected order " << order.getId() << ": price must be positive." << endl;
        return;
    }

    matchOrder(order);
}

bool OrderBook::cancelOrder(int id){
    auto it = orderIndex.find(id);
    if (it == orderIndex.end()) return false;

    bool isBuy = it->second.isBuy;
    double price = it->second.price;

    auto eraseFrom = [&](auto& levels){
        auto levelIt = levels.find(price);
        if (levelIt != levels.end()){
            auto& dq = levelIt->second;
            for (auto orderIt = dq.begin(); orderIt != dq.end(); ++orderIt){
                if (orderIt->getId() == id){
                    dq.erase(orderIt);
                    break;
                }
            }
            if (dq.empty()) levels.erase(levelIt);
        }
    };

    if (isBuy) eraseFrom(buyLevels);
    else eraseFrom(sellLevels);

    orderIndex.erase(it);
    return true;
}

bool OrderBook::modifyOrder(int id, int newQuantity){
    auto it = orderIndex.find(id);
    if (it == orderIndex.end()) return false;

    if (newQuantity <= 0){
        return cancelOrder(id);
    }

    bool isBuy = it->second.isBuy;
    double price = it->second.price;

    auto modifyIn = [&](auto& levels) -> bool {
        auto levelIt = levels.find(price);
        if (levelIt == levels.end()) return false;
        for (auto& o : levelIt->second){
            if (o.getId() == id){
                o.setQuantity(newQuantity);
                return true;
            }
        }
        return false;
    };

    return isBuy ? modifyIn(buyLevels) : modifyIn(sellLevels);
}

void OrderBook::printBook() const{
    cout << "\n----- ORDER BOOK -----" << endl;
    cout << "BUY side (best price first):" << endl;
    for (auto& level : buyLevels){
        for (auto& o : level.second){
            o.print();
        }
    }
    cout << "SELL side (best price first):" << endl;
    for (auto& level : sellLevels){
        for (auto& o : level.second){
            o.print();
        }
    }
    cout << "-----------------------\n" << endl;
}

void OrderBook::printTradeHistory() const{
    if (tradeHistory.empty()){
        cout << "No trades executed yet." << endl;
        return;
    }
    for (auto& t : tradeHistory){
        t.print();
    }
}
