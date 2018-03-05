#include "Llibre.h"
#include "funcionsLlibre.h"
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


float testClasseLlibre()
{
	string titol = "Data Structures and Data Analysis in C++";
	string autor = "Weiss";
	int nExemplars = 3;

	float reduccio = 0.0;

	Llibre l;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la classe Llibre" << endl;
	cout << "Comment :=>> =================================" << endl;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant un llibre amb aquest contingut" << endl;
	cout << "Comment :=>> Titol: " << titol << endl;
	cout << "Comment :=>> Autor: " << autor << endl;
	cout << "Comment :=>> N exemplars: " << nExemplars << endl;

	l.setTitol(titol);
	l.setAutor(autor);
	l.setNExemplars(nExemplars);

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Comprovant dades del llibre despres inicialitzar" << endl;
	cout << "Comment :=>> Titol: " << l.getTitol() << endl;
	if (l.getTitol() == titol)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1;
	}
	cout << "Comment :=>> Autor: " << l.getAutor() << endl;
	if (l.getAutor() == autor)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1;
	}
	cout << "Comment :=>> N exemplars: " << l.getNExemplars() << endl;;
	if (l.getNExemplars() == nExemplars)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test del metode presta" << endl;
	cout << "Comment :=>> N exemplars del llibre sense prestar: " << nExemplars << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_PRESTAR_1 = 4;
	bool resultatPrestar1[N_PROVES_PRESTAR_1] = { true, true, true, false };
	for (int i = 0; i < N_PROVES_PRESTAR_1; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Realitzant prestec: " << endl;

		int codiExemplar;
		bool resultat = l.presta(codiExemplar);
		cout << "Comment :=>> Resultat: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat == resultatPrestar1[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test del metode retorna despres de fer els prestecs anteriors" << endl;
	cout << "Comment :=>> ----------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_RETORNAR = 4;
	bool resultatRetornar[N_PROVES_RETORNAR] = { true, false, false, true };
	int codiExemplarRetornar[N_PROVES_RETORNAR] = { 1, 1, 4, 2 };
	for (int i = 0; i < N_PROVES_RETORNAR; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Retornant exemplar amb codi: " << codiExemplarRetornar[i] << endl;

		bool resultat = l.retorna(codiExemplarRetornar[i]);
		cout << "Comment :=>> Resultat: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat == resultatRetornar[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test del metode presta despres de fer els retorns anteriors" << endl;
	cout << "Comment :=>> --------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_PRESTAR_2 = 4;
	bool resultatPrestar2[N_PROVES_PRESTAR_2] = { true, true, false };
	for (int i = 0; i < N_PROVES_PRESTAR_2; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Realitzant prestec: " << endl;

		int codiExemplar;
		bool resultat = l.presta(codiExemplar);
		cout << "Comment :=>> Resultat: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat == resultatPrestar2[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}


	if (reduccio > 5)
		reduccio = 5.0;
	return reduccio;

}

float  testFuncionsLlibre()
{
	float reduccio = 0.0;
	const int MAX_LLIBRES = 4;
	string titol[MAX_LLIBRES] = {
		"Data Structures and Data Analysis in C++",
		"Thinking in C++",
		"Programacion en C++ para ingenieros",
		"The C++ Programming Language"
	};
	string autor[MAX_LLIBRES] = { "Weiss", "Eckel", "Xhafa", "Stroustrup" };
	int nExemplars[MAX_LLIBRES] = { 3, 4, 2, 1 };

	Llibre llibres[MAX_LLIBRES];

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de les funcions prestaLlibre i retornaLlibre" << endl;
	cout << "Comment :=>> ==========================================================" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant l'array de llibres pel test" << endl;
	for (int i = 0; i < MAX_LLIBRES; i++)
	{
		cout << "Comment :=>> llibre " << i+1 << ": " << titol[i] << ", " << autor[i] << ", " << nExemplars[i] << endl;
		llibres[i].setTitol(titol[i]);
		llibres[i].setAutor(autor[i]);
		llibres[i].setNExemplars(nExemplars[i]);
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test de la funcio prestaLlibre" << endl;
	cout << "Comment :=>> ---------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_PRESTAR = 4;
	int resultatPrestar[N_PROVES_PRESTAR] = { -2, 0, -1, 0};
	string titolPrestar[N_PROVES_PRESTAR] = {
		"Introduction to Databases",
		"The C++ Programming Language",
		"The C++ Programming Language",
		"Thinking in C++"
	};
	for (int i = 0; i < N_PROVES_PRESTAR; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Realitzant prestec de llibre : " << titolPrestar[i] << endl;

		int codiExemplar;
		int resultat = prestaLlibre(llibres, MAX_LLIBRES, titolPrestar[i], codiExemplar);
		cout << "Comment :=>> Resultat: " << resultat << endl;
		if (resultat == resultatPrestar[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << resultatPrestar[i] << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test de la funcio retornaLlibre despres de fer els prestecs anteriors" << endl;
	cout << "Comment :=>> ------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_RETORNAR = 4;
	int resultatRetornar[N_PROVES_RETORNAR] = { -2, 0, -1, -1 };
	int codiExemplarRetornar[N_PROVES_RETORNAR] = { 0, 0, 0, 5 };
	string titolRetornar[N_PROVES_RETORNAR] = {
		"Introduction to Databases",
		"The C++ Programming Language",
		"Data Structures and Data Analysis in C++",
		"Programacion en C++ para ingenieros"
	};
	for (int i = 0; i < N_PROVES_RETORNAR; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Realitzant retorn de llibre : " << titolRetornar[i] << ", exemplar: " << codiExemplarRetornar[i] <<  endl;

		int resultat = retornaLlibre(llibres, MAX_LLIBRES, titolPrestar[i], codiExemplarRetornar[i]);
		cout << "Comment :=>> Resultat: " << resultat << endl;
		if (resultat == resultatRetornar[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << resultatRetornar[i] << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}


	if (reduccio > 5)
		reduccio = 5.0;
	return reduccio;
}

int main()
{
	Llibre l;
	float grade = 10;

	grade -= testClasseLlibre();
	grade -= testFuncionsLlibre();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;

}