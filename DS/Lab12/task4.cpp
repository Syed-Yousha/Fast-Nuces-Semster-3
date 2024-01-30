#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int Bucket;

    list<int> *table;

public:
    Hash(int B)
    {
        Bucket = B;
        table = new list<int>[Bucket];
    }

    int hashFunction(int x)
    {
        return (x % Bucket);
    }


    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }    

    void deleteItem(int key)
    {
        int index = hashFunction(key);

        list <int> :: iterator i;
        for (i = table[index].begin() ;i != table[index].end(); i++)
        {
            if (*i == key)
            {
                break;
            }
            
        }
        
        if (i != table[index].end())
        {
            table[index].erase(i);
        }
        
    }

	void search(int key)
	{
		list<int>::iterator j;
		
		for(int i = 0; i < Bucket; i++)
		{
			for(j = table[i].begin(); j != table[i].end(); j++)
			{
				if(*j == key)
				{
					cout<<endl<<" value found: "<<*j;
					return; 
				}
			}
		}
		
		cout<<"\n Value not found!!";
	}

    void display()
    {
    	list<int>::iterator j;
        for (int i = 0; i < Bucket; i++)
        {
            cout << i;

			
            for (j = table[i].begin(); j != table[i].end(); j++)
            {
                cout<<" --> "<< *j;
            }
            
            cout<<endl;
        }
        
    }
};

int main()
{
    
    Hash obj(10);

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(1235);
    
    obj.display();

	cout<<endl<<"Deleting test"<<endl;
	obj.deleteItem(5);
	obj.display();

	obj.search(2);
	obj.search(7);

    return 0;
}
