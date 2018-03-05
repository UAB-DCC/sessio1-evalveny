// ex3_2ab.cpp: define el punto de entrada de la aplicación de consola.
//
/*
Proves:
*primera
Numerador:1
Denominador:2
Numerador:4
Denominador:8
Numerador:3
Denominador:6
Numerador:8
Denominador:2
Numerador:1
Denominador:3
#5.83333#3360#576#0.166667#96#576#-4.83333#-2784#576#1.5#288#192#

*segona
Numerador:2
Denominador:1
Numerador:5
Denominador:0
Numerador:6
Denominador:0
Numerador:7
Denominador:0
Numerador:8
Denominador:0
#No#

*tercera
Numerador:2
Denominador:1
Numerador:3
Denominador:1
Numerador:4
Denominador:0
Numerador:3
Denominador:0
Numerador:5
Denominador:0
#5#5#1#6#6#1#-1#-1#1#0.666667#2#3#

cout << "#" << suma.decimal() << "#" << suma.getNumerador() << "#" << suma.getDenominador() << "#" << producte.decimal() << "#" << producte.getNumerador() << "#" << producte.getDenominador() << "#" << resta.decimal() << "#" << resta.getNumerador() << "#" << resta.getDenominador() << "#" << divisio.decimal() << "#" << divisio.getNumerador() << "#" << divisio.getDenominador() << "#";
int numerador[NPROVES][MAXMIDA] =
{
{ 1, 4, 3, 8, 1 },
{ 2, 5, 6, 7, 8 },
{ 2, 3, 4, 3, 5 }
};
int denominador[NPROVES][MAXMIDA] =
{
{ 2, 8, 6, 2, 3 },
{ 1, 0, 0, 0, 0 },
{ 1, 1, 0, 0, 0 }
};
bool valid[NPROVES][MAXMIDA] =
{
{true,true,true,true,true},
{true,false,false,false,false},
{true,true,false,false,false}
};
*/
/*
#include "Racional.h"

#include <iostream>
using namespace std;

int main()
{
	const int N = 5;
	NombreRacional nR[N];
	int numerador, denominador;

	for (int i = 0; i < N; i++)
	{
		cout << "Numerador:";
		cin >> numerador;
		cout << "Denominador:";
		cin >> denominador;
		nR[i].setNumerador(numerador);
		nR[i].setDenominador(denominador);
	}

	int numCorrectes = 0;
	int primCorrecte;
	int i = 0;
	do
	{
		if (nR[i].esValid())
		{
			if (numCorrectes == 0)
			{
				primCorrecte = i;
			}
			numCorrectes++;
		}
		i++;
	} while ((numCorrectes < 2) && (i < N));

	if (numCorrectes > 1)
	{
		NombreRacional suma;
		NombreRacional resta;
		NombreRacional producte;
		NombreRacional divisio;
		suma = nR[primCorrecte];
		resta = nR[primCorrecte];
		producte = nR[primCorrecte];
		divisio = nR[primCorrecte];
		for (int j = primCorrecte + 1; j < N; j++)
		{
			if (nR[j].esValid())
			{
				suma.suma(nR[j]);
				resta.resta(nR[j]);
				producte.multiplica(nR[j]);
				divisio.divideix(nR[j]);
			}
		}
		cout << "#" << suma.decimal() << "#" << suma.getNumerador() << "#" << suma.getDenominador() << "#" << producte.decimal() << "#" << producte.getNumerador() << "#" << producte.getDenominador() << "#" << resta.decimal() << "#" << resta.getNumerador() << "#" << resta.getDenominador() << "#" << divisio.decimal() << "#" << divisio.getNumerador() << "#" << divisio.getDenominador() << "#";
	}
	else
	{
		cout << "#No#";
	}

	return 0;
}
*/
//#include "Racional.h"
#include "Operacions.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

const int MAXVECTOR = 5;
const int NPROVES = 5;
const float EPSILON = 0.001;


float testVectorNombreRacional()
{
	int numerador[NPROVES][MAXVECTOR] =
	{
		{ 1, 4, 3, 8, 1 },
		{ 2, 5, 6, 7, 8 },
		{ 2, 3, 4, 3, 5 },
		{ 3, 5, 8, 2, 1 },
		{ 7, 2, 4, 1, 9 }
	};

	int denominador[NPROVES][MAXVECTOR] =
	{
		{ 2, 8, 6, 2, 3 },
		{ 1, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 0 },
		{ 4, 6, 8, 9, 2 },
		{ 1, 2, 4, 5, 3 }
	};

	bool valid[NPROVES]=
	{ true,false,true,true,true };

	NombreRacional vNomRac[NPROVES][MAXVECTOR];
	//Inicialitzem vector Nombres Racionals
	for (int p = 0; p < NPROVES; p++)
	{
		for (int n = 0; n < MAXVECTOR; n++)
		{
			vNomRac[p][n].setNumerador(numerador[p][n]);
			vNomRac[p][n].setDenominador(denominador[p][n]);
		}
	}
	
	int resSumaNumerador[NPROVES] =
	{ 3360, 0, 5, 11424, 1464 };
	int resSumaDenominador[NPROVES] =
	{ 576, 0, 1, 3456, 120 };
	float resSumaDecimal[NPROVES]=
	{ 5.83333,0,5,3.30556,12.2 };

	int resRestaNumerador[NPROVES]=
	{ -2784, 0, -1, -6240, 216 };
	int resRestaDenominador[NPROVES]=
	{ 576, 0, 1, 3456, 120 };
	float resRestaDecimal[NPROVES]=
	{ -4.83333, 0, -1, -1.80556,1.8 };

	int resProducteNumerador[NPROVES]=
	{ 96, 0, 6, 240, 504 };
	int resProducteDenominador[NPROVES]=
	{ 576, 0, 1, 3456, 120 };
	float resProducteDecimal[NPROVES]=
	{ 0.166667, 0, 6, 0.0694444, 4.2 };

	int resDivisioNumerador[NPROVES]=
	{ 288, 0, 2, 2592, 840 };
	int resDivisioDenominador[NPROVES]=
	{ 192, 0, 3, 320, 72 };
	float resDivisioDecimal[NPROVES]=
	{ 1.5, 0, 0.666667, 8.1, 11.6667 };

	float punts = 0.0;

	cout << endl;
	cout << "Comment :=>> Iniciant test OPERAR Vector 5 NombreRacional" << endl;
	cout << "Comment :=>> ============================================" << endl;
	
	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p  << endl;
		cout << "Comment :=>> 5 Valors Vector Racional (Numerador,Denominador)" << endl;
		bool correcteSetGet = true;
		for (int n = 0; n < MAXVECTOR; n++)
		{
			cout << "Comment :=>>(" << vNomRac[p][n].getNumerador()<<","<<vNomRac[p][n].getDenominador() <<")" << endl;			
			if ((vNomRac[p][n].getNumerador() != numerador[p][n]) || (vNomRac[p][n].getDenominador() != denominador[p][n]))
			{
				correcteSetGet = false;
			}
		}
		if (correcteSetGet)
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << endl;
			for (int n = 0; n < MAXVECTOR; n++)
			{
				cout << "Comment :=>>(" << numerador[p][n] << "," << denominador[p][n] <<")" << endl;				
			}			
		}
		
		cout << "Comment :=>> TEST operar()" << endl;
		bool correcteOperar = true;
		NombreRacional nRSuma, nRProducte,nRDivisio,nRResta ;
		correcteOperar = operar(vNomRac[p], nRSuma, nRResta, nRProducte, nRDivisio,MAXVECTOR);
		
		cout << "Comment :=>> Operar ha donat com a resultat:" << endl;
		if (correcteOperar)
		{
			cout << "Comment :=>> VALID" << endl;
			if (valid[p])
			{
				cout << "Comment :=>> CORRECTE VALID" << endl;
				cout << "Comment :=>> OPERACIONS Resultat (Numerador,Denominador):Decimal" << endl;
				cout << "Comment :=>> TEST SUMA" << endl;
				cout << "Comment :=>> (" << nRSuma.getNumerador() << "," << nRSuma.getDenominador() << "):" << nRSuma.decimal() << endl;
				float kk = nRSuma.decimal();
				if ( (resSumaNumerador[p]== nRSuma.getNumerador()) && (resSumaDenominador[p] == nRSuma.getDenominador())&&
					 (resSumaDecimal[p]<=nRSuma.decimal()+EPSILON) && (resSumaDecimal[p] >= nRSuma.decimal() - EPSILON))
				{
					cout << "Comment :=>> CORRECTE SUMA" << endl;
					punts += 0.5;
				}
				else
				{
					cout << "Comment :=>> ERROR SUMA. S'esperava:" << endl;
					cout << "Comment :=>> (" << resSumaNumerador[p] << "," << resSumaDenominador[p] << "):" << resSumaDecimal[p] << endl;
				}

				cout << "Comment :=>> TEST RESTA" << endl;
				cout << "Comment :=>> (" << nRResta.getNumerador() << "," << nRResta.getDenominador() << "):" << nRResta.decimal() << endl;
				kk = nRResta.decimal();
				if ((resRestaNumerador[p] == nRResta.getNumerador()) && (resRestaDenominador[p] == nRResta.getDenominador()) && 
					(resRestaDecimal[p] <= nRResta.decimal() + EPSILON) && (resRestaDecimal[p] >= nRResta.decimal() - EPSILON))
				{
					cout << "Comment :=>> CORRECTE RESTA" << endl;
					punts += 0.5;
				}
				else
				{
					cout << "Comment :=>> ERROR RESTA. S'esperava:" << endl;
					cout << "Comment :=>> (" << resRestaNumerador[p] << "," << resRestaDenominador[p] << "):" << resRestaDecimal[p] << endl;
				}
				cout << "Comment :=>> TEST PRODUCTE" << endl;
				cout << "Comment :=>> (" << nRProducte.getNumerador() << "," << nRProducte.getDenominador() << "):" << nRProducte.decimal()<< endl;
				kk = nRProducte.decimal();
				if ((resProducteNumerador[p] == nRProducte.getNumerador()) && (resProducteDenominador[p] == nRProducte.getDenominador()) && 
					(resProducteDecimal[p] <= nRProducte.decimal() + EPSILON) && (resProducteDecimal[p] >= nRProducte.decimal() - EPSILON))
				{
					cout << "Comment :=>> CORRECTE PRODUCTE" << endl;
					punts += 0.5;
				}
				else
				{
					cout << "Comment :=>> ERROR PRODUCTE. S'esperava:" << endl;
					cout << "Comment :=>> (" << resProducteNumerador[p] << "," << resProducteDenominador[p] << "):" << resProducteDecimal[p] << endl;
				}
				cout << "Comment :=>> TEST DIVISIO" << endl;
				cout << "Comment :=>> (" << nRDivisio.getNumerador() << "," << nRDivisio.getDenominador() << "):" << nRDivisio.decimal() << endl;
				kk = nRDivisio.decimal();
				if ((resDivisioNumerador[p] == nRDivisio.getNumerador()) && (resDivisioDenominador[p] == nRDivisio.getDenominador()) && 
					(resDivisioDecimal[p] <= nRDivisio.decimal() + EPSILON) && (resDivisioDecimal[p] >= nRDivisio.decimal() - EPSILON))
				{
					cout << "Comment :=>> CORRECTE DIVISIO" << endl;
					punts += 0.5;
				}
				else
				{
					cout << "Comment :=>> ERROR DIVISIO. S'esperava:" << endl;
					cout << "Comment :=>> (" << resDivisioNumerador[p] << "," << resDivisioDenominador[p] << "):" << resDivisioDecimal[p] << endl;
				}


			}
		}
		else
		{
			cout << "Comment :=>> NO VALID" << endl;
			if (!valid[p])
			{
				cout << "Comment :=>> CORRECTE NO VALID" << endl;
				punts += 2;
			}
			else
			{
				cout << "Comment :=>> ERROR NO VALID. S'esperava" << endl;
				cout << "Comment :=>> VALID" << endl;
				cout << "Comment :=>> OPERACIONS Resultat (Numerador,Denominador):Decimal" << endl;
				cout << "Comment :=>> TEST SUMA" << endl;
				cout << "Comment :=>> (" << resSumaNumerador[p] << "," << resSumaDenominador[p] << "):" << resSumaDecimal[p] << endl;
				cout << "Comment :=>> TEST RESTA" << endl;
				cout << "Comment :=>> (" << resRestaNumerador[p] << "," << resRestaDenominador[p] << "):" << resRestaDecimal[p] << endl;
				cout << "Comment :=>> TEST PRODUCTE" << endl;
				cout << "Comment :=>> (" << resProducteNumerador[p] << "," << resProducteDenominador[p] << "):" << resProducteDecimal[p] << endl;
				cout << "Comment :=>> TEST DIVISIO" << endl;
				cout << "Comment :=>> (" << resDivisioNumerador[p] << "," << resDivisioDenominador[p] << "):" << resDivisioDecimal[p] << endl;
			}

		}			
	}
	return punts;
}

int main()
{
	float grade = 0.0;

	grade += testVectorNombreRacional();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}