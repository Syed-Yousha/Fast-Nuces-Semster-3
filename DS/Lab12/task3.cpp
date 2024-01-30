#include <bits/stdc++.h>
using namespace std;


template <typename K, typename V>

class Hash
{
	public:
	V value;
	K key;
	
	
	Hash(K key, V value)
	{
		this->key = key;
		this->value = value;
	}
	
};


template <typename K, typename V>


class HashMap
{
	Hash<K, V>** arr;
	
	int capacity;
	int size;
	Hash<K, V>* dummy;
	
	
public:
	HashMap()
	{
		capacity = 20;
		size = 0;
		arr = new Hash<K, V>*[capacity];
		
		for(int i = 0; i < capacity; i++)
		{
			arr[i] = NULL;
		}
		
		
		dummy = new Hash<K, V>(-1, -1);
	}
	
	
	int hashCode(K key)
	{
		return key % capacity;
	}
	
	
	void insertNode(K key, V value)
	{
		Hash<K, V>* temp = new Hash<K, V>(key, value);
		
		int hashIndex = hashCode(key);
		
		while(arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}
		
		
		if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
		{
			size++;
			arr[hashIndex] = temp;
		}
	}
	
	
	V deleteNode(int key)
	{
		int hashIndex = hashCode(key);
		
		while(arr[hashIndex] != NULL)
		{
			if(arr[hashIndex]->key == key)
			{
				Hash<K, V>* temp = arr[hashIndex];
				
				arr[hashIndex] = dummy;
				
				size--;
				return temp->value;
			}
			
			hashIndex++;
			hashIndex %= capacity;
		}
			
		return NULL;	
	}
	
	V search(int key)
	{
		int hashIndex = hashCode(key);
		
		int counter = 0;
		
		while(arr[hashIndex] != NULL)
		{
			
			if(counter++ > capacity)
			{
				cout<<"Key: "<<key<<" not found!!\n";	
				return NULL;
			}	
				
			
			if(arr[hashIndex]->key == key)
			{
				cout<<"\nValue found: ";
				return arr[hashIndex]->value;
			}
			
			hashIndex++;
			hashIndex %= capacity;
			
		}
		
		cout<<"Key: "<<key<<" not found!!\n";
		return NULL;
	}	
	
	int sizeofMap()
	{
		return size;
	}
	
	bool isEmpty()
	{
		return size ==0;
	}
	
	void display()
	{
		for(int i=0; i < capacity; i++)
		{
			if( arr[i] != NULL && arr[i]->key != -1 )
			{
				cout<<"key = "<< arr[i]->key << " value = " << arr[i]->value << endl; 
			}
		}
	}
	
};





int main()
{
	HashMap<int, int>* h = new HashMap<int, int>;
	
	h->insertNode(1, 1);
	h->insertNode(2, 2);
	h->insertNode(2, 3);
	h->insertNode(4, 7);
	h->display();
	
	cout<< h->sizeofMap() <<endl;
	cout<< h->deleteNode(2) <<endl;
	cout<< h->sizeofMap() <<endl;
	cout<< h->isEmpty() <<endl;
	cout<< h->search(4);
	
	return 0;
}
