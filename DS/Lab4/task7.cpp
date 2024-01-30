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

class Circular
{
	public:
	Node *head;
	Node *tail;
	
	Circular()
	{
		head = NULL;
		tail = NULL;
	}
	
	
	void insert_end(int val)
	{
		Node *n = new Node(val);
		if(head == NULL)
		{
			head = n;
			tail = n;
			tail->next=head;
		}
		
		tail->next=n;
		tail=tail->next;
		tail->next=head;
	}	
	
	void display()
	{
		
		cout<<"\n Circular LL\n\n";
		Node *tmp;
		tmp = tail->next;
		cout<<tmp->data<<" ";
		tmp = tmp->next;
		
		while(tmp != tail->next)
		{
			cout<< tmp->data<<" ";
			tmp = tmp->next;
		}
	}
};


int main()
{
	Circular obj;
	
	obj.insert_end(1);
	obj.insert_end(2);
	obj.insert_end(3);
	obj.insert_end(4);
	obj.insert_end(5);
	
	obj.display();

	return 0;	
}

