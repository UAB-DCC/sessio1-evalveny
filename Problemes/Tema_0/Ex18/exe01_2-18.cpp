/*
Test set:
1
1
2
2
3
3
4
4
5
5
6
6
###
Sol:#1#4#9##16#25#36##49#64#81#
###
1
2
3
4
5
6
7
8
9
9
8
7
6
5
4
3
2
1
###
Sol: #2#12#30##56#81#56##30#12#2#
*/
#include <iostream>

using namespace std;


const int N = 3;

void multMatriuComponents(int taula1[N][N], int taula2[N][N], int taulaRes[N][N])
{
	for (int i = 0; i< N; i++)
	{
		for (int j = 0; j< N; j++)
		{
			taulaRes[i][j] = taula1[i][j] * taula2[i][j];
		}
	}
}


int main()
{
	int taula1[N][N];
	int taula2[N][N];
	int taulaRes[N][N];
	for (int i = 0; i< N; i++)
	{
		for (int j = 0; j< N; j++)
		{
			cin >> taula1[i][j];
			cin >> taula2[i][j];
		}
	}

	multMatriuComponents(taula1, taula2, taulaRes);

	for (int i = 0; i< N; i++)
	{
		cout << "[";
		for (int j = 0; j< N; j++)
		{
			cout << taulaRes[i][j] << " ";
		}
		cout << "]"<<endl;
	}

    return 0;
}
