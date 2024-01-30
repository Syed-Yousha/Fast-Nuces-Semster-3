#include <iostream>
using namespace std;

class StudentFeeManager
{
	int *arr, size;
	public:
	
	StudentFeeManager(int s):size(s)
	{}
	
	void sett_array()
	{
		arr = new int[size];
		
		for(int i=0; i<3; i++)
		{
			arr[i] = 1000;
		}
	}
	
	
	void modify_array(int s)
	{
		arr = new int[s];
		for(int i=0; i<3; i++)
		{
			arr[i] = 1111;
		}
	}
	
	StudentFeeManager(StudentFeeManager &obj)
	{
		arr = new int[size];
		memcpy(arr, obj.arr, 3*sizeof(int));		
	}
	
	StudentFeeManager& operator = (const StudentFeeManager &obj)
	{
		arr = new int[size];
		if( obj.arr != arr)
		{
			memcpy(arr, obj.arr, 3*sizeof(int));
		}
		
		return *this;	
	}
	
	
	int &operator [](int i)
	{
		if(i<0 || i>2)
		{
			cout<<"\nError! array out of bound!";
			exit(1);
		}
	}
	
	void display()
	{
		
		cout<<"\n\n ========= Array Values =========\n";
		for(int i=0; i<3; i++)
		{
			cout << arr[i]<<endl;
		}
	}
	
	~StudentFeeManager()
	{
		delete[] arr;
	}
	
};

int main()
{

	StudentFeeManager obj(3);
	
	obj.sett_array();
	obj.display();
	
	StudentFeeManager obj2(obj);
	
	obj2.display();
	
	
	cout<<"\n\n ======== Modeifying ========";
	obj2.modify_array(3);
	obj.display();
	obj2.display();
}
