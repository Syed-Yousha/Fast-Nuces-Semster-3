#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void bubbleSort(int array[], int size)
{
	int count = 0;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			count++;
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	cout << "\n\n========== Bubble Sort ==========\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\nCount is: " << count;
}

int main()
{
    int arr[] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
    int size = sizeof(arr)/ sizeof(int);
    
    bubbleSort(arr, size);
}
