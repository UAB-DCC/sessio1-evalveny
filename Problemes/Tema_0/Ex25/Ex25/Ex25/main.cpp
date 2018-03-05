
#include "DiaGregoria.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

void escriuDiaGregoria(DiaGregoria& diaG)
{
	cout << "Comment :=>>" << "DIA:" <<diaG.dia << "/" << diaG.mes << "/" << diaG.any << "\n";
}

float testLlegeixDia()
{
	//1.5 punt
	//bool valid = true;
	float punts = 1.5;

	DiaGregoria diaG;
	streambuf* orig = std::cin.rdbuf();
	istringstream input("13\n9\n2014");
	cin.rdbuf(input.rdbuf());
	llegeixDia(diaG);
	cin.rdbuf(orig);
	escriuDiaGregoria(diaG);
	//return valid;
	return punts;
}

float testEsTraspas()
{
	//2 punts
	float punts = 0.0;

	const int A = 5;
	DiaGregoria anys[A] = { { 1, 1, 1996 },{ 1, 1, 1900 },{ 1, 1, 2000 },{ 1, 1, 1997 },{ 1, 1, 2004 } };
	bool traspas[A] = { true, false, true, false, true };

	for (int i = 0; i < A; i++)
	{
		cout << "Comment :=>> ------------------" << endl;
		cout << "Comment :=>> Test Anys Traspas:" <<i+1 << endl;
		cout << "Comment :=>> ------------------" << endl;
		cout << "Comment :=>> DIA Entrada:";
		escriuDiaGregoria(anys[i]);
		if (esTraspas(anys[i]))
		{
			cout << "Comment :=>> RESULTAT OBTINGUT: SI es TRASPAS" << endl;
			if (traspas[i])
			{
				cout << "Comment :=>> RESULTAT CORRECTE SI es TRASPAS" << endl;
				punts += 0.4;
			}
			else
			{
				cout << "Comment :=>> RESULTAT INCORRECTE, RESULTAT CORRECTE: NO es TRASPAS" << endl;
			}
		}
		else
		{
			cout << "Comment :=>> RESULTAT OBTINGUT: NO es TRASPAS" << endl;
			if (traspas[i])
			{
				cout << "Comment :=>> RESULTAT INCORRECTE, RESULTAT CORRECTE ES:SI es TRASPAS" << endl;				
			}
			else
			{
				cout << "Comment :=>> RESULTAT CORRECTE NO es TRASPAS" << endl;
				punts += 0.4;
			}

		}		
	}
	return punts;
}
float testEsValid()
{//2punts
	
	float punts = 0.0;

	const int A = 8;
	DiaGregoria diaG[A] = { { 29, 2, 1996 },{ 29, 2, 1900 },{ 0, 1, 2000 },{ 31, 12, 1997 },{ 1, 1, 2004 },{ 31, 4, 1997 },{ 30,4,2003 },{ 0,3,1703 } };
	bool validG[A] = { true, false, false, true, true, false, true,false };

	for (int i = 0; i < A; i++)
	{
		cout << "Comment :=>> ------------------" << endl;
		cout << "Comment :=>> Test DIA EsValid:" << i + 1 << endl;
		cout << "Comment :=>> ------------------" << endl;
		cout << "Comment :=>> DIA Entrada:";
		escriuDiaGregoria(diaG[i]);
		if (esValid(diaG[i]))
		{
			cout << "Comment :=>> RESULTAT OBTINGUT: DIA VALID" << endl;
			if (validG[i])
			{
				cout << "Comment :=>> RESULTAT CORRECTE DIA VALID" << endl;
				punts += 0.25;
			}
			else
			{
				cout << "Comment :=>> RESULTAT INCORRECTE, RESULTAT CORRECTE: DIA NO VALID" << endl;
			}
		}
		else
		{
			cout << "Comment :=>> RESULTAT OBTINGUT: DIA NO VALID" << endl;
			if (validG[i])
			{
				cout << "Comment :=>> RESULTAT INCORRECTE, RESULTAT CORRECTE: DIA VALID" << endl;
			}
			else
			{
				cout << "Comment :=>> RESULTAT CORRECTE DIA NO VALID" << endl;
				punts += 0.25;
			}
		}		
	}
	return punts;
}

float testTotalDies()
{//1.5 punts
	float punts = 0.0;

	const int A = 3;
	DiaGregoria dia[A] = { { 29, 2, 1996 },{ 30, 5, 1900 },{ 31, 12, 2000 } };
	int dies[A] = { 728718, 693745, 730485 };

	for (int i = 0; i < A; i++)
	{
		cout << "Comment :=>> ----------------" << endl;
		cout << "Comment :=>> Test TOTAL DIES:" << i + 1 << endl;
		cout << "Comment :=>> ----------------" << endl;
		cout << "Comment :=>> DIA Entrada:";
		escriuDiaGregoria(dia[i]);
		int numDies = totalDies(dia[i]);
		cout << "Comment :=>> RESULTAT OBTINGUT: TOTAL DIES:" <<numDies << endl;
		if (numDies == dies[i])
		{
			cout << "Comment :=>> RESULTAT OBTINGUT CORRECTE" << endl;			
			punts += 0.5;
		}
		else
		{
			cout << "Comment :=>> RESULTAT OBTINGUT ERRONI" << endl;
			cout << "Comment :=>> RESULTAT ESPERAT: TOTAL DIES:" <<dies[i] << endl;			
		}		
	}
	return punts;
}

float testDiferenciaDies()
{//1.5 punts
	float punts = 0.0;

	const int A = 3;
	DiaGregoria dia[A] = { { 29, 2, 1996 },{ 30, 5, 1900 },{ 31, 12, 2000 } };
	int afegeix[A] = { 1, 1157, 1 };
	DiaGregoria diaNou[A] = { { 1, 3, 1996 },{ 31, 7, 1903 },{ 1, 1, 2001 } };

	for (int i = 0; i < A; i++)
	{
		cout << "Comment :=>> ---------------------" << endl;
		cout << "Comment :=>> Test DIFERENCIA DIES:" << i + 1 << endl;
		cout << "Comment :=>> ---------------------" << endl;
		cout << "Comment :=>> DIA1 Entrada:";
		escriuDiaGregoria(dia[i]);
		cout << "Comment :=>> DIA2 Entrada:";
		escriuDiaGregoria(diaNou[i]);
		int dies1 = totalDies(dia[i]);
		int dies2 = totalDies(diaNou[i]);
		int resultat = (dies2 - dies1);
		cout << "Comment :=>> RESULTAT OBTINGUT: DIFERENCIA DIES:" << resultat << endl;
		if (resultat == afegeix[i])
		{
			cout << "Comment :=>> RESULTAT OBTINGUT CORRECTE" << endl;
			punts += 0.5;
		}
		else
		{
			cout << "Comment :=>> RESULTAT OBTINGUT ERRONI" << endl;
			cout << "Comment :=>> RESULTAT ESPERAT: DIFERENCIA DIES:" << afegeix[i] << endl;
		}		
	}
	return punts;
}

float testMesFrequent()
{//1.5 punts

	float punts = 0.0;

	const int A = 3;
	const int N = 5;
	DiaGregoria dates[A][N] = { { { 29, 2, 1996 },{ 30, 5, 1900 },{ 31, 12, 2000 },{ 25, 5, 1910 },{ 10, 6, 1900 } },
	{ { 29, 1, 1996 },{ 30, 1, 1900 },{ 31, 1, 2000 },{ 25, 1, 1910 },{ 10, 1, 1900 } },
	{ { 29, 12, 1996 },{ 30, 12, 1900 },{ 31, 11, 2000 },{ 25, 5, 1910 },{ 10, 6, 1900 } } };
	int mesos[A] = { 5, 1, 12 };

	for (int i = 0; i < A; i++)
	{
		cout << "Comment :=>> ------------------" << endl;
		cout << "Comment :=>> Test MES FREQUENT:" << i + 1 << endl;
		cout << "Comment :=>> ------------------" << endl;
		cout << "Comment :=>> DATAS Entrada:" << endl;
		for (int j = 0; j < N; j++)
		{
			escriuDiaGregoria(dates[i][j]);
		}

		int mes = mesFrequent(dates[i], N);
		cout << "Comment :=>> RESULTAT OBTINGUT: MES FREQUENT:" << mes << endl;
		//cout << (dies2 - dies1) << endl;
		if (mes == mesos[i])
		{
			cout << "Comment :=>> RESULTAT OBTINGUT CORRECTE" << endl;
			punts += 0.5;
		}
		else
		{
			cout << "Comment :=>> RESULTAT OBTINGUT ERRONI" << endl;
			cout << "Comment :=>> RESULTAT ESPERAT: MES FREQUENT:" << mesos[i] << endl;
		}
	}
	return punts;
}

float testGregoria()
{
	float punts = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test Gregoria" << endl;
	cout << "Comment :=>> ======================" << endl;

	cout << "Comment : = >>===================" << endl;
	cout << "Comment :=>> TEST 1: LLEGEIX DIA" << endl;
	cout << "Comment :=>> -------------------" << endl;
	float puntsAux=0;
	puntsAux = testLlegeixDia();//1.5 punts
	cout << "Comment :=>> -----------------------------------" << endl;
	cout << "Comment :=>> Punts Maxims: 1.5; Punts Obtinguts:" <<puntsAux <<endl;
	cout << "Comment :=>> -----------------------------------" << endl;
	punts += puntsAux;

	cout << "Comment :=>>=======================" << endl;
	cout << "Comment :=>> TEST 2: ES TRASPAS ANY" << endl;
	cout << "Comment :=>> ----------------------" << endl;
	puntsAux = testEsTraspas();//2 punts
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>> Punts Maxims: 2; Punts Obtinguts:" << puntsAux << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	punts += puntsAux;
	
	cout << "Comment :=>>=====================" << endl;
	cout << "Comment :=>> TEST 3: DIA ES VALID" << endl;
	cout << "Comment :=>> --------------------" << endl;
	puntsAux = testEsValid();//2 punts
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>> Punts Maxims: 2; Punts Obtinguts:" << puntsAux << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	punts += puntsAux;

	cout << "Comment :=>>===================" << endl;
	cout << "Comment :=>> TEST 4: TOTAL DIES" << endl;
	cout << "Comment :=>> ------------------" << endl;
	puntsAux = testTotalDies();//1.5punt
	cout << "Comment :=>> -----------------------------------" << endl;
	cout << "Comment :=>> Punts Maxims: 1.5; Punts Obtinguts:" << puntsAux << endl;
	cout << "Comment :=>> -----------------------------------" << endl;
	punts += puntsAux;
	
	cout << "Comment :=>>========================" << endl;
	cout << "Comment :=>> TEST 5: DIFERENCIA DIES" << endl;
	cout << "Comment :=>> -----------------------" << endl;
	puntsAux = testDiferenciaDies();//1.5 punt
	cout << "Comment :=>> -----------------------------------" << endl;
	cout << "Comment :=>> Punts Maxims: 1.5; Punts Obtinguts:" << puntsAux << endl;
	cout << "Comment :=>> -----------------------------------" << endl;
	punts += puntsAux;
	
	cout << "Comment :=>>=====================" << endl;
	cout << "Comment :=>> TEST 6: MES FREQUENT" << endl;
	cout << "Comment :=>> --------------------" << endl;
	puntsAux = testMesFrequent();//1.5 punts
	cout << "Comment :=>> -----------------------------------" << endl;
	cout << "Comment :=>> Punts Maxims: 1.5; Punts Obtinguts:" << puntsAux << endl;
	cout << "Comment :=>> -----------------------------------" << endl;
	punts += puntsAux;

	cout << "Comment :=>> -----------------------------------------------" << endl;
	
	return punts;
}
int main()
{
	float grade = 0.0;

	grade += testGregoria();//10 punts
	
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}