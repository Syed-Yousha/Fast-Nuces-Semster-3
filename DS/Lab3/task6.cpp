#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void shellsort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j = 0;

			for (j = i; j >= gap && (arr[j - gap]) > temp; j -= gap)
			{
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
}


int main()
{
    int size;
    cout<<"\nEnter the size of array: ";
    cin>>size;

    int *arr = new int[size];
    
    cout<<"\nEnter the values of array,";
    for (int i = 0; i < size; i++)
    {
        cout<<"\nValue #"<<i+1<<" : ";
        cin>>arr[i];
    }

    shellsort(arr, size);
    
}