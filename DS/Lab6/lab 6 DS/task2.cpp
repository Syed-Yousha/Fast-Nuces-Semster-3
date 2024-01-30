#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int interpolationSearch(int arr[], int n, int key)
{
	int low = 0;
	int high = n - 1;

	while (low <= high && key >= arr[low] && key <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == key)
			{
				return low;
			}
			return -1;
		}

		int pos = low + ((double)(key - arr[low]) / (arr[high] - arr[low])) * (high - low);
		if (arr[pos] == key)
		{
			return pos;
		}

		if (arr[pos] < key)
		{
			low = pos + 1;
		}
		else
		{
			high = pos - 1;
		}
	}

	return -1;
}

int main()
{
	int arr[] = {1, 3, 2, 4, 5, 6, 7};
	bubbleSort(arr, sizeof(arr) / sizeof(int));
	int size = sizeof(arr) / sizeof(arr[0]);
	// cout<<size;
	int key = 6;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	int result = interpolationSearch(arr, size, key);

	if (result == -1)
	{
		cout << "\n\nNot found!";
	}
	else
	{
		cout << "\nFound at index: " << result;
	}
}
