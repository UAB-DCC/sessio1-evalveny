#include "llista.h"
#include <iostream>

using namespace std;

void mostraArray(int v[], int longitud)
{
	for (int i = 0; i < longitud; i++)
		cout << v[i] << " ";
	cout << endl;
}

bool comparaArrays(int v1[], int v2[], int longitud)
{
	bool iguals = true;
	int i = 0;
	while ((i < longitud) && iguals)
	{
		if (v1[i] != v2[i])
			iguals = false;
		else
			i++;
	}
	return iguals;
}

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

float testEliminaSenseRepetits()
{
	const int N_PROVES = 8;
	const int MAX_LLISTA = 10;
	int llistaInicial[N_PROVES][MAX_LLISTA] = 
	{
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, -1, -1, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, -1, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, -1, -1, -1 }
	};
	int valor[N_PROVES] = {1, 10, 5, 6, 9, 3, 0, 0};
	bool resultat[N_PROVES] = {true, true, true, true, true, true, false, false};
	int llistaFinal[N_PROVES][MAX_LLISTA] =
	{
		{ 2, 3, 4, 5, 6, 7, 8, 9, 10, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, -1 },
		{ 1, 2, 3, 4, 6, 7, 8, 9, 10, -1 },
		{ 1, 2, 3, 4, 5, -1, -1, -1, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, -1, -1 },
		{ 1, 2, 4, 5, 6, 7, -1, -1, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, -1, -1, -1 }
	};

	float reduccio = 0.0;
	bool eliminat;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de eliminar sense repetits" << endl;
	cout << "Comment :=>> ========================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i+1 << endl;
		cout << "Comment :=>> Llista inicial: ";
		mostraArray(llistaInicial[i], MAX_LLISTA);
		cout << "Comment :=>> Valor a eliminar: " << valor[i] << endl;
		
		eliminat = eliminaValor(llistaInicial[i], MAX_LLISTA, valor[i]);
		
		cout << "Comment :=>> Resultat obtingut. Llista final: ";
		mostraArray(llistaInicial[i], MAX_LLISTA);
		cout << "Comment :=>> Valor de retorn: ";
		mostraBool(eliminat);
		cout << endl;
		
		if ((comparaArrays(llistaInicial[i], llistaFinal[i], MAX_LLISTA)) && (eliminat == resultat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava llista final: ";
			mostraArray(llistaFinal[i], MAX_LLISTA);
			cout << "Comment :=>> Valor de retorn: ";
			mostraBool(resultat[i]);
			cout << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6)
		reduccio = 6.0;
	return reduccio;
}


float testEliminaAmbRepetits()
{
	const int N_PROVES = 10;
	const int MAX_LLISTA = 10;
	int llistaInicial[N_PROVES][MAX_LLISTA] =
	{
		{ 1, 2, 3, 4, 5, 3, 7, 8, 9, 10 },
		{ 1, 1, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 10, 10 },
		{ 1, 2, 3, 4, 5, 5, 7, 8, 9, 10 },
		{ 1, 2, 3, 2, 5, 6, -1, -1, -1, -1 },
		{ 1, 1, 1, 1, 1, 1, -1, -1, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 8, -1 },
		{ 1, 2, 3, 4, 5, 6, 3, -1, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, -1, -1, -1 }
	};
	int valor[N_PROVES] = { 3, 1, 10, 5, 2, 1, 8, 3, 0, 0 };
	bool resultat[N_PROVES] = { true, true, true, true, true, true, true, true, false, false };
	int llistaFinal[N_PROVES][MAX_LLISTA] =
	{
		{ 1, 2, 4, 5, 7, 8, 9, 10, -1, -1 },
		{ 3, 4, 5, 6, 7, 8, 9, 10, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, -1, -1 },
		{ 1, 2, 3, 4, 7, 8, 9, 10, -1, -1 },
		{ 1, 3, 5, 6, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 1, 2, 3, 4, 5, 6, 7, -1, -1, -1 },
		{ 1, 2, 4, 5, 6, -1, -1, -1, -1, -1, },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, -1, -1, -1 }
	};

	float reduccio = 0.0;
	bool eliminat;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de eliminar amb repetits" << endl;
	cout << "Comment :=>> ======================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Llista inicial: ";
		mostraArray(llistaInicial[i], MAX_LLISTA);
		cout << "Comment :=>> Valor a eliminar: " << valor[i] << endl;

		eliminat = eliminaValorRepetits(llistaInicial[i], MAX_LLISTA, valor[i]);

		cout << "Comment :=>> Resultat obtingut. Llista final: ";
		mostraArray(llistaInicial[i], MAX_LLISTA);
		cout << "Comment :=>> Valor de retorn: ";
		mostraBool(eliminat);
		cout << endl;

		if ((comparaArrays(llistaInicial[i], llistaFinal[i], MAX_LLISTA)) && (eliminat == resultat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava llista final: ";
			mostraArray(llistaFinal[i], MAX_LLISTA);
			cout << "Comment :=>> Valor de retorn: ";
			mostraBool(resultat[i]);
			cout << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6)
		reduccio = 6.0;
	return reduccio;
}


int main()
{
	float grade = 10.0;

	grade -= testEliminaSenseRepetits();
	grade -= testEliminaAmbRepetits();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}