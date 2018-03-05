/*
Test set:
M'encanta_programar
3
###
Metodologia_de_la_programacio
2
###
Programar_o_no_programar
10
###
*/

#include <iostream>

using namespace std;

int main()
{
	string frase;
	int i, X;

    cout << "Introdueix una frase:" <<endl;
	cin >> frase;
	cin >> X;
	i = 0;
	while(frase[i] != '\0')
	{
		frase[i] += X;
		i++;
	}
	cout << "La frase codificada es: " << frase;
	return 0;
}
