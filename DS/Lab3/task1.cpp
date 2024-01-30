#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n);
void display_array(int arr[], int n);

int main()
{
	
	int crates[] = {43,2,6,1,3,8,12};
	int size = (sizeof(crates)/sizeof(int)) -1 ;
	
	
	SelectionSort(crates, size);
	display_array(crates, size);	

		
}


void SelectionSort(int arr[], int n)
{
	for(int i=0; i< n-1; i++)
	{
		int min_index = i;
		
		
		for(int j=i+1; j<n; j++)
		{
			if(arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		
	}
}

void display_array(int arr[], int n)
{
	
	cout<<"\n\n========== Displaying array ==========\n\n";
	for(int i=0; i<n; i++)
	{
		cout<<"\ncrates Shipped out after "<<arr[i]<<" hours";
	}
}

