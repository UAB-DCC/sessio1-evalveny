#include "quatre_ratlla.h"

bool posaFitxa(int tauler[N_FILES][N_COLUMNES], int columna, int jugador)
{
	bool posat = false;

	int i = 0;
	bool trobat = false;
	while ((i < N_FILES) && !trobat)
	{
		if (tauler[i][columna] != 0)
			trobat = true;
		else i++;
	}
	if (i > 0)
	{
		posat = true;
		tauler[i - 1][columna] = jugador;
	}
	return posat;
}

bool quatreRatllaHoritzontal(int tauler[N_FILES][N_COLUMNES], int fila, int columna)
{
	bool iguals = true;
	bool ratlla = false;
	int i = 0;
	int pos = columna;
	while ((i < 3) && (pos < (N_COLUMNES - 1)) && iguals)
	{
		if (tauler[fila][pos] != tauler[fila][pos + 1])
			iguals = false;
		else
		{
			i++;
			pos++;
		}
	}
	if (i == 3)
		ratlla = true;
	else
		ratlla = false;
	return ratlla;
}

bool quatreRatllaDiagonal(int tauler[N_FILES][N_COLUMNES], int fila, int columna)
{
	bool iguals = true;
	bool ratlla = false;
	int i = 0;
	int posCol = columna;
	int posFil = fila;
	while ((i < 3) && (posCol < (N_COLUMNES - 1)) && (posFil < (N_FILES - 1)) && iguals)
	{
		if (tauler[posFil][posCol] != tauler[posFil+1][posCol+1])
			iguals = false;
		else
		{
			i++;
			posFil++;
			posCol++;
		}
	}
	if (i == 3)
		ratlla = true;
	else
		ratlla = false;
	return ratlla;
}
