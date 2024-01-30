#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    int i, key, j;

    for (int i = 1; i < n ; i++)
    {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void display(int arr[], int n)
{

    cout<<"\n\nInsertion Sort: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int n = 6;
    int arr[6] = {4,1,8,9,2,1};
    insertion_sort(arr, n);
    display(arr, n); 

return 0;
}