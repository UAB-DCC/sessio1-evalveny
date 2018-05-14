#include "Vector.h"
#include <iostream>
using namespace std;


bool comparaVectors(Vector& v, Punt* resultat, int longitud)
{
	bool iguals = (longitud == v.longitud());
	if (iguals)
	{
		int i = 0;
		while ((i < longitud) && iguals)
		{
			if (!(resultat[i] == v[i]))
				iguals = false;
			else
				i++;
		}
	}
	return iguals;
}

float testVector()
{
	float punts = 0.0;

	const int MAX_PROVES = 5;

	Punt resultat[MAX_PROVES][20] = {
		{ {9,9}, {8,8}, {7,7}, {6,6}, {5,5}, {4,4}, {3,3}, {2,2}, {1,1}, {0,0} },
		{ {9,9}, {8,8}, {7,7}, {6,6}, {5,5} },
		{ {9,9}, {8,8}, {7,7}, {6,6}, {5,5} },
		{ {9,9}, {8,8}, {7,7}, {6,6}, {5,5} },
		{ {9,9}, {8,8}, {7,7}, {6,6}, {5,5}, {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {14,14}, {13,13}, {12,12}, {11,11}, {10,10}, {15,15}, {16,16}, {17,17}, {18,18}, {19,19} }		
	};
	
	int longitudResultat[MAX_PROVES] = { 10, 5, 5, 5, 20};

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------" << endl;
	cout << "Comment :=>> Iniciant test VECTOR   " << endl;
	cout << "Comment :=>> -----------------------" << endl;
	cout << "Comment :=>>" << endl;
	
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------" << endl;
	cout << "Comment :=>> Creant Vector de Punts" << endl;
	
	Vector v;

	cout << "Comment :=>> Redimensionant Vector a 10 posicions                    " << endl;
	
	v.redimensiona(10);

	cout << "Comment :=>> Assignant valors a Vector de 10 posicions                           " << endl;
	cout << "Comment :=>> {9,9}, {8,8}, {7,7}, {6,6}, {5,5}, {4,4}, {3,3}, {2,2}, {1,1}, {0,0}" << endl;
	cout << "Comment :=>> --------------------------------------------------------------------" << endl;
	
	for (int i = 0; i < 10; i++)
	{
		v[i].setX(10 - (i + 1));
		v[i].setY(10 - (i + 1));
	}
		
	bool valid = comparaVectors(v, resultat[0], longitudResultat[0]);
	if (!valid)
	{
		cout << "Comment :=>> ERROR redimensionant i inicialitzant el vector" << endl;
		
	}
	else
	{
		cout << "Comment :=>> OK redimensionant i inicialitzant el vector" << endl;
		punts += 2;
	}
	cout << "Comment :=>> --------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Redimensionant Vector de 10 posicions a 5 posicions                                              " << endl;
	cout << "Comment :=>> Passa  de {9, 9}, { 8,8 }, { 7,7 }, { 6,6 }, { 5,5 }, { 4,4 }, { 3,3 }, { 2,2 }, { 1,1 }, { 0,0 }" << endl;
	cout << "Comment :=>> a {9, 9}, { 8,8 }, { 7,7 }, { 6,6 }, { 5,5 }                                                     " << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------------------------------" << endl;
	
	v.redimensiona(5);
	if (!comparaVectors(v, resultat[1], longitudResultat[1]))
	{
		cout << "Comment :=>> ERROR redimensionant el vector a un tamany mes petit" << endl;		
	}
	else
	{
		cout << "Comment :=>> OK redimensionant el vector a un tamany mes petit" << endl;
		punts += 2;
	}
	cout << "Comment :=>> -------------------------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>> Assignacio Vector 5 posicions                    " << endl;
	cout << "Comment :=>> {9, 9}, { 8,8 }, { 7,7 }, { 6,6 }, { 5,5 }       " << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	
	Vector v2 = v;

	if (!comparaVectors(v2, resultat[2], longitudResultat[2]))
	{
		cout << "Comment :=>> ERROR comprovant operador d'assignacio entre vectors" << endl;		
	}
	else
	{
		cout << "Comment :=>> OK comprovant operador d'assignacio entre vectors" << endl;
		punts += 2;
	}
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Construint vector a partir d'un altre de 5 posicions: CONSTRUCTOR DE COPIA  " << endl;
	cout << "Comment :=>> {9, 9}, { 8,8 }, { 7,7 }, { 6,6 }, { 5,5 }                                  " << endl;
	cout << "Comment :=>> ----------------------------------------------------------------------------" << endl;
	
	Vector v3(v);
	if (!comparaVectors(v3, resultat[3], longitudResultat[3]))
	{		
		cout << "Comment :=>> ERROR comprovant constructor copia" << endl;
	}
	else
	{
		cout << "Comment :=>> OK comprovant constructor copia" << endl;
		punts += 2;
	}
	cout << "Comment :=>> ----------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Redimensionant Vector de 5 posicions a 20 posicions                                                                                                                      " << endl;
	cout << "Comment :=>> Passa  de {9,9}, {8,8}, {7,7}, {6,6}, {5,5}                                                                                                                              " << endl;
	cout << "Comment :=>> a         {9,9}, {8,8}, {7,7}, {6,6}, {5,5}, {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {14,14}, {13,13}, {12,12}, {11,11}, {10,10}, {15,15}, {16,16}, {17,17}, {18,18}, {19,19} " << endl;	
	cout << "Comment :=>> -------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	v.redimensiona(20);

	for (int i = 5; i < 10; i++)
	{
		v[i].setX(i - 5);
		v[i].setY(i - 5);
	}
		
	for (int i = 10; i < 15; i++)
	{
		v[i].setX(15 - (i - 10) - 1);
		v[i].setY(15 - (i - 10) - 1);
	}
		
	for (int i = 15; i < 20; i++)
	{
		v[i].setX(i);
		v[i].setY(i);
	}
		
	if (!comparaVectors(v, resultat[4], longitudResultat[4]))
	{
		cout << "Comment :=>> ERROR redimensionant i assignant valors un vector a un tamany mes gran" << endl;		
	}
	else
	{
		cout << "Comment :=>> OK redimensionant un vector i assignant valors a un tamany mes gran" << endl;
		punts += 2;
	}
	cout << "Comment :=>> -----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	return punts;
}

int main()
{
	float grade = 0;

	grade += testVector();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}