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
        Node *temp = new Node(data);
        // temp->data = data;

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

    void display()
    {
        Node *temp = head;

        cout << "\n\nLinked list data: \n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void sort_list()
    {
        if (head == NULL || head->next == NULL)
        {
            return; 
        }

        Node *curr;
        Node *nextNode;

        bool swapped = true;

        while (swapped)
        {
            swapped = false;
            curr = head;
            nextNode = NULL;

            while (curr->next != nextNode)
            {
                if (curr->data > curr->next->data)
                {
                    // Swap the data
                    int temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = true;
                }
                curr = curr->next;
            }
            nextNode = curr;
        }
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        
        Node *prev = NULL;
        Node *curr = head;
        Node *NextNode;

        while (curr != NULL)
        {
            NextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NextNode;
        }
        head = prev;    
        
    }

};

int main()
{
    Singli obj;
    obj.add_at_tail(1);
    obj.add_at_tail(4);
    obj.add_at_tail(2);
    obj.add_at_tail(9);
    obj.add_at_tail(0);

    obj.display();

    obj.sort_list();
    obj.display();

    obj.reverse();
    obj.display();

    return 0;
}