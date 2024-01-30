#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Shell_sort(int arr[], int n)
{

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j-=gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
        
    }
}

void display(int arr[], int n)
{

    cout << "\n\nShell Sort: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 6;
    int arr[6] = {4, 1, 8, 9, 2, 1};
    Shell_sort(arr, n);
    display(arr, n);

    return 0;
}