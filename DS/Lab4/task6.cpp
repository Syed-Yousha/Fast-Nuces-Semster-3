#include <iostream>
using namespace std;

class Node
{
public:
    string str;
    Node *next;

    Node(string s) : str(s), next(NULL) {}
};

class List
{
public:
    Node *head;
    Node *tail;

    List() : head(NULL), tail(NULL) {}

    void insert_tail(string item)
    {
        Node *n = new Node(item);

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
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->str << endl;
            temp = temp->next;
        }
    }
};

void concatenate_list(List &list1, List &list2)
{
    if (list1.head == NULL) 
    {
        list1.head = list2.head;
        list1.tail = list2.tail;
    }
    else if (list2.head != NULL) 
    {
        list1.tail->next = list2.head;
        list1.tail = list2.tail;
    }
}

int main()
{
    List list1;
    list1.insert_tail("a");
    list1.insert_tail("b");
    list1.insert_tail("c");

    List list2;
    list2.insert_tail("x");
    list2.insert_tail("y");
    list2.insert_tail("z");

    cout << "\nList 1: \n";
    list1.display();

    cout << "\nList 2: \n";
    list2.display();

    concatenate_list(list1, list2);

    cout << "\n=========== Concatenated List ===========\n" << endl;
    list1.display();

    return 0;
}
