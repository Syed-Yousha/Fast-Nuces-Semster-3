#include <iostream>
using namespace std;


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
	
	void insert_head(int data)
	{
		Node *n = new Node(data);
		n->next = head;
		head = n;
		cout<<"\nInserted at head";
	}	
	
	void insert_tail(int data)
	{
		Node *n = new Node(data);
		
		if(head == NULL)
		{
			head = n;
		}
		else
		{
			Node * temp = head;
			
			while( temp->next != NULL )
			{
				temp = temp->next;
			}	
			temp->next = n;
			n->next = tail;
			cout<<"\nInserted at tail";
		}
	}
	
	void display()
	{
		
		Node *temp = head;
		
		cout<<"\n\n======== Displaying entire list ========\n\n";
		while(temp != NULL)
		{
			cout<<" "<<temp->data;
			temp = temp->next;
		}
		
	}
	
	void reverse()
	{
		
		Node *curr = head;
		Node *prev = NULL;
		Node *nex = NULL;
		
		while(curr != NULL)
		{
			nex = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nex;
		}
		
		head = prev;
	}
	
};


int main()
{
	Singli obj;
	
	obj.insert_tail(1);
	obj.insert_tail(2);
	obj.insert_tail(3);
	obj.insert_tail(4);
	obj.display();
	
	obj.reverse();
	obj.display();


	return 0;
}
