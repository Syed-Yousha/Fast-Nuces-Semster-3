#include <iostream>
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
	
	int hashfunction(int key)
	{
		return key % bucket;
	}
	
	int quadratic_prob(int key, int attps)
	{
		return ((key + attps) *attps) % bucket;
	}
	
	void insert_item(int key)
	{
		int index = hashfunction(key);
		int attempts = 0;
		
		while(table[index] != -1)
		{
			index = quadratic_prob(key, attempts);
			attempts++;
		}
		
		table[index] = key;
	}
	
	void search(int key)
	{
		int index = hashfunction(key);
		int attempts = 0;
		
		for(int i=0; i<bucket; i++)
		{
			if(table[index] == key)
			{
				cout<<"\nItem found!";
				return;
			}
			
			index = quadratic_prob(key, attempts);
			attempts++;
		}
		
		cout<<"\nNot found";
	}
	
	void delete_item(int key)
	{
		int index = hashfunction(key);
		int attempts = 0;
		
		for(int i=0; i<bucket; i++)
		{
			if(table[index] == key)
			{
				table[index] = -1;
				cout<<"\nItem deleted!";
				return;
			}
			
			index = quadratic_prob(key, attempts);
			attempts++;
		}
		
		cout<<"\nNot found";
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
	
	obj.insert_item(2);
	obj.insert_item(22);
	obj.insert_item(13);
	obj.insert_item(187);
	obj.insert_item(9);
	obj.insert_item(77);
	obj.insert_item(10);
	
	
	obj.display();
}
