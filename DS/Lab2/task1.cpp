#include <iostream>
using namespace std;

int main()
{
    int const size = 3;
    int matrix[size][size] = {
        {2, 0, 0},
        {0, 5, 0},
        {0, 0, 0}};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            
            if(i != j && matrix[i][j] != 0)
            {
                cout << "\nMatrix ain't diagonal matrix!!!";
                exit(1);
            }
            
            
        }
    }

    cout << "\n\nMatrix is a Diagonal Matrix....";
}
