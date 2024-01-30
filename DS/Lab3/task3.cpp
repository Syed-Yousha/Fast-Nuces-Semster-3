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

void insertionSort(int array[], int size)
{
	int i, key, j, count = 0;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			count++;
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}

	cout << "\n\n========== Insertion Sort ==========\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\nCount is: " << count;
}

void SelectionSort(int arr[], int n)
{
	int count = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;

		for (int j = i + 1; j < n; j++)
		{
			count++;
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}

	cout << "\n\n========== Selection Sort ==========\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\nCount is: " << count;
}

void shellsort(int arr[], int n)
{
	int count = 0;
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j = 0;

			for (j = i; j >= gap && (arr[j - gap]) > temp; j -= gap)
			{
				count++;
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}

	cout << "\n\n========== Shell Sort ==========\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\nCount is: " << count;
}

int main()
{

	int size = 20;

	int arr[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000;
	}

	int temp[size];

	memcpy(temp, arr, size * sizeof(int));
	bubbleSort(temp, size);

	memcpy(temp, arr, size * sizeof(int));
	insertionSort(temp, size);

	memcpy(temp, arr, size * sizeof(int));
	SelectionSort(temp, size);

	memcpy(temp, arr, size * sizeof(int));
	shellsort(temp, size);

	return 0;
}
