#include<iostream>
using namespace std;
#define max 5

class stack
{
	int top;

	public:
	
	string a[max];
	
	stack() 
	{
		top = -1;	
	}	
	
	bool push(string x)
	{
		if(top >= (max - 1))
		{
			cout<< "\nStack overflow";	
		}
		else
		{
			a[++top] = x;
			cout<<endl;
			cout << x <<" pushed into stack\n";
			return true;	
		}
	}
	
	string pop()
	{
		if(top < 0)
		{
			cout<<"\nStack underflow";
			return 0;
		}
		else
		{
			string x = a[top];
			top--;
			cout<<endl;
			cout<<x<<" is completed";
			return x;	
		}
	}
	
	void peek()
	{
		if(top < 0)
		{
			cout<<"\nStack is empty";
			return;
		}
		else
		{
			string x = a[top];
			cout<<x;
		}
	}
	
	bool isEmpty()
	{
		return (top < 0);
	}
	
	bool isFull()
	{
		return (top == max);
	}
};

int main()
{
	
	stack obj;
	if(obj.isEmpty())
		cout<<"\nStack is empty\n";
		
	obj.push("task 1");
	obj.push("task 2");
	obj.push("task 3");
	obj.push("task 4");
	obj.push("task 5");
	
	obj.pop();

	return 0;
}


