#include <iostream>
#define MAX_SIZE 100
using namespace std;

class MinHeap 
{
private:
    int heap[MAX_SIZE];
    int size;

    void heapifyUp(int index) 
	{
        while (index > 0) 
		{
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) 
			{
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else 
			{
                break;
            }
        }
    }

public:
    MinHeap() : size(0) {}

    void insert(int priority) 
	{
        if (size < MAX_SIZE) 
		{
            heap[size++] = priority;
            heapifyUp(size - 1);
        } else 
		{
            cout << "Heap is full. Cannot insert more elements." << endl;
        }
    }

    void displayHeap() 
	{
        cout << "Heap: ";
        for (int i = 0; i < size; ++i) 
		{
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;

    heap.insert(5);
    heap.displayHeap();
	
	heap.insert(2);
    heap.displayHeap();
	

    return 0;
}



















