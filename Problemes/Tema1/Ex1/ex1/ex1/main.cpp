//Exercici 1 Tema1

#include "PiramideQuadrada.h"

#include <iostream>
using namespace std;

int main()
{
	float longitud;
	float alcada;
	PiramideQuadrada p;

	cout << "Entra longitud:";
	cin >> longitud;

	cout << "Entra alcada:";
	cin >> alcada;

	p.setLongitud(longitud);
	p.setAlcada(alcada);

	if (p.esValid())
	{
		cout << p.volum() << endl << p.area() << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}

	return 0;
}