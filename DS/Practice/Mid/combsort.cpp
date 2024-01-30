#include <iostream>
using namespace std;

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1)
    {
        return 1;
    }
    return gap;
}

void comb_sort(int arr[], int size)
{
    int gap = size;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < size - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void display(int arr[], int size)
{
    cout << "\nComb Sort:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[5] = {4, 2, 5, 1, 7};
    int size = sizeof(arr) / sizeof(int);

    comb_sort(arr, size);
    display(arr, size);

    return 0;
}