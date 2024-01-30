#include <iostream>
using namespace std;

class Node
{
public:
    string task;
    Node *next;

    Node(string t) : task(t), next(NULL) {}
};

class To_do_list
{

public:
    Node *head;
    Node *tail;

    To_do_list() : head(NULL), tail(NULL) {}

    void insert_tail(string task)
    {
        Node *n = new Node(task);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        // cout << "\nInserted at tail";
    }

    void del_front()
    {
        Node *d = head;
        head = head->next;
        d->next = NULL;
        delete d;
    }

    void delete_end()
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete from an empty list.";
            return;
        }

        Node *temp = head;
        Node *pre = NULL;

        while (temp->next != NULL)
        {
            pre = temp;
            temp = temp->next;
        }

        if (temp == head)
        {
            delete temp;
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = pre;
            tail->next = NULL;
            delete temp;
        }
    }

    void delete_after(int key)
    {
        if (head == NULL || key < 0)
        {
            cout << "Invalid position or list is empty. Cannot delete.";
            return;
        }

        Node *curr = head;
        Node *pre = NULL;

        for (int i = 1; i <= key && curr != NULL; i++)
        {
            if (i == key)
            {
                if (pre == NULL)
                {
                    head = curr->next;
                    delete curr;
                    return;
                }
                else
                {
                    pre->next = curr->next;
                    delete curr;
                    return;
                }
            }

            pre = curr;
            curr = curr->next;
        }

        cout << "Position " << key << " not found in the list. Cannot delete.";
    }

    void display()
    {

        Node *temp;
        temp = head;

        cout << "\n\n======== To do list ========\n\n";
        while (temp != NULL)
        {
            cout << endl
                 << temp->task;
            temp = temp->next;
        }
    }
};

int main()
{

    To_do_list obj;

    // insertion
    obj.insert_tail("Buy grocerires");
    obj.insert_tail("Finish a report");
    obj.insert_tail("Go for run");
    obj.display();

    // Deletion
    obj.del_front();
    obj.display();

    obj.insert_tail("call a friend");
    obj.display();

    obj.delete_end();
    obj.display();

    obj.delete_after(1);
    obj.display();

    return 0;
}
