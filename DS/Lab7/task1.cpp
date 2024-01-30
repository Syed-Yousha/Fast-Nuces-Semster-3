#include <iostream>
#include <time.h>
#include <cstdlib> 
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, int &count)
{
    static bool flag = true;
    int pivot = arr[high];


    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            count++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int &count)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, count);

        quickSort(arr, low, pivotIndex - 1, count);
        quickSort(arr, pivotIndex + 1, high, count);
    }
}

int main()
{
    srand(time(NULL));

    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Pivot as first element k226007
    int count = 0;

    quickSort(arr, 0, size-1, count);

    cout << "\n\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nPivot first element count: " << count;

    // Pivot as Random element k226007
    count = 0;
    int random = rand() % size;

    quickSort(arr, 0, random, count);
    cout << "\n\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nPivot Random element count: " << count;
    cout << "\nRandom value: " << random;
    // Pivot as middle element k226007
    count = 0;

    quickSort(arr, 0, (size - 1) / 2, count);

    cout << "\n\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nPivot middle element count: " << count;

    // Pivot by median approach
    count = 0;

    quickSort(arr, 0, size / 2, count);

    cout << "\n\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nPivot by median approach count: " << count;

    return 0;
}
