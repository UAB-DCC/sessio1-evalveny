/*
Test set:
5
7
3
5
8
###
54
72
123
45
81
###
*/

#include <iostream>

using namespace std;

const int N = 5;

int main()
{
	int vector[N], i, petit;

	for(i = 0; i < N; i++)
	{
		cin >> vector[i];
	}
	petit = 0;
	for(i = 1; i < N; i++)
	{
		if(vector[i] < vector[petit])
		{
			petit = i;
		}
	}
	cout << vector[petit] << endl << petit;
	return 0;
}
