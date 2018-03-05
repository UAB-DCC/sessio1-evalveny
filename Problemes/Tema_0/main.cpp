#include "binari.h"
#include <iostream>

using namespace std;

void mostraBinari(int v[], int longitud)
{
	for (int i = 0; i < longitud; i++)
		cout << v[i];
	cout << endl;
}

int testConversioSenseSigne()
{
	const int N_PROVES = 6;
	const int MAX_BINARI = 16;
	int binari[N_PROVES][MAX_BINARI] = 
	{
		{0, 0, 0, 0}, 
		{1, 1, 1, 1}, 
		{0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0},
		{1, 0, 0, 0, 1, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	int longitud[N_PROVES] = {4, 4, 8, 8, 8, 16};
	int resultat[N_PROVES] = {0, 15, 85, 170, 139, 33023};

	float reduccio = 0.0;
	int valor;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de conversio sense signe" << endl;
	cout << "Comment :=>> ======================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i+1 << endl;
		cout << "Comment :=>> Numero binari a convertir: ";
		mostraBinari(binari[i], longitud[i]);
		valor = BinariADecimal(binari[i], longitud[i]);
		cout << "Comment :=>> Resultat obtingut: " << valor << endl;
		if (valor == resultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << resultat[i] << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6)
		reduccio = 6.0;
	return reduccio;
}

int testConversioAmbSigne()
{
	const int N_PROVES = 6;
	const int MAX_BINARI = 16;
	int binari[N_PROVES][MAX_BINARI] =
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	int longitud[N_PROVES] = { 4, 4, 8, 8, 8, 16 };
	int resultat[N_PROVES] = { 0, -1, 85, -86, -117, -32513 };

	float reduccio = 0.0;
	int valor;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de conversio amb signe" << endl;
	cout << "Comment :=>> ======================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Numero binari a convertir: ";
		mostraBinari(binari[i], longitud[i]);
		valor = BinariADecimalSigne(binari[i], longitud[i]);
		cout << "Comment :=>> Resultat obtingut: " << valor << endl;
		if (valor == resultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << resultat[i] << endl;
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

	grade -= testConversioSenseSigne();
	grade -= testConversioAmbSigne();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}