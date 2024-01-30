#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{

    bool swapped;
    
    for (int i = 0; i < size; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
        
    }
}

void display(int arr[], int size)
{
    cout <<"\nBubble Sort:"<< endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<< " ";
    }
}

int main()
{

    int arr[5] = {4, 2, 5, 1, 7};
    int size = sizeof(arr)/sizeof(int);
    
    bubble_sort(arr, size);
    display(arr, size);

    return 0;
}