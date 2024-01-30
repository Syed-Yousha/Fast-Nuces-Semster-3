#include <iostream>
using namespace std;

int get_max(int arr[], int size)
{
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        
    }

    return max;
}

void count_Sort(int arr[],const int n, int div)
{
    int output[n];
    int i, count[10] = {0};

    for ( i = 0; i < n; i++)
    {
        count[(arr[i]/ div) % 10]++;
    }
    
    for ( i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    
    for ( i = n-1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }
    

    for ( i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int n)
{
    int max = get_max(arr, n);

    for (int div = 1; max/div > 0; div*=10)
    {
        count_Sort(arr, n, div);
    }
}

void reverse(int arr[],const int size)
{
    int temp[size];
    int j = 0;

    for (int i = size-1; i >= 0; i--)
    {
        temp[j] = arr[i];
        j++;
    }
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {36,987,654,2,20,99,456,957,555,420,66,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    display(arr, size);

    radix_sort(arr, size);

    cout << "\n\nSorted array(Ascending): ";
    display(arr, size);

    reverse(arr, size);
    cout << "\n\nSorted array(descending): ";
    display(arr, size);
    

    return 0;
}