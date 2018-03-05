#include "Unir.h"

void uneixOrdenadament(int vector1[], int mida1, int vector2[], int mida2, int vectorUnio[], int mida3)
{
	int i = 0; // index llista 1
	int j = 0; // index llista 2
	int k = 0; // index llista unió

	while (i < mida1 && j < mida2)
	{
		if (vector1[i] <= vector2[j])
		{
			vectorUnio[k] = vector1[i];
			i++;
			k++;
		}
		else
		{
			vectorUnio[k] = vector2[j];
			j++;
			k++;
		}
	}

	for (int x = i; x < mida1; x++)
	{
		vectorUnio[k] = vector1[x];
		k++;
	}

	for (int x = j; x < mida2; x++)
	{
		vectorUnio[k] = vector2[x];
		k++;
	}
}
