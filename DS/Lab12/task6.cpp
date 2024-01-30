#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
	int rollNumber;
	string name;
	
	Student(int roll, string& n): rollNumber(roll), name(n){}
	
};

class StudentHashTable
{
	static const int size = 15;
	Student* table[size];

	public:
		StudentHashTable()
		{
			for (int i=0; i<size; i++)
			{
				table[i] = NULL;
			}
		}
		
		
	int hash(int roll, int attempt)	
	{
		return (roll + attempt * attempt) % size;
	}	
	
	
	void insertRecord(int roll, string name)
	{
		int atps = 0;
		
		int index;
		
		
		do
		{
			index = hash(roll, atps);
			
			if(table[index] == NULL)
			{
				table[index] = new Student(roll, name);
				cout<<"\nData is inserted\n";
				return;
			}
			
			atps++;
			
		}while(atps < size);
		
		cout<<"\nHashTable is Full!";
	}
	
	void search(int roll)
	{
		int atps = 0;
		int index;
		
		
		do
		{
			index = hash(roll, atps);
			
			if(table[index]->rollNumber == roll)
			{
				cout<<"\nrecord found\n";
				return;
			}
			
			atps++;
			
		}while(atps < size);
		
		cout<<"\nRecord not found!!";
	}
	
	
};

int main()
{
	StudentHashTable obj;
	
	obj.insertRecord(6007, "Yousha");
	obj.insertRecord(6111, "Thomas");
	obj.insertRecord(6232, "Dazai");
	obj.insertRecord(6999, "kiseke");
	obj.insertRecord(1111, "Levi");


	obj.search(1111);
	obj.search(6007);
	return 0;
}
























