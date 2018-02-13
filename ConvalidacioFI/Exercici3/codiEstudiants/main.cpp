#include "Estudiants.h"
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

float testCalculHistograma()
{
	const int N_PROVES = 5;
	const int MAX_LLISTA = 10;
	const int N_EDATS = 14;
	int llistaEdats[N_PROVES][MAX_LLISTA] = 
	{
		{ 18, 18, 30, 30, 25, 20, 30, 18, 25, 21 },
		{ 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
		{ 31, 40, 35, 45, 32, 33, 40, 31, 31, 35 },
		{ 18, 19, 20, 21, 22, 23, 24, 25, 26, 35 },
		{ 18, 19, 20, 21, 22, 23, 30, 40, 32, 35 },
	};
	int resultat[N_PROVES][N_EDATS] =
	{
		{ 3, 0, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 3 }
	};

	float reduccio = 0.0;
	int frequenciaEdats[N_EDATS];

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de calcular frquencies d'edats" << endl;
	cout << "Comment :=>> ============================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i+1 << endl;
		cout << "Comment :=>> Llista d'edats: ";
		mostraArray(llistaEdats[i], MAX_LLISTA);
		
		estadisticaEdats (llistaEdats[i], MAX_LLISTA, frequenciaEdats);
		
		cout << "Comment :=>> Resultat obtingut. Frequencia d'edats: ";
		mostraArray(frequenciaEdats, N_EDATS);
		
		if (comparaArrays(resultat[i], frequenciaEdats, N_EDATS))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava frequencia d'edats: ";
			mostraArray(resultat[i], N_EDATS);
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}


float testMaximMinim()
{
	const int N_PROVES = 5;
	const int N_EDATS = 14;
	int frequenciaEdats[N_PROVES][N_EDATS] =
	{
		{ 5, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1 },
		{ 0, 5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 5 },
		{ 1, 5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 0 },
		{ 5, 3, 6, 2, 5, 7, 5, 4, 6, 3, 5, 4, 4, 6 },
	};
	int resultatEdatMinima[N_PROVES] ={	19, 18, 19, 31, 21};
	int resultatEdatMaxima[N_PROVES] = { 18, 19, 31, 19, 23 };
	int resultatNEstMinima[N_PROVES] = { 0, 0, 0, 0, 2 };
	int resultatNEstMaxima[N_PROVES] = { 5, 5, 5, 5, 7 };

	float reduccio = 0.0;
	int edatMinim, edatMaxim, nEstMinim, nEstMaxim;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de calcular edat amb minim i maxim d'estudiants" << endl;
	cout << "Comment :=>> =============================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Frequencia d'edats: ";
		mostraArray(frequenciaEdats[i], N_EDATS);

		minimMaximEdat(frequenciaEdats[i], edatMinim, edatMaxim, nEstMinim, nEstMaxim);

		cout << "Comment :=>> Resultat obtingut. Edat amb minm: " << edatMinim << ". N est edat minim: " << nEstMinim <<
			". Edat amb maxim: " << edatMaxim << ". N est edat maxim: " << nEstMaxim << endl;;

		if ((edatMinim == resultatEdatMinima[i]) && (edatMaxim == resultatEdatMaxima[i]) && 
			(nEstMinim == resultatNEstMinima[i]) && (nEstMaxim == resultatNEstMaxima[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava. Edat amb minm: " << resultatEdatMinima[i] << ". N est edat minim: " << resultatNEstMinima[i] <<
				". Edat amb maxim: " << resultatEdatMaxima[i] << ". N est edat maxim: " << resultatNEstMaxima[i] << endl;;

			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}

int main()
{
	float grade = 10.0;

	grade -= testCalculHistograma();
	grade -= testMaximMinim();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}