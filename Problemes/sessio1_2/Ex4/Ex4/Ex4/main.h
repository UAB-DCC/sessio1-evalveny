#pragma once

//Ex4: 

#include "stdafx.h"
#include "Invertir.h"
#include <iostream>
using namespace std;

void mostraVector(int v[], int longitud)
{
	cout << "[";
	if (longitud > 0)
	{
		cout << v[0];
	}
	for (int i = 1; i < longitud; i++)
		cout << "," << v[i];
	cout << "]" << endl;
}

bool comparaVector(int v1[], int v2[], int longitud)
{
	bool iguals = true;
	int i = 0;
	while ((iguals) && (i < longitud))
	{
		if (v1[i] != v2[i])
			iguals = false;
		i++;
	}
	return iguals;
}

float testInvertir()
{
	const int NPROVES = 5;
	const int MAXMIDA = 5;
	int vector[NPROVES][MAXMIDA] =
	{
		{ 0, 0, 0, 0, 0 },
		{ 1, 2, 3, 4, 5 },
		{ 5, 4, 3, 2, 1 },
		{},
		{ 1 }
	};
	int longitud[NPROVES] = { 5, 5, 5, 0, 1 };
	int resultat[NPROVES][MAXMIDA] =
	{
		{ 0, 0, 0, 0, 0 },
		{ 5, 4, 3, 2, 1 },
		{ 1, 2, 3, 4, 5 },
		{},
		{ 1 }
	};

	float reduccio = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test inversio vector" << endl;
	cout << "Comment :=>> =============================" << endl;

	for (int i = 0; i < NPROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Vector a invertir: " << endl;
		mostraVector(vector[i], longitud[i]);
		cout << endl;
		invertirVector(vector[i], longitud[i]);
		cout << "Comment :=>> Resultat obtingut: " << endl;
		mostraVector(vector[i], longitud[i]);
		cout << endl;
		if (comparaVector(vector[i], resultat[i], longitud[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << endl;
			mostraVector(resultat[i], longitud[i]);
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	return reduccio;
}

int main()
{
	float grade = 10.0;

	grade -= testInvertir();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
