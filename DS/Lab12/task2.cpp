#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int Bucket;

    list<string> *table;

public:
    Hash(int B)
    {
        Bucket = B;
        table = new list<string>[Bucket];
    }

    int hashFunction(char x)
    {
        return (x % Bucket);
    }


    void insert(char key, string str)
    {
        int index = hashFunction(key);
        table[index].push_back(str);
    }    

    void deleteItem(char key, string str)
    {
        int index = hashFunction(key);

        list <string> :: iterator i;
        for (i = table[index].begin() ;i != table[index].end(); i++)
        {
            if (*i == str)
            {
                break;
            }
            
        }
        
        if (i != table[index].end())
        {
            table[index].erase(i);
        }
        cout<<"\nitem "<< str <<" deleted successfully!\n";
        
    }

	void word_search(char key)
	{
		int index = hashFunction(key);
		
		list<string> :: iterator i;
		cout<<"\nAt key: "<<key<<" strings found are: \n";
		for(i = table[index].begin(); i != table[index].end(); i++)
		{
			cout<<endl<<*i;
		}
	}

    void display()
    {
    	list<string>::iterator j;
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

    obj.insert('A', "Fast-Nu");
    obj.insert('B', "Home");
    obj.insert('A', "fly");
    obj.insert('C', "trust");
    obj.insert('B', "beyond");
    obj.insert('B', "dark");
    
    
    obj.display();

	cout<<endl<<endl;
	obj.deleteItem('B', "dark");
	obj.display();
	
	obj.word_search('A');

    return 0;
}
