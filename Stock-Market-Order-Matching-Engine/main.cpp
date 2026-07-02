#include <iostream>
#include "include/Order.h"
#include "include/OrderBook.h"

using namespace std;

int main(){
    OrderBook book;
    int nextId = 1;
    int timestampCounter = 0;

    while (true){
        cout << "\n=== Order Matching Engine ===\n";
        cout << "1. Add Order\n";
        cout << "2. Cancel Order\n";
        cout << "3. Modify Order Quantity\n";
        cout << "4. Print Order Book\n";
        cout << "5. Print Trade History\n";
        cout << "6. Exit\n";
        cout << "Choice: ";

        int choice;
        if (!(cin >> choice)) break;

        if (choice == 6) break;

        switch (choice){
            case 1: {
                double price;
                int quantity;
                int sideInput;

                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Order side (1 = Buy, 0 = Sell): ";
                cin >> sideInput;

                Order order(nextId, price, quantity, sideInput == 1, timestampCounter++);
                cout << "Order ID assigned: " << nextId << endl;
                nextId++;
                book.addOrder(order);
                break;
            }
            case 2: {
                int id;
                cout << "Enter Order ID to cancel: ";
                cin >> id;
                cout << (book.cancelOrder(id) ? "Order cancelled." : "Order not found.") << endl;
                break;
            }
            case 3: {
                int id, qty;
                cout << "Enter Order ID to modify: ";
                cin >> id;
                cout << "Enter new quantity: ";
                cin >> qty;
                cout << (book.modifyOrder(id, qty) ? "Order modified." : "Order not found.") << endl;
                break;
            }
            case 4:
                book.printBook();
                break;
            case 5:
                book.printTradeHistory();
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    cout << "\n--- Final Trade History ---" << endl;
    book.printTradeHistory();

    return 0;
}
