#include <iostream>
using namespace std;
const int n = 5;

bool isSafe(int board[n][n], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    return true;
}

bool solveQueen(int board[n][n], int col)
{
    if (col >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
        }
        if (isSafe(board, i, col + 1))
        {
            return true;
        }
        board[i][col] = 0; // backtrack
    }
    return false;
}

void solution(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

bool solve()
{
    int board[n][n] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    if (solveQueen(board, 0) == false)
    {
        cout << "Solution does not exist" << endl;
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
