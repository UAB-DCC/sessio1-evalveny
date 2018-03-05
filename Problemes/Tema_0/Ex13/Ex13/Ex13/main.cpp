#include <stdio.h>
#include <iostream>
#include "ParitatParell.h"

using namespace std;

void mostraVector(int v[], int longitud)
{
	cout << "Comment :=>>" << "[";
	if (longitud > 0)
	{
		cout << v[0];
	}
	for (int i = 1; i < longitud; i++)
		cout << "," << v[i];
	cout << "]" << endl;
}

float testBitParitatParell()
{
	float reduccio = 0.0;

	const int NUMTRAMES = 5;
	int trama[NUMTRAMES][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },{ 1, 0, 1, 0, 0, 0, 1, 1 },{ 1, 1, 0, 1, 0, 0, 1, 1 },{ 1, 1, 1, 1, 1, 1, 1, 1 },{ 1, 0, 0, 1, 0, 0, 1, 0 } };
	bool correcte[NUMTRAMES] = { true,true,false,true,false };

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test bit Paritat" << endl;
	cout << "Comment :=>> =========================" << endl;

	for (int i = 0; i < NUMTRAMES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Paraula a verificar: " << endl;
		mostraVector(trama[i], 8);
		if (bitParitatParell(trama[i]))
		{
			cout << "Comment :=>> Resultat obtingut: TRUE" << endl;
			if (!correcte[i])
			{
				cout << "Comment :=>> ERROR. S'esperava: FALSE" << endl;
				reduccio += 2;
			}
			else
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
		}
		else
		{
			cout << "Comment :=>> Resultat obtingut: FALSE" << endl;
			if (correcte[i])
			{
				cout << "Comment :=>> ERROR. S'esperava: TRUE" << endl;
				reduccio += 2;
			}
			else
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	return reduccio;
}


int main()
{
	float grade = 10.0;

	grade -= testBitParitatParell();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}