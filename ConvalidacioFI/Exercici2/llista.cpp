#include "llista.h"

bool cercaValor(int llista[], int longitud, int valor, int &posicio)
{
	bool trobat = false;
	bool fi = false;
	int i = 0;
	while ((i < longitud) && !fi && !trobat)
	{
		if (llista[i] == valor)
		{
			trobat = true;
			posicio = i;
		}
		else
			if (llista[i] == -1)
				fi = true;
			else 
				i++;
	}
	return trobat;
}

void desplacaLlista(int llista[], int longitud, int posicio)
{
	for (int i = posicio; i < longitud; i++)
		llista[i - 1] = llista[i];
}

bool eliminaValor(int llista[], int longitud, int valor)
{
	int posicio = 0;
	bool trobat = cercaValor(llista, longitud, valor, posicio);
	if (trobat)
	{
		if (posicio < (longitud - 1))
			desplacaLlista(llista, longitud, posicio + 1);
		llista[longitud - 1] = -1;
	}
	return trobat;
}

bool eliminaValorRepetits(int llista[], int longitud, int valor)
{
	bool fi = false;
	bool trobat = false;
	int i = 0;
	while ((i < longitud) && !fi)
	{
		if (llista[i] == -1)
			fi = true;
		else
		{
			if (llista[i] == valor)
			{
				trobat = true;
				if (i < (longitud - 1))
					desplacaLlista(llista, longitud, i + 1);
				llista[longitud - 1] = -1;
			}
			else
				i++;
		}
	}
	return trobat;
}