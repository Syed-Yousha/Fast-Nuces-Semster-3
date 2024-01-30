#include <iostream>
#define MAX_SIZE 100
using namespace std;

class MaxHeap 
{
private:
    int heap[MAX_SIZE];
    int size;

    void heapifyDown(int index) 
	{
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) 
		{
            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild] > heap[largest]) 
		{
            largest = rightChild;
        }

        if (largest != index) 
		{
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() : size(0) {}

    void insert(int priority) 
	{
        if (size < MAX_SIZE) 
		{
            heap[size++] = priority;

            int currentIndex = size - 1;
            int parentIndex = (currentIndex - 1) / 2;

            while (currentIndex > 0 && heap[currentIndex] > heap[parentIndex])
			{
                swap(heap[currentIndex], heap[parentIndex]);
                currentIndex = parentIndex;
                parentIndex = (currentIndex - 1) / 2;
            }
        } else 
		{
            cout << "Heap is full." << endl;
        }
    }

    void removeRoot() 
	{
        if (size > 0) 
		{
            heap[0] = heap[size - 1];
            size--;

            heapifyDown(0);
        } else {
            cout << "Heap is empt." << endl;
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
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(3);
    maxHeap.insert(7);

    cout << "Initial Max-Heap: ";
    maxHeap.displayHeap();

    maxHeap.removeRoot();

    cout << "after removing the root: ";
    maxHeap.displayHeap();

    return 0;
}
















