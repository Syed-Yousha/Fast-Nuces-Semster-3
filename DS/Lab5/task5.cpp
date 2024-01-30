#include <iostream>
using namespace std;

void display_sum(int *array[], int rows , int col[]);
void display(int *array[], int rows , int col[]);

int main()
{

    const int rows = 3;
    int *array[rows];

    int col[] = {3, 4, 2};

    for (int i = 0; i < rows; i++)
    {

        array[i] = new int[col[i]];

        for (int j = 0; j < col[i]; j++)
        {
            // cout << "\nEnter value for jagged cols: ";
            // cin >> array[i][j];
            array[i][j] = i+j;
        }
    }


    display(array, rows, col);
    display_sum(array, rows, col);

    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
}



void display_sum(int *array[], int rows , int col[])
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            sum += array[i][j];
        }
        
    }

    cout<<"\nSum of the jagged array is: "<<sum;
    
}

void display(int *array[], int rows , int col[])
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout<<array[i][j] <<" ";
        }
        
        cout<<endl;
    }

}