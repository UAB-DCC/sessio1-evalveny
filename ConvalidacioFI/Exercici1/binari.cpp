#include "binari.h"

int BinariADecimal(int binari[], int longitud)
{
	int valor = 0;
	for (int i = 0; i < longitud; i++)
	{
		valor = (2 * valor) + binari[i];
	}
	return valor;
}

int BinariADecimalSigne(int binari[], int longitud)
{
	int valor = 0;
	int potencia = 1;
	for (int i = 1; i < longitud; i++)
	{
		potencia *= 2;
		valor = (2 * valor) + binari[i];
	}
	if (binari[0] == 1)
		valor -= potencia;
	return valor;
}