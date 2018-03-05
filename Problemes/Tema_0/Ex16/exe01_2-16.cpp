/*
Test set:
3
###
5
###
10
###
*/

#include <iostream>

using namespace std;

const int N = 5;

void inicialitzaMatriu(int taula[N][N], int X)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			taula[i][j] = j + 1 + X;
		}
	}
}

int main()
{
	int taula[N][N];
	int X;

	cin >> X;
	inicialitzaMatriu(taula, X);
	for(int i = 0; i < N; i++)
	{
	    cout << "[";
		if (N>0)

		for(int j = 0; j < N; j++)
		{
			cout << taula[i][j] << " ";
		}
		cout << "]" <<endl;

	}
	return 0;
}
