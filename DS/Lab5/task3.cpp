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

    int singli_length(Node *temp)
    {
        int static count = 0;
        if (temp == NULL)
            return count;

        count++;
        singli_length(temp->next);
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

    //Singli length
    cout<<"\n\nSingli length: "<<obj.singli_length(obj.head);

    return 0;
}