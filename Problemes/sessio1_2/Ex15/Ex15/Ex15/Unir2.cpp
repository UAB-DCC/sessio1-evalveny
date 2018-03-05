#include "Unir2.h"
int cercaPosicio(int vector[], int mida, int valor)
{
	int i = 0;
	while (i < mida && vector[i] <= valor)
	{
		i++;
	}

	return i;
}

void afegeixOrdenadament(int vector[], int mida, int valor)
{
	int posicio = cercaPosicio(vector, mida, valor);
	int temp = vector[posicio];
	vector[posicio] = valor;
	for (int i = posicio + 1; i <= mida; i++)
	{
		int aux = vector[i];
		vector[i] = temp;
		temp = aux;
	}
}

void uneixOrdenadament2(int vector1[], int mida1, int vector2[], int mida2, int vectorUnio[], int mida3)
{
	// copiem la vector ordenada (vector1) a la vector d'unió (vectorUnio)
	for (int i = 0; i < mida1; i++)
	{
		vectorUnio[i] = vector1[i];
	}

	// afegir a la vector d'unió cada valor de la vector dos
	for (int j = 0; j < mida2; j++)
	{
		afegeixOrdenadament(vectorUnio, mida1 + j, vector2[j]);
	}
}
