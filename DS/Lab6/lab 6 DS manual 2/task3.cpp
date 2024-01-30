#include <bits/stdc++.h>
using namespace std;
const int size = 3;

class runner
{
	public:
	
	string name;
	float sec;
};

void merge(runner *obj, int l, int m, int r)
{
	int i = l;
	int j = m+1;
	int  k = l;
	int temp[size];
	
	while(i<=m && j<=r)
	{
		
		if(obj[i].sec < obj[j].sec)
		{
			temp[k] = obj[i].sec;
			i++;
			k++;
		}
		else
		{
			temp[k] = obj[j].sec;
			j++;
			k++;
		}
		
	}
	
	while(i<=m)
	{
		temp[k]= obj[i].sec;
		i++;
		k++;
	}
	
	while(j<=r)
	{
		temp[k] = obj[j].sec;
		j++;
		k++;
	}
	
	for(int s=l; s<=r; s++)
	{
		obj[s].sec = temp[s];
	}
}

void mergeSort(runner *obj, int l, int r)
{
	if(l<r)
	{
		int mid = l+r/2;
		mergeSort(obj, l , mid);
		mergeSort(obj, mid+1, r);
		merge(obj, l, mid, r);
	}
}



int main()
{
	runner *obj = new runner[size];
	
	string name;
	float sec;
	
	for(int i=0; i<size; i++)
	{
		cout<<"\nEnter the name of participant: ";
		cin>>name;
		
		cout<<"\nEnter finish time in seconds: ";
		cin>>sec;
				
		obj[i].name = name;
		obj[i].sec = sec;
	}
	
	mergeSort(obj, 0, size-1);
	
	
	//Display
	for(int i=0; i<size; i++)
	{
		cout<<endl<<i+1<<". "<<obj[i].name<<" - "<<obj[i].sec<<" seconds";
	}
}
