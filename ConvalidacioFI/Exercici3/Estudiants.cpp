#include "Estudiants.h"

void estadisticaEdats(int edatsEstudiants[], int nEstudiants, int frequenciaEdats[])
{
	for (int i = 0; i < (EDAT_MAXIMA - EDAT_MINIMA + 2); i++)
		frequenciaEdats[i] = 0;

	for (int i = 0; i < nEstudiants; i++)
	{
		if (edatsEstudiants[i] <= EDAT_MAXIMA)
			frequenciaEdats[edatsEstudiants[i] - EDAT_MINIMA]++;
		else
			frequenciaEdats[EDAT_MAXIMA - EDAT_MINIMA + 1]++;
	}
}

void minimMaximEdat(int edatsEstudiants[], int &edatMinim, int &edatMaxim, int &nEstMinim, int &nEstMaxim)
{
	edatMinim = 0;
	edatMaxim = 0;
	for (int i = 1; i < (EDAT_MAXIMA - EDAT_MINIMA + 2); i++)
	{
		if (edatsEstudiants[i] > edatsEstudiants[edatMaxim])
			edatMaxim = i;
		else
			if (edatsEstudiants[i] < edatsEstudiants[edatMinim])
				edatMinim = i;
	}
	nEstMinim = edatsEstudiants[edatMinim];
	nEstMaxim = edatsEstudiants[edatMaxim];
	edatMinim += EDAT_MINIMA;
	edatMaxim += EDAT_MINIMA;
}
