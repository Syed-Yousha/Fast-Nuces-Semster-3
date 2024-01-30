#include <iostream>
using namespace std;

bool isSafe(int arr[][5], int x, int y, int n)
{
	if (x < n && y < n && arr[x][y] == 1)
	{
		return true;
	}
	return false;
}

bool lioninMaze(int arr[][5], int x, int y, int n, int solArr[][5])
{
	if ((x == (n - 1)) && (y == (n - 1)))
	{
		solArr[x][y] = 1;
		return true;
	}

	if (isSafe(arr, x, y, n))
	{

		if (lioninMaze(arr, x + 1, y, n, solArr))
		{
			solArr[x][y] = 1;
			return true;
		}
		if (lioninMaze(arr, x, y + 1, n, solArr))
		{
			solArr[x][y] = 1;
			return true;
		}

		solArr[x][y] = 0;  // backtrack
		return false;
	}
	return false;
}

int main()
{
	int arr[5][5] = {
		{1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 0, 1, 0},
		{1, 0, 0, 1, 1},
		{1, 1, 1, 0, 1}};

	int solArr[5][5] = {0};

	lioninMaze(arr, 0, 0, 5, solArr);

	// Solution array
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << solArr[i][j] << " ";
		}
		cout << endl;
	}
}
