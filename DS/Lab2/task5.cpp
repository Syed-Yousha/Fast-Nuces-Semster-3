#include <iostream>
using namespace std;

int main()
{
	int rows = 5, cols_size[5];
	string id[5];
	
	int* arr[rows];
	
	for(int i=0; i<rows; i++)
	{
		cout<<"\nEnter your roll num: ";
		cin>>id[i];
		
		cout<<"\n Enter the number of courses: ";
		cin>>cols_size[i];
		
		
		arr[i] = new int[cols_size[i]];
		    
//		cout<<"\n\nEnter marks for "<<cols_size[i]<<" courses: ";
		
		for(int j=0; j< cols_size[i]; j++)
		{
			cout<<"\n\n marks for course #"<<j+1<<" :" ;
			cin>>arr[i][j];	
		}	
	}
	
	
	cout<<"\n\n======== Students data ========";
	for(int i=0; i<rows; i++)
	{
		
		cout<<"\n\n========= Student #"<<i+1<<" :" ;
		cout<<"\nRoll num: "<<id[i];
		cout<<"\nMarks:";
		for(int j=0; j<cols_size[i]; j++)
		{
			cout<<arr[i][j]<<", ";
			
		}
	}
	
}
