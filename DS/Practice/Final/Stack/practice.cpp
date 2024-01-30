#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(NULL) {}
    };

    Node* top;

public:
    Stack() : top(NULL) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Error: Trying to pop from an empty stack.\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    T& peek() const {
        if (isEmpty()) {
        	std::cout<<"\nout of range";
        	exit;
		}
        return top->data;
    }

    bool isEmpty() const {
        return top == NULL;
    }
};

int main() {
    Stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    while (!myStack.isEmpty()) {
        std::cout << myStack.peek() << " ";  // Output: 30 20 10
        myStack.pop();
    }

    return 0;
}

