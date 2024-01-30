#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int size)
{
	int i, j, temp;
	int swapped;
	for(i=0; i<size-1; i++)
	{
		swapped = false;
		for(j=0; j < size-i-1; j++)
		{
			if(arr[j]> arr[j+1])
			{
				swap(arr[j], arr[j + 1]);
                swapped = true;
			}
		}
		
		 if (swapped == false)
            break;
	}
	
}

int BinarySearch(int arr[], int low, int high, int x)
{
	int mid;
	while(low <= high)
	{
		mid = (low + (high - low))/2;
		
		if(arr[mid] == x)
		{
			return mid;	
		}
		
		if(arr[mid] < x)
			low = mid + 1;
			
		else
			high = mid - 1;
	}	
	
	return -1;
}

int main()
{
	int index = 0;
	int arr[] = {2,2,43,5,1,6};
	bubbleSort(arr, sizeof(arr)/sizeof(int));
	
	index = BinarySearch(arr,0, sizeof(arr)/sizeof(int), 5);
	
	if(index == -1)
		cout<<"\n value not found!";
		
	else
		cout<<"\n value found! at index: "<<index;
}
