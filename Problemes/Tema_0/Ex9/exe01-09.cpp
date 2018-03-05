/*
Test set:
2
4
6
8
10
2
###
3
6
9
12
10
3
###
5
8
10
15
20
5
###
*/

#include <iostream>

using namespace std;

const int N = 5;

bool totsMultiples(int vector[], int longitud, int n)
{
	bool multiples = true;
	int i = 0;
	do
    {
        if ((vector[i] % n) != 0)
            multiples = false;
        else
            i++;
    } while (multiples && (i < longitud));
    return multiples;
}

int main()
{
	int vector[N], numero;

    cout << "Introdueix els " << N << " elements del vector:" <<endl;
	for(int i = 0; i < N; i++)
	{
		cin >> vector[i];
	}
	cout << "Introdueix un numero:"<<endl;
	cin >> numero;
	bool resultat = totsMultiples(vector, N, numero);
	if (resultat)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
	return 0;
}
