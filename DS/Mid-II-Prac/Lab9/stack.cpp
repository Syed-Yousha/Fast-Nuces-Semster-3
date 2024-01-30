#include <iostream>
using namespace std;

#define Max 4

class Stack {
    int top;

public:
    string a[Max];

    Stack() : top(-1) {}

    bool push(string x) {
        if (top >= Max - 1) {
            cout << "\nStack overflow";
            return false;
        } else {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }

    string pop() {
        if (top < 0) {
            cout << "\nStack underflow";
            return "";
        } else {
            string x = a[top--];
            return x;
        }
    }

    string peek() {
        if (top < 0) {
            cout << "\nStack is empty!";
            return "";
        } else {
            string x = a[top];
            return x;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack list;


    list.push("task1");
    list.push("task2");
    list.push("task3");
    list.push("task4");


    cout << "\nTop element: " << list.peek();

    cout << "\n\nPopping all items";
    while (!list.isEmpty()) {
        cout << endl << list.pop();
    }

    return 0;
}

