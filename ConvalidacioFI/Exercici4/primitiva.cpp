#include "primitiva.h"

int nEncerts(int aposta[], int resultat[])
{
	int nCorrectes = 0;
	for (int i = 0; i < MAX_APOSTES; i++)
	{
		bool encert = false;
		int j = 0;
		while ((j < MAX_APOSTES) && !encert)
		{
			if (aposta[i] == resultat[j])
			{
				encert = true;
				nCorrectes++;
			}
			else j++;
		}
	}
	return nCorrectes;
}

int nEncertsOrdenat(int aposta[], int resultat[])
{
	int i = 0;
	int j = 0;
	int nCorrectes = 0;
	while ((i < MAX_APOSTES) && (j < MAX_APOSTES))
	{
		if (aposta[i] == resultat[j])
		{
			nCorrectes++;
			i++;
			j++;
		}
		else
			if (aposta[i] < resultat[j])
				i++;
			else
				j++;
	}
	return nCorrectes;
}