#include "TemperaturaSetmana.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

float testTSetmana()
{
	float punts = 0;
	const int MAXDIES = 7;
	const int MAXHORES = 24;
	const int MAXRES = 3;

	

	int temperatures[MAXDIES][MAXHORES] = { { 12,15,18,12,17,15,10,12,22,10,5,9,25,28,10,12,18,11,22,24,2, 9,8,15},
											  { 10,30,28,22,15,12,23,12,25,31,10,1,12,7,6,29,14,10,15,16,17,19,22,12 },
											  { 10,12,15,14,12,17,12,12,14,15,12,12,11,12,10,12,15,11,11,11,16,12,12,15 },
											  { 18,12,17,15,10,2,5,28,22,7,5,0, 15,16,18,12,27,15,20,23,23,28,22,27 },
											  { 25,20, 22,15,38,22,27,25,10,14,13,18,12,17,16,18,22,25,38,32,17,15,16,13 },
											  { 15,12, 12,14, 12,11,32,32,31,25,5,14,12,15,16,18,22,31,1,10,32,25,18,2 },
											  { 27,25,10,18, 16,28,22,27,25,20,23,23,26,15,17,10,12,15,18,16,12,18,28,42 } };
	int calculTemp[MAXDIES][MAXRES] = { {2,28,14},{1,31,16 },{10,17,12},{ 0,28,16 },{ 10,38,20 },{ 1,32,17 },{ 10,42,20 } }; //Minima,Maxima,Mitjana
	int temperaturesRes[MAXDIES][MAXHORES];

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------" << endl;
	cout << "Comment :=>> Iniciant test Temperatures" << endl;
	cout << "Comment :=>> --------------------------" << endl;
	cout << "Comment :=>>" << endl;

	TemperaturaSetmana tSetmana;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test Temperatures: LlegirTemperatura, ResgistraTemperatura:" << endl;
	cout << "Comment :=>> --------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	
	tSetmana.llegeixTemperatures("fitxer1.txt");
	float puntsParcials = 0;

	tSetmana.getTemperaturaSetmana(temperaturesRes);
	cout << "Comment :=>> TEMPERATURA DIA N: [ T1,T2,...,T24, ]" << endl;
	for (int d = 0; d < MAXDIES; d++)
	{
		cout << "Comment :=>> TEMPERATURA DIA " << d << ": " <<endl;
		cout << "Comment :=>> [ ";
		bool correcte = true;
		for (int h = 0; h < MAXHORES; h++)
		{
			if (temperaturesRes[d][h] != temperatures[d][h]) { correcte = false; }
			cout << temperaturesRes[d][h] << ", ";
		}
		cout << " ]" <<endl;

		if (!correcte)
		{
			cout << "Comment :=>> ERROR TEMPERATURA DIA: " << d << ": SOLUCIO " << endl;
			cout << "Comment :=>> [ ";
			for (int h = 0; h < MAXHORES; h++)
			{
				cout << temperatures[d][h] << ", ";
			}
			cout << " ]" << endl;
		}
		else
		{
			cout << "Comment :=>> CORRECTE TEMPERATURA DIA: " <<d << endl;
			puntsParcials += 0.5;
		}
	}
	
	cout << "Comment :=>> -----------------------------------------------------------------" << endl;
	cout << "Comment :=>> Final test Temperatures: LlegirTemperatura, ResgistraTemperatura:" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 3.5)" << endl;
	cout << "Comment :=>> -----------------------------------------------------------------" << endl;

	punts += puntsParcials;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test Temperatures CalculaResum:" << endl;
	cout << "Comment :=>> -----------------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;

	tSetmana.calculaResum();
	cout << "Comment :=>> CALCUL ESTADISTIQUES TEMPERATURA DIA N: [ MINIMA, MAXIMA, MITJANA ]" << endl;
	for (int d = 0; d < MAXDIES; d++)
	{
		bool correcte = true;
		cout << "Comment :=>> CALCUL ESTADISTIQUES TEMPERATURA DIA " << d << ":          [";
		int tempMax,tempMin,tempMitjana;
		tempMin = tSetmana.getTemperaturaDia(d).getMinima();

		cout << tempMin <<", ";
		tempMax = tSetmana.getTemperaturaDia(d).getMaxima();
		cout << tempMax << ", ";
		tempMitjana = tSetmana.getTemperaturaDia(d).getMitjana();
		cout << tempMitjana << " ] " <<endl;
		if ((tempMin!= calculTemp[d][0]) ||(tempMax!= calculTemp[d][1])||(tempMitjana!=calculTemp[d][2]))
		{
			correcte = false;
			cout << "Comment :=>> ERROR CALCUL ESTADISTIQUES TEMPERATURA DIA: " << d << ": SOLUCIO " << endl;
			cout << "Comment :=>> SOLUIO CALCUL ESTADISTIQUES TEMPERATURA DIA " << d << ": [" << calculTemp[d][0] <<", " << calculTemp[d][1] <<", " << calculTemp[d][2] <<" ]" <<endl;
		}
		else
		{
			cout << "Comment :=>> CORRECTE CALCUL ESTADISTIQUES TEMPERATURA DIA: " << d << endl;
			puntsParcials += 0.5;
		}

	}
	cout << "Comment :=>> -------------------------------------" << endl;
	cout << "Comment :=>> Final test Temperatures CalculaResum:" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 3.5)" << endl;
	cout << "Comment :=>> -------------------------------------" << endl;

	punts += puntsParcials;
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test Temperatures desarResum:" << endl;
	cout << "Comment :=>> ---------------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;

	tSetmana.guardaResum("sortida1.txt");
	
	ifstream fitxer;

	fitxer.open("sortida1.txt");
	int tempLlegides[MAXDIES][MAXRES];

	if (fitxer.is_open())
	{
		for (int dia = 0; dia < MAXDIES; dia++)
		{
			for (int i = 0; i < MAXRES; i++)
			{
				fitxer >> tempLlegides[dia][i];
			}
		}		
	}

	cout << "Comment :=>> DESAR ESTADISTIQUES TEMPERATURA DIA N: [ MINIMA, MAXIMA, MITJANA ]" << endl;
	for (int d = 0; d < MAXDIES; d++)
	{
		bool correcte = true;
		cout << "Comment :=>> DESAR ESTADISTIQUES TEMPERATURA DIA " << d << ":          [";
		cout << tempLlegides[d][0] << ", " <<tempLlegides[d][1] <<", " << tempLlegides[d][2] <<" ]" <<endl;
				
		if ((tempLlegides[d][0] != calculTemp[d][0]) || (tempLlegides[d][1] != calculTemp[d][1]) || (tempLlegides[d][2] != calculTemp[d][2]))
		{
			correcte = false;
			cout << "Comment :=>> ERROR DESAR ESTADISTIQUES TEMPERATURA DIA: " << d << ": SOLUCIO " << endl;
			cout << "Comment :=>> SOLUIO DESAR ESTADISTIQUES TEMPERATURA DIA " << d << ": [" << calculTemp[d][0] << ", " << calculTemp[d][1] << ", " << calculTemp[d][2] << " ]" << endl;
		}
		else
		{
			cout << "Comment :=>> CORRECTE DESAR ESTADISTIQUES TEMPERATURA DIA: " << d << endl;
			puntsParcials += 0.43;
		}

	}
	if (puntsParcials > 3)
	{
		puntsParcials = 3;
	}

	cout << "Comment :=>> -------------------------------------" << endl;
	cout << "Comment :=>> Final test Temperatures desarResum:" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 3)" << endl;
	cout << "Comment :=>> -------------------------------------" << endl;

	punts += puntsParcials;

	return punts;
}

int main()
{
	float grade = 0;

	grade += testTSetmana();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}