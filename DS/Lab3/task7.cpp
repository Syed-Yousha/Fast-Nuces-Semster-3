#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void combSort(int arr[], int size)
{
    int gap = size;
    bool swapped = true;

    while (gap > 1 || swapped == true)
    {
        
        //Comb sort formula
        gap = (gap*10)/13;
        if (gap < 1)
        {
            gap = 1;
        }
        
        swapped = false;

        // k226007 swapping
        for (int i = 0; i < size-gap; i++)
        {
            if (arr[i] > arr[i+gap])
            {
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
        
    }


    cout << "\n\n========== Comb Sort ==========\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
    
}


int main()
{
    int myarr[] = {9, 5, 1, 4, 3, 14, 119};
    int size = sizeof(myarr) / sizeof(int);

    combSort(myarr, size);
}