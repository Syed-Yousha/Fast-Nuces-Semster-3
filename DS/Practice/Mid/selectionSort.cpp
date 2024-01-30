#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{

    int min_index;
    for (int i = 0; i < size - 1; i++)
    {

        min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
        }
    }
}
void display(int arr[], int size)
{
    cout << "\nSelection Sort:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[5] = {4, 2, 5, 1, 7};
    int size = sizeof(arr) / sizeof(int);

    selectionSort(arr, size);
    display(arr, size);

    return 0;
}