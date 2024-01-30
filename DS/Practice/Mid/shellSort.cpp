#include <iostream>
using namespace std;

void shell_sort(int arr[], int size)
{

    for (int gap = size / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];

            int j = i;
            while(j>=gap && arr[j-gap] > temp)
            {
                arr[j] = arr[j - gap];
                j-=gap;
            }

            arr[j] = temp;
        }
    }

    return;
}

void display(int arr[], int size)
{
    cout <<"\nShell Sort:"<< endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<< " ";
    }
}

int main()
{

    int arr[5] = {4, 2, 5, 1, 7};
    int size = sizeof(arr)/sizeof(int);
    
    shell_sort(arr, size);
    display(arr, size);

    return 0;
}