#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(NULL) {}
};

class Singli
{
public:
    Node *head;
    Node *tail;

    Singli()
    {
        head = NULL;
        tail = NULL;
    }

    void add_at_tail(int data)
    {
        Node *temp;
        temp->data = data;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }    
    }

};

int main()
{
    return 0;
}