#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

// struct Node
// {
//     int data;
//     Node *next;
// };

class Singli
{
public:
    Node *head, *tail;

    Singli()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_tail(int num)
    {
        Node *temp = new Node(num);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
            tail->next = NULL;
        }
    }

    void display()
    {
        Node *temp = head;

        cout << "\nList Data: \n\n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool search(Node *temp, int data)
    {
        if (temp == NULL)
        {
            cout<<"\nData Not found!";
            return 0;
        }
        
        if (temp->data == data)
        {
            cout<<"\nData found!";
            return 1;
        }
        

        search(temp->next, data);
    }
};

int main()
{

    Singli obj;

    obj.insert_at_tail(1);
    obj.insert_at_tail(2);
    obj.insert_at_tail(3);
    obj.insert_at_tail(4);

    obj.display();

    //Search
    obj.search(obj.head, 3);

    return 0;
}