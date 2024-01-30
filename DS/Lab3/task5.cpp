#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void insertionSort(int array[], int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}

	cout << "\n\n========== Insertion Sort ==========\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}


int main()
{
    int myarr[] = {9, 5, 1, 4, 3, 14, 119};
    int size = sizeof(myarr) / sizeof(int);

    insertionSort(myarr, size);
}