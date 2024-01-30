#include <iostream>
using namespace std;


class Sales
{
	int **arr;
	int products;
	int no_sales;
	
	public:
	
	Sales(int p, int s): products(p), no_sales(s)
	{
		//setting array
		arr = new int*[products];
		
		for(int i=0; i<products; i++)
		{
			arr[i] = new int[no_sales];
		}
		
		
		//input
		for(int i=0; i<products; i++)
		{
			cout<<"\n============ Product # "<<i+1<<"============ \n";
			for(int j=0; j<no_sales; j++)
			{
				cout<<"\n==== Enter sale # "<<j+1<<"==== \n";
				cin>>arr[i][j];
			}	
		}
		
	}
	
	
	void display()
	{		
		cout<<"\n\n ========== Sales ==========\n\n";
		
		for(int i=0; i<products; i++)
		{
			for(int j=0; j<no_sales; j++)
			{
				cout<<arr[i][j]<<"\t";
			}	
			cout<<endl;
		}	
	}
	
};


int main()
{
	int prod, size;
	
	cout<<"\nEnter the num of products: ";
	cin>>prod;
	
	cout<<"\nEnter the size: ";
	cin>>size;
	
	Sales obj(prod, size);
	
	obj.display();
}
