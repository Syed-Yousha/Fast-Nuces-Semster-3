#include <iostream>
using namespace std;


int linear_search(int *arr,int size,int x)
{
//	arr = new int[size];
	
	for(int i=0; i<size; i++)
	{
		if(arr[i] == x)
			return i;
	}
	
	return -1;
}

int main()
{
	int index = 0;
	int arr[] = {2,43,5,1,6};
	index = linear_search(arr, (sizeof(arr)/sizeof(int)), 5);
	
	if(index == -1)
		cout<<"\n value not found!";
		
	else
		cout<<"\n value found! at index: "<<index;
}
