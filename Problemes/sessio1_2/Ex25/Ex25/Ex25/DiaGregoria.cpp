//
//  DiaGregoria.cpp
//  Test funcions repàs
//

#include <stdio.h>
#include <iostream>

#include "DiaGregoria.h"

/*
 * exercici 1
 */
void llegeixDia(DiaGregoria& diaCalendari)
{
	cout << "Entra el dia: ";
	cin >> diaCalendari.dia;
	cout << "Entra el mes: ";
	cin >> diaCalendari.mes;
	cout << "Entra l'any: ";
	cin >> diaCalendari.any;
}

bool esTraspas(DiaGregoria& diaCalendari)
{
	// Recordeu que els anys de traspàs són tots els divisibles per 4,
	// en excepció dels que siguin divisibles per 100, però no els que
	// siguin divisibles per 400.

	return (diaCalendari.any % 4) == 0 && ((diaCalendari.any % 100) != 0 || (diaCalendari.any % 400) == 0);
}

bool esValid(DiaGregoria& diaCalendari)
{
	unsigned int diesMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (esTraspas(diaCalendari))
	{
		diesMes[1]++;
	}

	return (1 <= diaCalendari.mes && diaCalendari.mes <= 12 && 1 <= diaCalendari.any && 1 <= diaCalendari.dia && diaCalendari.dia <= diesMes[diaCalendari.mes - 1]);
}

int totalDies(DiaGregoria& diaCalendari)
{
	int diesMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (esTraspas(diaCalendari))
	{
		diesMes[1]++;
	}
	int a = diaCalendari.any - 1;
	int acumDiesAnys = (a * 365) + (a / 4) - (a / 100) + (a / 400);
	int acumDiesMes = 0;
	for (unsigned int i = 0; i < diaCalendari.mes - 1; i++)
	{
		acumDiesMes += diesMes[i];
	}
	
	return diaCalendari.dia + acumDiesMes + acumDiesAnys;
}

int diferenciaDies(DiaGregoria& diaCalendari1, DiaGregoria& diaCalendari2)
{
	return (totalDies(diaCalendari1) - totalDies(diaCalendari2));
}

int mesFrequent(DiaGregoria dates[], int nDates)
{
	int frequenciaMes[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < nDates; i++)
		frequenciaMes[dates[i].mes - 1]++;
	int mesMax = 0;
	for (int i = 1; i < 12; i++)
		if (frequenciaMes[i] > frequenciaMes[mesMax])
			mesMax = i;
	return mesMax + 1;
}
