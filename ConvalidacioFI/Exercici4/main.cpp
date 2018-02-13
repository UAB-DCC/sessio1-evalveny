#include "primitiva.h"
#include <time.h>
#include <iostream>

using namespace std;

void mostraArray(int v[], int longitud)
{
	for (int i = 0; i < longitud; i++)
		cout << v[i] << " ";
	cout << endl;
}

float testNEncertsNoOrdenat()
{
	const int N_PROVES = 5;
	const int MAX_LLISTA = 6;
	int apostes[N_PROVES][MAX_LLISTA] = 
	{
		{ 5, 12, 22, 18, 32, 25 },
		{ 20, 10, 30, 40, 45, 15 },
		{ 40, 10, 30, 20, 15, 45 },
		{ 40, 12, 22, 18, 32, 25 },
		{ 12, 22, 40, 18, 32, 45 },
	};
	int resultats[N_PROVES][MAX_LLISTA] =
	{
		{ 40, 10, 30, 20, 15, 45 },
		{ 40, 10, 30, 20, 15, 45 },
		{ 40, 10, 30, 20, 15, 45 },
		{ 40, 10, 30, 20, 15, 45 },
		{ 40, 10, 30, 20, 15, 45 }
	};
	int nCorrectes[N_PROVES] = {0, 6, 6, 1, 2};

	float reduccio = 0.0;
	int nEncertsResultat;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de calcular n. encerts sense ordenar" << endl;
	cout << "Comment :=>> ==================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i+1 << endl;
		cout << "Comment :=>> Llista d'apostes: ";
		mostraArray(apostes[i], MAX_LLISTA);
		cout << "Comment :=>> Resultat del sorteig: ";
		mostraArray(resultats[i], MAX_LLISTA);

		nEncertsResultat = nEncerts(apostes[i], resultats[i]);
		
		cout << "Comment :=>> Resultat obtingut. N. encerts: " << nEncertsResultat << endl;
		
		if (nEncertsResultat == nCorrectes[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava N. encerts: " << nCorrectes[i] << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}


float testNEncertsOrdenat()
{
	const int N_PROVES = 5;
	const int MAX_LLISTA = 6;
	int apostes[N_PROVES][MAX_LLISTA] =
	{
		{ 5, 12, 18, 22, 25, 32 },
		{ 10, 15, 20, 30, 40, 45 },
		{ 5, 15, 20, 25, 30, 40 },
		{ 5, 12, 15, 18, 22, 30 },
		{ 5, 12, 18, 22, 35, 40 },
	};
	int resultats[N_PROVES][MAX_LLISTA] =
	{
		{ 10, 15, 20, 30, 40, 45 },
		{ 10, 15, 20, 30, 40, 45 },
		{ 10, 15, 20, 30, 40, 45 },
		{ 10, 15, 20, 30, 40, 45 },
		{ 10, 15, 20, 30, 40, 45 }
	};
	int nCorrectes[N_PROVES] = { 0, 6, 4, 2, 1 };

	float reduccio = 0.0;
	int nEncertsResultat;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de calcular n. encerts amb valors ordenats" << endl;
	cout << "Comment :=>> ========================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Llista d'apostes: ";
		mostraArray(apostes[i], MAX_LLISTA);
		cout << "Comment :=>> Resultat del sorteig: ";
		mostraArray(resultats[i], MAX_LLISTA);

		nEncertsResultat = nEncertsOrdenat(apostes[i], resultats[i]);

		cout << "Comment :=>> Resultat obtingut. N. encerts: " << nEncertsResultat << endl;

		if (nEncertsResultat == nCorrectes[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava N. encerts: " << nCorrectes[i] << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}

float testEficienciaOrdenat()
{
	const int MAX_LLISTA = 6;
	int apostes[MAX_LLISTA] = { 5, 12, 18, 22, 25, 32 };
	int resultats[MAX_LLISTA] = { 10, 15, 20, 30, 40, 45 };
	int nEncertsResultat;

	const float FACTOR_EFICIENCIA = 0.7;
	float reduccio = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de eficiencia de la cerca ordenada" << endl;
	cout << "Comment :=>> ================================================" << endl;
	float tempsAcumulatOrdenat = 0;
	float tempsAcumulatNoOrdenat = 0;
	for (int k = 0; k < 10; k++)
	{
		clock_t timeOrdenat;
		timeOrdenat = clock();
		for (int j = 0; j < 1000000; j++)
		{
			nEncertsResultat = nEncertsOrdenat(apostes, resultats);
		}
		timeOrdenat = clock() - timeOrdenat;
		tempsAcumulatOrdenat += (float)timeOrdenat / CLOCKS_PER_SEC;

		clock_t timeNoOrdenat;
		timeNoOrdenat = clock();
		for (int j = 0; j < 1000000; j++)
		{
			nEncertsResultat = nEncerts(apostes, resultats);
		}
		timeNoOrdenat = clock() - timeNoOrdenat;
		tempsAcumulatNoOrdenat += (float)timeNoOrdenat / CLOCKS_PER_SEC;
	}

	cout << "Comment :=>> Temps per realitzar la cerca ordenada: " << tempsAcumulatOrdenat << endl;
	cout << "Comment :=>> Temps per realitzar la cerca no ordenada: " << tempsAcumulatNoOrdenat << endl;
	if (tempsAcumulatOrdenat < (FACTOR_EFICIENCIA * tempsAcumulatNoOrdenat))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		cout << "Comment :=>> S'esperava una major reduccio del temps al realitzar la cerca ordenada" << endl;
		reduccio += 2.0;
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}


int main()
{
	float grade = 10.0;

	grade -= testNEncertsNoOrdenat();
	grade -= testNEncertsOrdenat();
	grade -= testEficienciaOrdenat();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}