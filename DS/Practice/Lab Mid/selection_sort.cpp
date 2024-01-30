#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            swap(arr[min_idx], arr[i]);
        }
    }
}

void display(int arr[], int n)
{

    cout << "\n\nSelection Sort: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 6;
    int arr[6] = {4, 1, 8, 9, 2, 1};
    Selection_sort(arr, n);
    display(arr, n);

    return 0;
}