#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Order {
    string itemName;
    int quantity;
};

void addOrder(queue<Order>& orderQueue, const Order& order) {
    orderQueue.push(order);
}

bool processOrder(queue<Order>& orderQueue) {
    if (!orderQueue.empty()) {
        Order order = orderQueue.front();
        cout << "Processing order: " << order.quantity << "x " << order.itemName << endl;
        orderQueue.pop();
        return true;
    } else {
        cout << "No orders to process." << endl;
        return false;
    }
}

int main() {
    queue<Order> orderQueue;

    while (true) {
        cout << "Choose an option:\n";
        cout << "1. Add an order\n";
        cout << "2. Process the next order\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            Order order;
            cout << "Enter the item name: ";
            cin >> order.itemName;
            cout << "Enter the quantity: ";
            cin >> order.quantity;
            addOrder(orderQueue, order);
        } else if (choice == 2) {
            processOrder(orderQueue);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    while (!orderQueue.empty()) {
        processOrder(orderQueue);
    }

    return 0;
}

