//
//  TestFuncionsRepas.cpp
//  Test funcions repàs
//

#include <stdio.h>

#include <iostream>
#include <sstream>

#include "TestFuncionsRepas.h"
#include "DiaGregoria.h"
#include "Recorreguts.h"

using namespace std;

// test exercici 1
bool TestFuncionsRepas::testBitParitatParell ()
{
    bool valid = true;
	const int numeroTrames = 4;
	int trama[4][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 0, 1, 0, 0, 0, 1, 1 }, { 1, 1, 0, 1, 0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 } };
	bool correcte[4] = {true,true,false,true};

	for (int i = 0; i < numeroTrames; i++)
	{
	    valid = valid && (bitParitatParell(trama[i]) == correcte[i]);
	}
	return valid;
}

// tests exerici 2
bool TestFuncionsRepas::testLlegeixDia ()
{
    bool valid = true;

	DiaGregoria diaG;
	streambuf* orig = std::cin.rdbuf();
	istringstream input("13\n9\n2014");
	cin.rdbuf(input.rdbuf());
	llegeixDia(diaG);
	cin.rdbuf(orig);
	cout << diaG.dia << "/" << diaG.mes << "/" << diaG.any << "\n";
	return valid;
}

bool TestFuncionsRepas::testEsTraspas ()
{
    bool valid = true;

	const int A = 5;
	DiaGregoria anys[A] = { { 1, 1, 1996 }, { 1, 1, 1900 }, { 1, 1, 2000 }, { 1, 1, 1997 }, { 1, 1, 2004 } };
	bool traspas[A] = {true, false, true, false, true};

	for (int i = 0; i < A; i++)
	{
		valid = valid && (esTraspas(anys[i]) == traspas[i]);
	}
	return valid;
}

bool TestFuncionsRepas::testEsValid ()
{
    bool valid = true;

	const int A = 6;
	DiaGregoria diaG[A] = { { 29, 2, 1996 }, { 29, 2, 1900 }, { -1, 1, 2000 }, { 31, 12, 1997 }, { 1, 1, 2004 }, {31, 4, 1997} };
	bool validG[A] = { true, false, false, true, true, false };

	for (int i = 0; i < A; i++)
	{
		valid = valid && (esValid(diaG[i]) == validG[i]);
	}
	return valid;
}

bool TestFuncionsRepas::testTotalDies()
{
    bool valid = true;

	const int A = 3;
	DiaGregoria dia[A] = { { 29, 2, 1996 }, { 30, 5, 1900 }, { 31, 12, 2000 } };
	int dies[A] = { 728718, 693745, 730485 };

	for (int i = 0; i < A; i++)
	{
		//cout << totalDies(dia[i]) << endl;
		valid = valid && (totalDies(dia[i]) == dies[i]);
	}
	return valid;
}

bool TestFuncionsRepas::testDiferenciaDies()
{
    bool valid = true;

	const int A = 3;
	DiaGregoria dia[A] = { { 29, 2, 1996 }, { 30, 5, 1900 }, { 31, 12, 2000 } };
	int afegeix[A] = { 1, 1157, 1 };
	DiaGregoria diaNou[A] = { { 1, 3, 1996 }, { 31, 7, 1903 }, { 1, 1, 2001 } };

	for (int i = 0; i < A; i++)
	{
		int dies1 = totalDies(dia[i]);
		int dies2 = totalDies(diaNou[i]);
		//cout << (dies2 - dies1) << endl;
		valid = valid && ((dies2 - dies1) == afegeix[i]);
	}
	return valid;
}

bool TestFuncionsRepas::testMesFrequent()
{
    bool valid = true;

	const int A = 3;
	const int N = 5;
	DiaGregoria dates[A][N] = { { { 29, 2, 1996 }, { 30, 5, 1900 }, { 31, 12, 2000 }, { 25, 5, 1910 }, { 10, 6, 1900 }},
								{ { 29, 1, 1996 }, { 30, 1, 1900 }, { 31, 1, 2000 }, { 25, 1, 1910 }, { 10, 1, 1900 }},
								{ { 29, 12, 1996 }, { 30, 12, 1900 }, { 31, 11, 2000 }, { 25, 5, 1910 }, { 10, 6, 1900 }}};
	int mesos[A] = { 5, 1, 12 };

	for (int i = 0; i < A; i++)
	{
		int mes = mesFrequent(dates[i], N);
		//cout << (dies2 - dies1) << endl;
		valid = valid && (mes == mesos[i]);
	}
	return valid;
}


// test exercici 3
bool TestFuncionsRepas::testUneixOrdenadament()
{
    bool valid = true;
	const int L = 4;
	const int M = 5;
	const int N = 6;
	const int O = 11;

	int llista1[L][M] = { { 1, 3, 5, 6, 9 }, { 1, 2, 3, 4, 5 }, { 7, 8, 9, 10, 11 }, { 1, 3, 5, 7, 9 } };
	int llista2[L][N] = { { 2, 4, 6, 7, 8, 13 }, { 6, 7, 8, 9, 10, 11 }, { 1, 2, 3, 4, 5, 6 }, { 2, 4, 6, 8, 10, 12 } };
	int llistaUnio[L][O];
	int llistaUnioCalculat[L][O] = {
		{ 1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 13 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 } };

	for (int l = 0; l < L; l++)
	{
		uneixOrdenadament(llista1[l], M, llista2[l], N, llistaUnio[l], O);
		for (int m = 0; m < O ; m++) {
			//cout << llistaUnio[l][m] << " ";
			valid = valid && (llistaUnio[l][m] == llistaUnioCalculat[l][m]);
		}
		//cout << endl;
	}
	return valid;
}

// test exercici 4
bool TestFuncionsRepas::testCercaPosicio()
{
    bool valid = true;

	const int L = 5;
	const int K = 8;
	int llista[K] = { 1, 2, 3, 4, 5, 5, 6, 7 };
	int valor[L] = { 1, 0, 9, 4, 6};
	int posicio[L] = { 1, 0, 8, 4, 7};

	for (int i = 0; i < L; i++)
	{
		//cout << valor[i] << " " << posicio[i] << endl;
		valid = valid && (cercaPosicio(llista, K, valor[i]) == posicio[i]);
	}
	return valid;
}

bool TestFuncionsRepas::testAfegeixOrdenadament()
{
    bool valid = true;

	const int L = 5;
	const int K = 8;
	int llistaFinal[L][K + 1] = {
		{ 1, 1, 2, 3, 4, 5, 5, 6, 7 },
		{ 0, 1, 2, 3, 4, 5, 5, 6, 7 },
		{ 1, 2, 3, 4, 5, 5, 6, 7, 9 },
		{ 1, 2, 3, 4, 4, 5, 5, 6, 7 },
		{ 1, 2, 3, 4, 5, 5, 6, 6, 7 } };
	int valor[L] = { 1, 0, 9, 4, 6 };

	for (int i = 0; i < L; i++)
	{
		int llista[K + 1] = { 1, 2, 3, 4, 5, 5, 6, 7, 0 };
		afegeixOrdenadament(llista, K, valor[i]);
		for (int j = 0; j < K + 1; j++) {
			cout << llista[j];
			valid = valid && (llista[j] == llistaFinal[i][j]);
		}
		cout << endl;
	}
	return valid;
}

bool TestFuncionsRepas::testUneixOrdenadament2()
{
    bool valid = true;

	const int L = 4;
	const int M = 5;
	const int N = 6;
	const int O = 11;

	int llista1[L][M] = { { 1, 3, 5, 6, 9 }, { 1, 2, 3, 4, 5 }, { 7, 8, 9, 10, 11 }, { 1, 3, 5, 7, 9 } };
	int llista2[L][N] = { { 4, 2, 8, 7, 6, 13 }, { 11, 10, 9, 8, 7, 6 }, { 6, 5, 3, 4, 2, 1 }, { 2, 4, 6, 8, 10, 12 } };
	int llistaUnio[L][O];
	int llistaUnioCalculat2[L][O] = {
		{ 1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 13 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 } };

	for (int l = 0; l < L; l++)
	{
		uneixOrdenadament2(llista1[l], M, llista2[l], N, llistaUnio[l], O);
		for (int m = 0; m < O; m++) {
			//cout << llistaUnio[l][m] << " ";
			valid = valid && (llistaUnio[l][m] == llistaUnioCalculat2[l][m]);
		}
		//cout << endl;
	}
	return valid;
}

// test exercici 5
bool TestFuncionsRepas::testEsSimetrica()
{
    bool valid = true;
	const int L = 2;
	int matriu[L][N][N] = {
		{ { 1, 2, 8, 3 }, { 2, 0, 5, 7 }, { 8, 5, 0, 1 }, { 3, 7, 1, 7 } },
		{ { 1, 2, 8, 3 }, { 2, 0, 5, 7 }, { 8, 5, 0, 1 }, { 3, 7, 3, 7 } } };
	bool simetrica[L] = { true, false };
	for (int l = 0; l < L; l++)
	{
		valid = valid && (esSimetrica(matriu[l]) == simetrica[l]);
	}
	return valid;
}
