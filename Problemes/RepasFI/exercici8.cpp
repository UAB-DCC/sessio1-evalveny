/*
Test set:
3
5
1
2
4
###
1
2
3
4
5
###
5
4
3
2
1
###
*/

#include <iostream>

using namespace std;

const int N = 5;

void invertir(int* vector)
{
	int i, temp;
	for(i = 0; i < N / 2; i++)
	{
		temp = vector[i];
		vector[i] = vector[N - i - 1];
		vector[N - i - 1] = temp;
	}
}

int main()
{
	int vector[N], i;

    cout << "Introdueix els " << N << " valors del vector: ";
	for(i = 0; i < N; i++)
	{
		cin >> vector[i];
	}
	invertir(vector);
	cout << "El vector invertit es: ";
	cout << "#";
	for(i = 0; i < N; i++)
	{
		cout << vector[i] << "#";
	}
	return 0;
}
