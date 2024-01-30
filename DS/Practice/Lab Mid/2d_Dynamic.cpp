#include <iostream>
using namespace std;

class Array
{
    int rows, cols;
    int **arr;

    public:

    Array(int r, int c):rows(r), cols(c)
    {
        arr = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int [cols];
        }
    }

    ~Array()
    {
        if(arr != 0)
        {
            for (int i = 0; i < rows; i++)
            {
                if (arr[i] != 0)
                {
                    delete arr[i];
                }
                arr[i] = 0;
                 
            }
            delete arr;    
        }
        arr = 0;
    }

    void fill_array()
    {
        for (int i = 0; i < rows; i++)
        {
            cout<<"\n\n- Rows #"<<i+1<<": \n";
            for (int j = 0; j < rows; j++)
            {
                cout<<"\ncol #"<<j+1<<": ";
                cin>>arr[i][j];
            }

        }
    }

    void print_array()
    {
        cout<<"\n\nDisplaying Array: \n\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout<<arr[i][j]<<" ";   
            }
            cout<<endl;

        }
        
    }

    //Boundary check
    int &operator()(int i, int j)
    {
        if (i<0 || i>rows-1 || j<0 || j>cols-1)
        {
            cout<<"\nBoundary error!";
            exit(1);
        }
        
    }

    //Copy constructor
    Array(const Array &obj)
    {
        rows = obj.rows;
        cols = obj.cols;

        arr = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
            memcpy(arr[i], obj.arr[i], sizeof(int) * cols);
        }
        
    }


    //Copy assignment operator
    Array& operator = (const Array &obj)
    {
        for (int i = 0; i < rows; i++)
        {
            if (arr[i] != 0)
            {
                delete arr[i];
            }   
        }
        delete arr;

        rows = obj.rows;
        cols = obj.cols;

        arr = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
            memcpy(arr[i], obj.arr[i], sizeof(int) * cols);
        }
    }

    
};


int main()
{
    int rows = 3, cols = 3;

    Array obj(rows, cols);
    obj.fill_array();
    obj.print_array();
    
    Array obj2(obj);
    obj2.print_array();

    return 0;
}
