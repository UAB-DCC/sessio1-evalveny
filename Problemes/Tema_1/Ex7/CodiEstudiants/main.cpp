// HistNotes.cpp: define el punto de entrada de la aplicación de consola.
//

#include "Assignatura.h"
#include <iostream>
#include <string>
using namespace std;

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

float testHistograma()
{
	float reduccio = 0.0;

	HistogramaNotes hist;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la classe HistogramaNotes" << endl;
	cout << "Comment :=>> ==========================================" << endl;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>> Iniciant test del metode registra" << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_REGISTRA = 10;
	float valors[N_PROVES_REGISTRA] = { 10.5, -0.5, 1.0, 1.2, 1.6, 1.9, 10.0, 8.2, 8.6, 5.5 };
	bool resultatRegistra[N_PROVES_REGISTRA] = { false, false, true, true, true, true, true, true, true, true };
	for (int i = 0; i < N_PROVES_REGISTRA; i++)
	{
		cout << "Comment :=>> Registrant valor: " << valors[i] << endl;

		bool resultat = hist.registra(valors[i]);
		cout << "Comment :=>> Resultat: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat == resultatRegistra[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test del metode getValor despres registrar els valors anteriors" << endl;
	cout << "Comment :=>> ------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_GETVALOR = 13;
	int posicio[N_PROVES_GETVALOR] = { -1, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int resultatRecupera[N_PROVES_GETVALOR] = { -1, -1, 0, 4, 0, 0, 0, 1, 0, 0, 2, 0, 1 };
	for (int i = 0; i < N_PROVES_GETVALOR; i++)
	{
		cout << "Comment :=>> Recuperant valor de la posicio: " << posicio[i] << endl;

		int resultat = hist.getValor(posicio[i]);
		cout << "Comment :=>> Resultat: " << resultat << endl;
		if (resultat == resultatRecupera[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << resultatRecupera[i] << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}


	if (reduccio > 6)
		reduccio = 6.0;
	return reduccio;

}


float testAssignatura()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la classe Assignatura" << endl;
	cout << "Comment :=>> ======================================" << endl;

	const int N_PROVES = 4;
	const int N_ESTUDIANTS = 5;
	const string nom = "Estudiant";
	float notes[N_PROVES][N_ESTUDIANTS] =
	{
		{ 0.2, 0.6, 0.9, 3.5, 6.5 },
		{ 10.0, 10.0, 10.0, 3.5, 6.5 },
		{ 3.2, 3.6, 3.9, 6.5, 8.5 },
		{ 5.2, 5.6, 5.9, 3.5, 1.5 }
	};
	int resultatMaxim[N_PROVES] = { 0, 10, 3, 5 };
	for (int i = 0; i < N_PROVES; i++)
	{
		Assignatura assig;

		cout << "Comment :=>> TEST " << i + 1 << endl;
		for (int j = 0; j < N_ESTUDIANTS; j++)
		{
			Estudiant e;
			e.setNom(nom);
			e.setNota(notes[i][j]);
			cout << "Comment :=>> Afegint estudiant amb nota: " << notes[i][j] << endl;
			assig.afegeixEstudiant(e);
		}

		cout << "Comment :=>> Calculant histograma de notes" << endl;
		assig.calculaHistograma();
		cout << "Comment :=>> Recuperant maxim de l'histograma de notes" << endl;
		int resultat = assig.notaMesRepetida();

		cout << "Comment :=>> Resultat: " << resultat << endl;
		if (resultat == resultatMaxim[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. s'esperava: " << resultatMaxim[i] << endl;
			reduccio += 2;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	
	if (reduccio > 6)
		reduccio = 6.0;
	return reduccio;
}



int main()
{
	float grade = 10;

	grade -= testHistograma();
	grade -= testAssignatura();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}

