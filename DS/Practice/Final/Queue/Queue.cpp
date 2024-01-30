#include <iostream>
using namespace std;

class Queue
{
	int *arr;
	int front, rear, size;
	
	
	public:
	Queue(int s): size(s)
	{
		arr = new int[size];	
		front = rear = -1;
	}
	
	
	void enqueue(int x)
	{
		if(rear == size)
		{
			cout<<"\nQueue is full!";
			return;
		}
		
		if(front == -1)
		{
			front = 0;
			rear = 0;
		}
		
		arr[rear] = x;
		rear++;
		
	}
	
	
	int dequeue(int x)
	{
		if(front == -1)
		{
			cout<<"\nQueue is empty!";
			return 0;
		}	
		
		int deq = arr[front];
		front++;
		
		
		if(front > rear)
		{
			front = rear = -1;
		}
		
		return deq;	
	}
	
	
	int get_front()
	{
		return arr[front];
	}
	
	bool  is_empty()
	{
		return (front == -1);
	}
	
	void display()
	{
		cout<<"\n\nDisplaying list:\n";
		for(int i=0; i<size; i++)
		{
			cout<<arr[i]<<" ";
		}
	}
	
};

int main()
{
	Queue obj(10);
	
	obj.enqueue(2);
	obj.enqueue(12);
	obj.enqueue(23);
	obj.enqueue(234);
	obj.enqueue(2);
	obj.enqueue(5);	
	obj.enqueue(7);
	obj.enqueue(1);
	
	obj.display();
	
}
