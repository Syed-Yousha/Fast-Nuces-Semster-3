#include <bits/stdc++.h>
#include <iostream>
#include <list>
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

	void pair_searching()
	{
		list<int>::iterator j;
		
		for(int i = 0; i < Bucket - 1; i++ )
		{
			for(j = table[i].begin(); j != table[i].end(); j++)
			{
				auto j2 = next(j); 
				if( (i)+(*j) ==  (i+1 ) + (*j2) )
				{
					cout<<"\n( "<<i<<", "<<j<<" ) = ( "<<i2<<", "<<j2<<" )";
					cout<<"\n Explaination: "<<i<<" + "<<j<<" = "<<i2<<" + "<<j2;	
				}		
			}
		}
	}

    void display()
    {
    	
    	cout<<"\n\nSearching pairs: \n";
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

    int arr[] = {1,2,3,124,5,1115};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    for(int i =0; i<size; i++)
    {
    	obj.insert(arr[i]);
	}
	
	   
    obj.display();

	cout<<endl<<"Deleting test"<<endl;
	obj.deleteItem(5);
	obj.display();

	obj.search(2);
	obj.search(7);

	obj.pair_searching();	

    return 0;
}
