#include <iostream>
using namespace std;

int get_max(int arr[],const int size)
{
	int max = arr[0];
	
	for(int i=0; i<size; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	
	return max;
}


void count_sort(int arr[], const int size, int div)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
    {
    	count[(arr[i] / div) % 10]++; 
    }
    
    for(int i = 1; i < 10; i++)
    {
    	count[i] += count[i - 1];
	}
	
	for(int i = size - 1; i>=0; i--)
	{
		output[count[(arr[i]/div) % 10] - 1] = arr[i];
		count[(arr[i]/div )%10]--;
	}
	
	for(int i=0; i<size; i++)
	{
		arr[i] = output[i];
	}
    
}

void RadixSort(int arr[], const int size)
{
	int m = get_max(arr, size);
	
	for(int div = 1; m/div > 0; div *=10)
		count_sort(arr, size, div);
}

void display(int arr[], const int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void reverse(int arr[],const int size)
{
	int tmp[size];
	int j = 0;
	for(int i=size-1; i>=0; i--)
	{
		tmp[j] = arr[i];
		j++;
	}
	
	for(int i=0; i<size; i++)
	{
		arr[i] = tmp[i];
	}
}

int main()
{
	int arr[] = {23,34,42,15,57,36};
	int size = sizeof(arr)/ sizeof(arr[0]);
	
	RadixSort(arr, size);
	cout<<"\nAssending Order:\n";
	display(arr, size);
	
	cout<<"\nDecending Order:\n";
	reverse(arr, size);
	display(arr, size);
	return 0;
}
