#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(NULL), tail(NULL) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sort()
    {
        if (head == NULL)
            return;

        Node *current;
        Node *nextNode = NULL;
        bool sorted = false;

        while (!sorted)
        {
            sorted = true;
            current = head;

            while (current->next != nextNode)
            {
                if (current->data > current->next->data)
                {
                    swap(current->data, current->next->data);
                    sorted = false;
                }
                current = current->next;
            }
            nextNode = current;
        }
    }
};

int main()
{
    LinkedList list;

    list.insert(3);
    list.insert(1);
    list.insert(5);
    list.insert(2);
    list.insert(4);

    cout << "Original list: ";
    list.display();

    list.sort();

    cout << "Sorted list: ";
    list.display();

    return 0;
}
