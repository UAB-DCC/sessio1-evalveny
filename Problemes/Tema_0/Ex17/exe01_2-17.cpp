/*
Test set:
1
###
2
###
4
###
*/

#include <iostream>

using namespace std;

const int N = 4;

void inicialitzaMatriu(int taula[N][N], int X)
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			taula[i][j] = i * j * X;
		}
	}
}

int main()
{
	int taula[N][N];
	int i, j, X;

	cin >> X;
	inicialitzaMatriu(taula, X);
	for(i = 0; i < N; i++)
	{
		cout << "[";
		for(j = 0; j < N; j++)
		{
			cout << taula[i][j] << " ";
		}
		cout << "]" <<endl;
	}
	return 0;
}
