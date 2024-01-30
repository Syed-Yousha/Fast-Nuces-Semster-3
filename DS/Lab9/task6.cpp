#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Patron {
    string name;
    int transactionTime;
};

int main() {
    queue<Patron> patronQueue;

    while (true) {
        cout << "Choose an option:\n";
        cout << "1. Add yourself to the queue\n";
        cout << "2. Complete your book transaction and leave\n";
        cout << "3. Display the current queue\n";
        cout << "4. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            Patron patron;
            cout << "Enter your name: ";
            cin >> patron.name;
            cout << "Enter the estimated transaction time (in minutes): ";
            cin >> patron.transactionTime;
            patronQueue.push(patron);
            cout << patron.name << " added to the queue.\n";
        } else if (choice == 2) {
            if (!patronQueue.empty()) {
                Patron nextPatron = patronQueue.front();
                patronQueue.pop();
                cout << nextPatron.name << " has completed their transaction and left.\n";
            } else {
                cout << "No patrons in the queue.\n";
            }
        } else if (choice == 3) {
            cout << "Current Queue of Patrons:\n";
            queue<Patron> tempQueue = patronQueue;
            while (!tempQueue.empty()) {
                Patron currentPatron = tempQueue.front();
                tempQueue.pop();
                cout << currentPatron.name << " (Estimated Time: " << currentPatron.transactionTime << " minutes)\n";
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, 3, or 4." << endl;
        }
    }

    return 0;
}

