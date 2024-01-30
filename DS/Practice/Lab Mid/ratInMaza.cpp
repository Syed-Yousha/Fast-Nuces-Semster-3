#include <iostream>
using namespace std;

bool is_Safe(int arr[][4], int x, int y, int size)
{
    if (x < size && y < size && arr[x][y] == 1)
    {
        return true;
    }
    
}

bool ratinMaze(int arr[][4], int x, int y, int n, int solArr[][4])
{
    if (x == (n-1) && y == (n - 1))
    {
        solArr[x][y] = 1;
        return true;
    }

    if (is_Safe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (ratinMaze(arr, x+1, y, n, solArr))
        {
            return true;
        }
        
        if (ratinMaze(arr, x, y+1, n, solArr))
        {
            return true;
        }
        
        solArr[x][y] = 0; //backtrack
        return false;
    }
    
    return false;
}

int main()
{
    const int n = 4;

    int arr[n][n] = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,1,1},
        {0,0,0,1}
    };

    int sol[n][n] = {0};

    ratinMaze(arr, 0, 0, n, sol);

    // Solution array
    cout<<"\n\nSolution array:\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
    
    return 0;
}