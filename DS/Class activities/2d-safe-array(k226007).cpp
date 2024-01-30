#include <iostream>
using namespace std;

class Sales
{
	int **arr;
	int products;
	int no_sales;
	
public:
	Sales(int p, int s) : products(p), no_sales(s)
	{
		arr = new int*[products];
		for(int i = 0; i < products; i++)
		{
			arr[i] = new int[no_sales];
		}
		
		for(int i = 0; i < products; i++)
		{
			cout << "\n============ Product # " << i + 1 << "============ \n";
			for(int j = 0; j < no_sales; j++)
			{
				cout << "\n==== Enter sale # " << j + 1 << "==== \n";
				cin >> arr[i][j];
			}	
		}
	}
	
	Sales(const Sales &obj) : products(obj.products), no_sales(obj.no_sales)
	{
		arr = new int*[products];
		for(int i = 0; i < products; i++)
		{
			arr[i] = new int[no_sales];
			for(int j = 0; j < no_sales; j++)
			{
				arr[i][j] = obj.arr[i][j];
			}
		}
	}
	
	Sales& operator=(const Sales &obj)
	{
		if(this != &obj)
		{
			for(int i = 0; i < products; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;
			
			products = obj.products;
			no_sales = obj.no_sales;
			
			arr = new int*[products];
			for(int i = 0; i < products; i++)
			{
				arr[i] = new int[no_sales];
				for(int j = 0; j < no_sales; j++)
				{
					arr[i][j] = obj.arr[i][j];
				}
			}
		}
		
		//k226007
		return *this;
	}
	
	void display()
	{
		cout << "\n\n ========== Sales ==========\n\n";
		for(int i = 0; i < products; i++)
		{
			for(int j = 0; j < no_sales; j++)
			{
				cout << arr[i][j] << "\t";
			}	
			cout << endl;
		}
	}
	
	~Sales()
	{
		for(int i = 0; i < products; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
};

int main()
{
	int prod, size;
	cout << "\nEnter the num of products: ";
	cin >> prod;
	
	cout << "\nEnter the size: ";
	cin >> size;
	
	Sales obj(prod, size);
	obj.display();
	
	return 0;
}
