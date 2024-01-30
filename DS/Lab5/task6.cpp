#include <iostream>
using namespace std;

void display_sum(int *array[], int rows , int sizes[]);

void display(int *array[], int rows , int sizes[]);

void Recursive_array_sum(int *array[], int rows , int sizes[])
{
    int static count = 0, sum = 0, i, j;

    if (rows < 0)
    {
        cout << "Sum of all elements: " << sum << endl;
        return;       
    }
    
    i = rows-1;
    for (int j = 0; j < sizes[i]; j++)
    {
        sum += array[i][j];   
    }
    
    Recursive_array_sum(array, i, sizes);
}


int main()
{

    const int rows = 3;
    int *array[rows];

    int sizes[] = {3, 4, 2};

    for (int i = 0; i < rows; i++)
    {

        array[i] = new int[sizes[i]];

        for (int j = 0; j < sizes[i]; j++)
        {
            // cout << "\nEnter value for jagged sizess: ";
            // cin >> array[i][j];
            array[i][j] = i+j;
        }
    }


    display(array, rows, sizes);
    display_sum(array, rows, sizes);

    cout<<"\nRecursive Sum: ";
    Recursive_array_sum(array, rows, sizes);

    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
}



void display_sum(int *array[], int rows , int sizes[])
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            sum += array[i][j];
        }
        
    }

    cout<<"\nSum of the jagged array is: "<<sum;
    
}

void display(int *array[], int rows , int sizes[])
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout<<array[i][j] <<" ";
        }
        
        cout<<endl;
    }

}