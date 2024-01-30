#include <iostream>
using namespace std;

class MaxHeap {
public:
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int size;

    void heapifyDown(int index) {
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

    void insert(int value) 
	{
        if (size < MAX_SIZE) 
		{
            heap[size++] = value;

            int currentIndex = size - 1;
            int parentIndex = (currentIndex - 1) / 2;

            while (currentIndex > 0 && heap[currentIndex] > heap[parentIndex]) 
			{
                swap(heap[currentIndex], heap[parentIndex]);
                currentIndex = parentIndex;
                parentIndex = (currentIndex - 1) / 2;
            }
        } else {
            cout << "Heap is full." << endl;
        }
    }

    void removeValue(int value) 
	{
        for (int i = 0; i < size; ++i) 
		{
            if (heap[i] == value) 
			{
                heap[i] = heap[size - 1];
                size--;
                heapifyDown(i);
                break;
            }
        }
    }

    void displayHeap() {
        cout << "Max Heap: ";
        for (int i = 0; i < size; ++i) 
		{
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

class MinHeap 
{
private:
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int size;

    void heapifyDown(int index) 
	{
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) 
		{
            smallest = leftChild;
        }

        if (rightChild < size && heap[rightChild] < heap[smallest]) 
		{
            smallest = rightChild;
        }

        if (smallest != index) 
		{
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() : size(0) {}

    void insert(int value) 
	{
        if (size < MAX_SIZE) 
		{
            heap[size++] = value;

            int currentIndex = size - 1;
            int parentIndex = (currentIndex - 1) / 2;

            while (currentIndex > 0 && heap[currentIndex] < heap[parentIndex]) 
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

    void removeValue(int value) 
	{
        for (int i = 0; i < size; ++i) 
		{
            if (heap[i] == value) 
			{
                heap[i] = heap[size - 1];
                size--;
                heapifyDown(i);
                break;
            }
        }
    }

    void displayHeap() {
        cout << "Min Heap: ";
        for (int i = 0; i < size; ++i) 
		{
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    MaxHeap maxHeap;

    maxHeap.insert(25);
    maxHeap.insert(30);
    maxHeap.insert(35);
    maxHeap.insert(11);
    maxHeap.insert(15);
    maxHeap.insert(19);
    maxHeap.insert(18);
    maxHeap.insert(55);
    maxHeap.insert(78);
    maxHeap.insert(36);

    cout << "before: ";
    maxHeap.displayHeap();

    maxHeap.removeValue(55);

    cout << "after removing 55: ";
    maxHeap.displayHeap();

    MinHeap minHeap;

    minHeap.insert(25);
    minHeap.insert(30);
    minHeap.insert(35);
    minHeap.insert(11);
    minHeap.insert(15);
    minHeap.insert(19);
    minHeap.insert(18);
    minHeap.insert(55);
    minHeap.insert(78);
    minHeap.insert(36);

    cout << "Min Heap before removing 18: ";
    minHeap.displayHeap();

    minHeap.removeValue(18);

    cout << "Min Heap after removing 18: ";
    minHeap.displayHeap();

   
	for (int i = maxHeap.size - 1; i > 0; --i) {
	    swap(maxHeap.heap[0], maxHeap.heap[i]);
	    maxHeap.heapifyDown(0);
	}


    cout << "Sorted: ";
    maxHeap.displayHeap();

    return 0;
}

