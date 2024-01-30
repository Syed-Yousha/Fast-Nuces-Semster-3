#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Singly
{
    public: 
    Node *head;
    Node *tail;

    Singly():head(NULL), tail(NULL){}

    void insert_at_tail(int val)
    {
        Node *n = new Node(val);

        if (head == NULL)
        {
            head = n;
            tail = n;
            return;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
            cout<<"\ninserted";
        }
        // Node *temp = head;
        
        // while(temp->next != NULL)
        // {
        // 	temp = temp->next;
		// }
        // temp->next = n;
        // tail = n;
        // cout<<"\ninserted";
    }

    void insert_front(int val)
    {
        Node *tmp = new Node(val);
        tmp->next = head;
        head = tmp;
    }

    void insert_any_pos(int pos, int val)
    {
        Node *tmp = new Node(val);
        Node *pre;
        Node *curr;

        curr = head;
        
        for (int i = 0; i < pos; i++)
        {
            pre = curr;
            curr = curr->next;
        }
        
        pre->next = tmp;
        tmp->next = curr;
    }

    bool Search(int key)
    {
        Node *tmp = head;

        while (tmp->next != NULL)
        {
            if (tmp->data == key)
            {
                cout<<"\nFound";
                return 1;
            }
            
        }

        cout<<"\nNot Found!";
        return 0;
    }

    void display()
    {
        Node *tmp = head;

        cout<<"\n\nDisplay:\n";
        while(tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
    }
};

int main()
{   
    Singly obj;

    obj.insert_at_tail(2);
    obj.insert_at_tail(3);
    obj.insert_at_tail(4);
    obj.insert_at_tail(5);
    obj.insert_at_tail(6);

    obj.display();    
    return 0;
}
