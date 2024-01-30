
#include <iostream>
using namespace std;

class Node
{
	public:
	int marks;
	string name;
	Node *next;
	
	Node(int val, string name)
	{	
		marks = val;
		this->name = name;
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
	
	
	void insert_head(int marks, string name)
	{
		Node *n = new Node(marks, name);
		n->next = head;
		head = n;
		cout<<"\nInserted at head";
	}	
	
	void insert_tail(int marks, string name)
	{
		Node *n = new Node(marks, name);
		
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
	
	void insert_after(string name_pos, int marks, string name)
	{
		Node *n = new Node(marks, name);
		Node *temp = head;
		Node *curr = head;
		Node *pre;
		
		
		while(temp != NULL)
		{
			pre = curr;
			curr = curr->next;	
				
			if(temp->name == name_pos)
			{
				break;
			}		
			
			temp = temp->next;	
		}
		
		pre->next = n;
		n->next = curr;
	}
	
	bool search_marks(string key)
	{
		Node *temp = head;
		
		while( temp != NULL )
		{
			if( temp->name == key )
			{
				
				cout<<"\nMarks are: "<<temp->marks;
				return true;			
			}
			temp = temp->next;
		}
		
		cout<<"\n Name not found!";
		return false;		
	}
	
	void display()
	{
		
		Node *temp = head;
		
		cout<<"\n\n======== Displaying entire lise ========\n\n";
		while(temp != NULL)
		{
			cout<<"\n name of student: "<<temp->name;
			cout<<"\n Marks of student: "<<temp->marks;
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
	obj.insert_head(88, "Eve");
	obj.insert_tail(89, "Frank");
	
	obj.insert_tail(90, "Alice");
	obj.insert_tail(95, "Bob");
	obj.insert_tail(78, "Carol");
	obj.insert_tail(95, "David");
	
	
	obj.insert_after("Bob", 92, "Grace");
		
	obj.search_marks("Carol");
	obj.display();
	
	obj.reverse();
	obj.display();

	return 0;
}
