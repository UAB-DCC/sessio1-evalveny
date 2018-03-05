// Ex20.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"


#include <stdio.h>
#include <iostream>
#include "MatSimetrica.h"

using namespace std;

void mostraMatriu(int matriu[N][N])
{
	for (int i = 0; i < N; i++)
	{
		cout << "[";
		for (int j = 0; j < N; j++)
		{
			cout << matriu[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

int testEsSimetrica()
{
	float reduccio = 0.0;

	const int L = 2;
	int matriu[L][N][N] = {
		{ { 1, 2, 8, 3 },{ 2, 0, 5, 7 },{ 8, 5, 0, 1 },{ 3, 7, 1, 7 } },
		{ { 1, 2, 8, 3 },{ 2, 0, 5, 7 },{ 8, 5, 0, 1 },{ 3, 7, 3, 7 } } };
	bool simetrica[L] = { true, false };
	for (int l = 0; l < L; l++)
	{
		cout << "Comment :=>> TEST " << l + 1 << endl;
		cout << "Comment :=>> Matriu a dir si es Simetrica: " << endl;
		mostraMatriu(matriu[l]);
		if (esSimetrica(matriu[l]))
		{
			cout << "Comment :=>> Resultat obtingut: ES SIMETRICA" << endl;
			if (!simetrica[l])
			{
				reduccio -= 5.0;
				cout << "Comment :=>> ERROR. S'esperava: NO ES SIMETRICA" << endl;
			}
			else
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
		}
		else
		{
			cout << "Comment :=>> Resultat obtingut: NO ES SIMETRICA" << endl;
			if (simetrica[l])
			{
				reduccio -= 5;
				cout << "Comment :=>> ERROR. S'esperava: ES SIMETRICA" << endl;
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

int main(int argc, const char* argv[])
{
	float grade = 10.0;
	
	grade -= testEsSimetrica();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
