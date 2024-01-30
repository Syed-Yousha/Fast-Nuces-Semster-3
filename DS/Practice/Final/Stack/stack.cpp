#include <iostream>
using namespace std;
template <typename T>


class stack
{
	
	struct Node
	{	
		public:
		T data;
		Node *next;
		Node(const T& d): data(d), next(NULL){}
	};

	Node *top;
	
	public:
	stack():top(NULL){}
	
	
	void push(const T& val)
	{
		Node *newNode = new Node(val);
		newNode->next = top;
		top = newNode;
	}
	
	bool isEmpty()
	{
		return (top == NULL);
	}
	
	void pop()
	{
		if(isEmpty())
		{
			cout<<"\nStack is empty!";
			return ;
		}		
		
		top = top->next;
	}
	
	
	T& peek()
	{
		return top->data;
	}
	
	void display()
	{
		cout<<"\n\nDisplaying stack:\n\n   ";
		cout<<peek();
		pop();
		while(!isEmpty())
		{
			cout<<"->"<<peek();
			pop();
		}
	}
	
	~stack()
	{
		while(!isEmpty())
		{
			pop();
		}
	}
};
int main()
{
	stack<int> obj;
	
	obj.pop();
	obj.push(2);
	obj.push(4);
	obj.push(2);
	obj.push(6);
	obj.push(8);
	
	obj.display();
}
