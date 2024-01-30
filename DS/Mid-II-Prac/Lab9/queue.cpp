#include <iostream>
using namespace std;

class Queue
{
    int capacity;
    int front;
    int rear;
    int *arr;


    public:

    Queue(int size)
    {
        capacity = size;
        front = rear = -1;
        arr = new int[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout<<"\nQueue is Full!";
            return;
        }
        
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear +1) % capacity;
        }
        
        
        arr[rear] = data;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout<< "\nQueue is empty";
            return 0;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return arr[front];
    }

    int peek()
    {
        if (isEmpty())
        {
            return arr[front];
        }
        
    }    
};

int main()
{

     Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    cout << "Front element: " << myQueue.peek() << endl;

	for(int i=1; i<5; i++)
	{
		cout<<endl<<myQueue.dequeue();
	}
    return 0;
}
