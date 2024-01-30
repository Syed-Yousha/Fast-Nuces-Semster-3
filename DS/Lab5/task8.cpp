#include <iostream>
using namespace std;
const int N = 4;

   
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    
    for (i = row, j=col ; i>=0 && j>=0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
        
    }
    
    for ( i=row, j=col; i<N && j>=0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
        
    }
    
    return true;

}

bool placeFlag(int board[N][N], int col)
{
    if (col>=N)
    {
        return true;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
        
            if (placeFlag(board, col+1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

void solution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solve()
{
    int board[N][N] = {0};

    if (placeFlag(board, 0) == false)
    {
        cout<<"\nSolution does not exist!";
        return false;
    }
    
    solution(board);
    return true;
}

int main()
{ 
    solve();
    return 0;
}