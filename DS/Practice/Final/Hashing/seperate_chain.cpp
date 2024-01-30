#include <bits/stdc++.h>
using namespace std;

class Hash
{
	int bucket;
	list<int> *table;
	
	public:
	Hash(int b)
	{
		this->bucket = b;
		table = new list<int>[bucket];
	}
	
	int hashfunction(int key)
	{
		return key % bucket;
	}
	
	void insert_item(int key)
	{
		int index = hashfunction(key);
		table[index].push_back(key);
	}
	
	
	void delete_item(int key)
	{
		int index = hashfunction(key);
		
		
		list<int>::iterator i;
		
		for(i = table[index].begin(); i != table[index].end(); i++)
		{
			if(*i == key)
			{
				break;
			}
		}
		
		if(i != table[index].end())
		{
			table[index].erase(i);
		}
	}
	
	
	void display()
	{
		cout<<"\n\nDisplaying items:\n";
		for(int i = 0; i<bucket; i++)
		{
			cout<<endl<<i;
			for(list<int>::iterator x = table[i].begin(); x != table[i].end(); x++)
			{
				cout<<"->"<<*x;
			}
		}
	}
		
};

int main()
{
	Hash obj(5);
	
	obj.insert_item(2);
	obj.insert_item(21);
	obj.insert_item(15);
	obj.insert_item(3);
	obj.insert_item(6);
	
	
	obj.display();
}
