#include <iostream>
using namespace std;

void shellsort(int arr[], int n)
{
	for(int gap = n/2; gap>0; gap /=2 )
	{
		for(int i=gap; i<n; i++)
		{
			int temp = arr[i];
			int j = 0;
			
			for(j = i; j>=gap && (arr[j-gap]) > temp; j-=gap)
			{
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}

void display_array(int arr[], int n)
{
	
	cout<<"\n\n========== Displaying array ==========\n\n";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" liters\n";
	}
}

int main()
{
	int bottles[] = {43,2,6,1,3,8,12};
	int size = (sizeof(bottles)/sizeof(int)) -1 ;
	
	shellsort(bottles, size);
	display_array(bottles, size);
}
