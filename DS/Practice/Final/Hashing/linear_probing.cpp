#include <bits/stdc++.h>
using namespace std;

class Hash
{
	int bucket;
	int *table;
	
	public:
	Hash(int b): bucket(b)
	{
		table = new int[bucket];
		for(int i=0; i<bucket; i++)
		{
			table[i] = -1;
		}	
	}
	
	int hashfunction(int x)
	{
		return x % bucket;
	}
	
	void insert_item(int key)
	{
		int index = hashfunction(key);
		
		while(table[index] != -1)
		{
			index = (index + 1) % bucket;
		}
		
		table[index] = key;
	}
	
	void search(int key)
	{
		int index = hashfunction(key);
		
		
		for(int i=0; i<bucket; i++)
		{
			
			if(table[index] == key)
			{
				cout<<"\nItem found!";
				return;		
			}
			
			index = (index + 1)%bucket;
		}
		
		cout<<"\nnot found!";
	}
	
	void delete_item(int key)
	{
		int index = hashfunction(key);
		
		for(int i=0; i<bucket; i++)
		{
			
			if(table[index] ==  key)
			{
				table[index] = -1;
				cout<<"\nItem has been deleted!";
				return;
			}
			
			index = (index + 1)%bucket;
		}
		
		
		cout<<"\nnot found!";
	}
	
	void display()
	{
		cout<<"\n\nDisplaying All items: \n";
		
		for(int i=0; i<bucket; i++)
		{
			cout<<i<<": ";
			cout<<table[i]<<endl;
		}
	}
};


int main()
{
	Hash obj(10);
	
	obj.insert_item(3);
	obj.insert_item(13);
	obj.insert_item(14);
	obj.insert_item(123);
	obj.insert_item(5);
	obj.insert_item(8);
	obj.insert_item(92);
	
	obj.display();
	
	
	obj.search(123);
	obj.search(111);
	
	obj.delete_item(92);
	obj.display();
}
