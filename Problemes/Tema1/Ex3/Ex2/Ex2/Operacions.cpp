#include "Operacions.h"

bool operar(NombreRacional nR[], NombreRacional& nRSuma, NombreRacional& nRResta,
	NombreRacional& nRProducte, NombreRacional& nRDivisio, int mida)
{
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
	} while ((numCorrectes < 2) && (i < mida));

	if (numCorrectes > 1)
	{

		nRSuma = nR[primCorrecte];
		nRResta = nR[primCorrecte];
		nRProducte = nR[primCorrecte];
		nRDivisio = nR[primCorrecte];

		for (int j = primCorrecte + 1; j < mida; j++)
		{
			if (nR[j].esValid())
			{
				nRSuma.suma(nR[j]);
				nRResta.resta(nR[j]);
				nRProducte.multiplica(nR[j]);
				nRDivisio.divideix(nR[j]);
			}
		}

	}

	return (numCorrectes > 1);
}

