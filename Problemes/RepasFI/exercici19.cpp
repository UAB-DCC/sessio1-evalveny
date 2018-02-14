/*
Test set:
1
2
3
4
5
6
7
8
9
###
21
30
12
7
8
45
7
9
11
###
*/

#include <iostream>

using namespace std;

const int N = 3;

void multiplicaMatriu(int m1[N][N],int m2[N][N],int result[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				result[i][j] += m1[i][k] * m2[k][j];
			}

		}
	}
}
int main()
{
	int m1[N][N], m2[N][N], result[N][N];

	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m1[i][j];
			cin >> m2[i][j];
		}
		
	}
	
	multiplicaMatriu(m1, m2, result);

	for(int i = 0; i < N; i++)
	{
		cout << "#";
		for(int j=0;j<N;j++)
		{
			cout << result[i][j] << "#";
		}
	}
	
	return 0;
}
