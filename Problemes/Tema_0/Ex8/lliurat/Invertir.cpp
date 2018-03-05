#include "Invertir.h"

void invertirVector(int v1[], int longitud)
{
	for (int i = 0; i < longitud / 2; i++)
	{
		int aux = v1[i];
		v1[i] = v1[longitud - i - 1];
		v1[longitud - i - 1] = aux;
	}

}