// ex3_2ab.cpp: define el punto de entrada de la aplicación de consola.
//
/*
Proves:
*primera
Numerador:1
Denominador:2
Numerador:4
Denominador:8
Numerador:3
Denominador:6
Numerador:8
Denominador:2
Numerador:1
Denominador:3
#5.83333#3360#576#0.166667#96#576#-4.83333#-2784#576#1.5#288#192#

*segona
Numerador:2
Denominador:1
Numerador:5
Denominador:0
Numerador:6
Denominador:0
Numerador:7
Denominador:0
Numerador:8
Denominador:0
#No#

*tercera
Numerador:2
Denominador:1
Numerador:3
Denominador:1
Numerador:4
Denominador:0
Numerador:3
Denominador:0
Numerador:5
Denominador:0
#5#5#1#6#6#1#-1#-1#1#0.666667#2#3#

*/

#include "Racional.h"

#include <iostream>
using namespace std;

int main()
{
	const int N = 5;
	NombreRacional nR[N];
	int numerador, denominador;

	for (int i = 0; i < N; i++)
	{
		cout << "Numerador:";
		cin >> numerador;
		cout << "Denominador:";
		cin >> denominador;
		nR[i].setNumerador(numerador);
		nR[i].setDenominador(denominador);
	}

	int numCorrectes = 0;
	int primCorrecte;
	int i = 0;
	do
	{
		if (nR[i].esValid())
		{
			if (numCorrectes == 0)
			{
				primCorrecte = i;
			}
			numCorrectes++;
		}
		i++;
	} while ((numCorrectes < 2) && (i < N));

	if (numCorrectes > 1)
	{
		NombreRacional suma;
		NombreRacional resta;
		NombreRacional producte;
		NombreRacional divisio;
		suma=nR[primCorrecte];
		resta=nR[primCorrecte];
		producte=nR[primCorrecte];
		divisio=nR[primCorrecte];
		for (int j = primCorrecte+1; j < N; j++)
		{
			if (nR[j].esValid())
			{
				suma.suma(nR[j]);
				resta.resta(nR[j]);
				producte.multiplica(nR[j]);
				divisio.divideix(nR[j]);
			}
		}
		cout << "#" << suma.decimal() << "#" << suma.getNumerador() << "#" << suma.getDenominador() << "#" << producte.decimal() << "#" << producte.getNumerador() << "#" << producte.getDenominador() << "#" << resta.decimal() << "#" << resta.getNumerador() << "#" << resta.getDenominador() << "#" << divisio.decimal() << "#" << divisio.getNumerador() << "#" << divisio.getDenominador() << "#";
	}
	else
	{
		cout << "#No#";
	}
	
    return 0;
}

