//
//  Recorreguts.cpp
//  Test funcions repàs
//

#include "Recorreguts.h"

/*
 * exercici 3
 */
void uneixOrdenadament(int llista1[], int mida1, int llista2[], int mida2, int llistaUnio[], int mida3)
{
	int i = 0; // index llista 1
	int j = 0; // index llista 2
	int k = 0; // index llista unió

	while (i < mida1 && j < mida2)
	{
		if (llista1[i] <= llista2[j])
		{
			llistaUnio[k] = llista1[i];
			i++;
			k++;
		}
		else
		{
			llistaUnio[k] = llista2[j];
			j++;
			k++;
		}
	}

	for (int x = i; x < mida1; x++)
	{
		llistaUnio[k] = llista1[x];
		k++;
	}

	for (int x = j; x < mida2; x++)
	{
		llistaUnio[k] = llista2[x];
		k++;
	}
}

/*
 * exercici 4
 */
int cercaPosicio(int llista[], int mida, int valor)
{
	int i = 0;
	while (i < mida && llista[i] <= valor)
	{
		i++;
	}

	return i;
}

void afegeixOrdenadament(int llista[], int mida, int valor)
{
	int posicio = cercaPosicio(llista, mida, valor);
	int temp = llista[posicio];
	llista[posicio] = valor;
	for (int i = posicio+1; i <= mida; i++)
	{
		int aux = llista[i];
		llista[i] = temp;
		temp = aux;
	}
}

void uneixOrdenadament2(int llista1[], int mida1, int llista2[], int mida2, int llistaUnio[], int mida3)
{
	// copiem la llista ordenada (llista1) a la llista d'unió (llistaUnio)
	for (int i = 0; i < mida1; i++)
	{
		llistaUnio[i] = llista1[i];
	}

	// afegir a la llista d'unió cada valor de la llista dos
	for (int j = 0; j < mida2; j++)
	{
		afegeixOrdenadament(llistaUnio, mida1 + j, llista2[j]);
	}
}


/*
 * exercici 5
 */
bool esSimetrica(int matriu[N][N]) {
	int i = 0;
	bool simetrica = true;
	while (i < N && simetrica)
	{
		int j = i + 1;
		while (j < N && simetrica)//matriu[i][i])
		{
			//cout << matriu[i][j] << endl;
			if (matriu[i][j] != matriu[j][i]) {
				simetrica = false;
			}
			j++;
		}
		//cout << endl;
		i++;
	}

	return simetrica;
}
