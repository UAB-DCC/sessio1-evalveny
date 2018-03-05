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

*/

#include "Racional.h"

#include <iostream>
using namespace std;



float testNombreRacional()
{
	const int NPROVES = 5;

	int numerador[NPROVES]=
	{1, 4, 3, 8, 1};
	int denominador[NPROVES] =
	{ 2, 8, 6, 2, 0 };
	
	bool valid[NPROVES]= 
	{true,true,true,true,false};

	int resSumaNumerador[NPROVES]=
	{ 16, 48, 54, 0, 0 };
	int resSumaDenominador[NPROVES]=
	{16, 48, 12, 0, 0 };
	float resSumaDecimal[NPROVES]=
	{ 1,1,4.5,0,0 };		
	
	int resRestaNumerador[NPROVES] =
	{ 0, 0, -42, 0, 0 };
	int resRestaDenominador[NPROVES]=
	{ 16, 48, 12, 0, 0 };
	float resRestaDecimal[NPROVES] =
	{ 0, 0, -3.5, 0,0 };
	
	int resProducteNumerador[NPROVES] =
	{ 4, 12, 24, 0, 0 };
	int resProducteDenominador[NPROVES] =
	{ 16, 48, 12, 0, 0 };
	float resProducteDecimal[NPROVES] =
	{ 0.25, 0.25, 2, 0, 0 };
	
	int resDivisioNumerador[NPROVES] =
	{ 8, 24, 6, 0, 0 };
	int resDivisioDenominador[NPROVES] =
	{ 8, 24, 48, 0, 0 };
	float resDivisioDecimal[NPROVES]=
	{ 1, 1, 0.125, 0, 0 };
	
	float punts = 0.0;

	NombreRacional nR1, nR2;
	
	cout << endl;
	cout << "Comment :=>> Iniciant test NombreRacional" << endl;
	cout << "Comment :=>> ============================" << endl;

	nR1.setNumerador(numerador[0]);
	nR1.setDenominador(denominador[0]);
	if ((numerador[0] == nR1.getNumerador()) && (denominador[0] == nR1.getDenominador()))
	{
		punts += 0.1;
	}
	if (nR1.esValid() == valid[0])
	{
		punts += 0.1;
	}

	for (int p = 1; p < NPROVES; p++)
	{
		nR1.setNumerador(numerador[p-1]);
		nR1.setDenominador(denominador[p-1]);
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p-1 << endl;
		cout << "Comment :=>> TEST get(set)Numerador() get(set)Denominador()" << endl;

		cout << "Comment :=>> Racional1:(Numerador: " <<nR1.getNumerador() <<", Denominador:" <<nR1.getDenominador() <<")"<< endl;
		if ( (numerador[p-1]== nR1.getNumerador()) && (denominador[p-1] == nR1.getDenominador()) )
		{
			cout << "Comment :=>> CORRECTE" << endl;			
		}
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << endl;
			cout << "Comment :=>> Racional1:(Numerador: " << numerador[p - 1] <<", Denominador:" << denominador[p - 1] << ")" << endl;
		}
		nR2.setNumerador(numerador[p]);
		nR2.setDenominador(denominador[p]);
		cout << "Comment :=>> Racional2:(Numerador: " << nR2.getNumerador() <<", Denominador:" << nR2.getDenominador() << ")" << endl;
		if ((numerador[p] == nR2.getNumerador()) && (denominador[p] == nR2.getDenominador()) )
		{
			cout << "Comment :=>> CORRECTE" << endl;
			punts += 0.1;
		}
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << endl;
			cout << "Comment :=>> Racional2:(Numerador: " << numerador[p] << ", Denominador:" << denominador[p] << ")" << endl;
		}
		cout << "Comment :=>> TEST esValid()" << endl;
		cout << "Comment :=>> Racional1:";
		if (nR1.esValid()) cout << "ES VALID"<<endl;
		else cout << "NO ES VALID"<<endl;
		if (nR1.esValid() == valid[p])
		{
			cout << "Comment :=>> RESULTAT esValid() Racional1 CORRECTE" << endl;			
		}
		else
		{
			cout << "Comment :=>> RESULTAT esValid() Racional1 ERROR. S'esperava" << endl;
			cout << "Comment :=>> Racional1:";
			if (valid[p - 1]) cout << "ES VALID" << endl;
			else cout << "NO ES VALID" << endl;			
		}
		cout << "Comment :=>> Racional2:";
		if (nR2.esValid()) cout << "ES VALID" <<endl;
		else cout << "NO ES VALID" <<endl;
		if (nR2.esValid() == valid[p])
		{
			cout << "Comment :=>> RESULTAT esValid() Racional2 CORRECTE" <<endl;
			punts += 0.1;
		}
		else
		{
			cout << "Comment :=>> RESULTAT esValid() Racional2 ERROR. S'esperava" << endl;
			cout << "Comment :=>> Racional2:";
			if (valid[p]) cout << "ES VALID" << endl;
			else cout << "NO ES VALID" << endl;
		}
		if (valid[p - 1] && valid[p ])
		{
			cout << "Comment :=>> TEST suma" << endl;
			nR1.suma(nR2);
			cout << "Comment :=>> Suma (Numerador:" << nR1.getNumerador() <<",Denominador:" << nR1.getDenominador() <<"Decimal:" << nR1.decimal()<<")"<<endl;
			if ((nR1.getNumerador() == resSumaNumerador[p - 1]) && (nR1.getDenominador() == resSumaDenominador[p - 1]) && (nR1.decimal() == resSumaDecimal[p - 1]))
			{
				cout << "Comment :=>> CORRECTE" << endl;
				punts += 0.75;
			}
			else
			{
				cout << "Comment :=>> ERROR. S'esperava:" << endl;
				cout << "Comment :=>> Suma (Numerador:" << resSumaNumerador[p-1] << ",Denominador:" << resSumaDenominador[p-1] << "Decimal:" << resSumaDecimal[p-1] << ")" << endl;
			}

			cout << "Comment :=>> TEST PRODUCTE" << endl;
			nR1.setNumerador(numerador[p - 1]);
			nR1.setDenominador(denominador[p - 1]);
			nR1.multiplica(nR2);
			cout << "Comment :=>> Producte (Numerador:" << nR1.getNumerador() << ",Denominador:" << nR1.getDenominador() << "Decimal:" << nR1.decimal() << ")" << endl;
			if ((nR1.getNumerador() == resProducteNumerador[p - 1]) && (nR1.getDenominador() == resProducteDenominador[p - 1]) && (nR1.decimal() == resProducteDecimal[p - 1]))
			{
				cout << "Comment :=>> CORRECTE" << endl;
				punts += 0.75;
			}
			else
			{
				cout << "Comment :=>> ERROR. S'esperava:" << endl;
				cout << "Comment :=>> Producte (Numerador:" << resProducteNumerador[p - 1] << ",Denominador:" << resProducteDenominador[p - 1] << "Decimal:" << resProducteDecimal[p - 1] << ")" << endl;
			}
			
			cout << "Comment :=>> TEST RESTA" << endl;
			nR1.setNumerador(numerador[p - 1]);
			nR1.setDenominador(denominador[p - 1]);
			nR1.resta(nR2);
			cout << "Comment :=>> Resta (Numerador:" << nR1.getNumerador() << ",Denominador:" << nR1.getDenominador() << "Decimal:" << nR1.decimal() << ")" << endl;
			if ((nR1.getNumerador() == resRestaNumerador[p - 1]) && (nR1.getDenominador() == resRestaDenominador[p - 1]) && (nR1.decimal() == resRestaDecimal[p - 1]))
			{
				cout << "Comment :=>> CORRECTE" << endl;
				punts += 0.75;
			}
			else
			{
				cout << "Comment :=>> ERROR. S'esperava:" << endl;
				cout << "Comment :=>> Resta (Numerador:" << resRestaNumerador[p - 1] << ",Denominador:" << resRestaDenominador[p - 1] << "Decimal:" << resRestaDecimal[p - 1] << ")" << endl;
			}


			cout << "Comment :=>> TEST DIVISIO" << endl;
			nR1.setNumerador(numerador[p - 1]);
			nR1.setDenominador(denominador[p - 1]);
			nR1.divideix(nR2);
			cout << "Comment :=>> Divisio (Numerador:" << nR1.getNumerador() << ",Denominador:" << nR1.getDenominador() << "Decimal:" << nR1.decimal() << ")" << endl;
			if ((nR1.getNumerador() == resDivisioNumerador[p - 1]) && (nR1.getDenominador() == resDivisioDenominador[p - 1]) && (nR1.decimal() == resDivisioDecimal[p - 1]))
			{
				cout << "Comment :=>> CORRECTE" << endl;
				punts += 0.75;
			}
			else
			{
				cout << "Comment :=>> ERROR. S'esperava:" << endl;
				cout << "Comment :=>> Resta (Numerador:" << resDivisioNumerador[p - 1] << ",Denominador:" << resDivisioDenominador[p - 1] << "Decimal:" << resDivisioDecimal[p - 1] << ")" << endl;
			}

		}
		else 
		{
			cout << "Comment :=>> TEST SUMA, PRODUCTE; RESTA; DIVISIO NO ES POT FER" << endl;				
		}
			
	}	

	return punts;
}

int main()
{
	float grade = 0.0;

	grade += testNombreRacional();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}

