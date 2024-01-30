#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    int curr, i, j;
    for (i = 1; i < size; i++)
    {
        
        curr = arr[i];
        j = i-1;

        while (arr[j]>curr && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;    

    }
    
}

void display(int arr[], int size)
{
    cout <<"\nInsertion Sort:"<< endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<< " ";
    }
}

int main()
{

    int arr[5] = {4, 2, 5, 1, 7};
    int size = sizeof(arr)/sizeof(int);
    
    insertion_sort(arr, size);
    display(arr, size);

    return 0;
}