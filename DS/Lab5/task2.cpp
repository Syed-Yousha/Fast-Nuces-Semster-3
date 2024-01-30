#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void guess(int num, bool flag)
{
	int static n = num;
	
	if(n == num && flag == 1)
	{
		cout<<"\n You guessed the right number! good";
		exit(0);
	}
	else if(num < n)
	{
		cout<<"\n guess is small than number !";
	}
	else if(num > n)
	{
		cout<<"\n guess is greater than number !";
	}
	
	
	jump:
	int guess_num;
	cout<<"\n\n Take a guess , less than 100 and greater than 0: ";
	cin>> guess_num;
	
	if( guess_num < 0)
	{
		cout<<"\error! number should be greater than 0!";
		goto jump;
	}
	
	if( guess_num > 100)
	{
		cout<<"\error! number should be smaller than 100!";
		goto jump;
	}
	
	
	guess(guess_num, 1);
	
}

int main()
{
	srand(time(NULL));
	int num = rand()%100;
	cout<<num;
	guess(num, 0);
	
}
