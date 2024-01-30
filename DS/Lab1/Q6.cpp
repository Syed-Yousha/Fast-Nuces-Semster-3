#include <iostream>
using namespace std;

class Box
{
    int layers, *arr;

    public:

    Box(){}
    Box(int l):layers(l)
    {

        arr = new int[layers];

        //input
        for(int i=0; i<layers; i++)
		{
			cout<<"\n============ Enter Cubes in layers # "<<i+1<<" : ";
            cin>>arr[i];
		}
        
    }

    void display()
	{
		
		
		cout<<"\n\n ========== Layers config ==========\n";
		
		for(int i=0; i<layers; i++)
		{
			cout<<"\n layer #"<< i+1<<" : ";
            cout<<arr[i];
		}
		
	}

    ~Box()
    {
        delete[] arr;
    }
    
};


int main()
{
    int layers;

    cout<<"\nEnter the number of Layers in the box: ";
    cin>> layers;

    Box obj(layers);

    obj.display();
    return 0;
}