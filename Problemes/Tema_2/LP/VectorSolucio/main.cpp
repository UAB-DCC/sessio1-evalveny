#include "Vector.h"
#include "Persona.h"
#include <iostream>
using namespace std;

template <class T>
bool comparaVectors(Vector<T> &v, T* resultat, int longitud)
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

int main()
{
	bool valid = true;
	float grade = 10.0;
	
	const int MAX_PROVES = 6;

	int resultat[MAX_PROVES][20] = {
		{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
		{ 9, 8, 7, 6, 5 },
		{ 9, 8, 7, 6, 5 },
		{ 9, 8, 7, 6, 5 },
		{ 9, 8, 7, 6, 5, 0, 1, 2, 3, 4, 14, 13, 12, 11, 10, 15, 16, 17, 18, 19 },
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }
	};
	int longitudResultat[MAX_PROVES] = { 10, 5, 5, 5, 20, 20 };

	Vector<int> v;
	v.redimensiona(10);
	for (int i = 0; i < 10; i++)
		v[i] = 10 - (i + 1);
	valid = comparaVectors(v, resultat[0], longitudResultat[0]);
	if (!valid)
	{
		cout << "Comment :=>> Error redimensionant i inicialitzant el vector" << endl;
		grade -= 2;
	}
	v.redimensiona(5);
	if (!comparaVectors(v, resultat[1], longitudResultat[1]))
	{
		valid = false;
		cout << "Comment :=>> Error redimensionant el vector a un tamany mes petit" << endl;
		grade -= 2;
	}

	Vector<int> v2 = v;
	if (!comparaVectors(v2, resultat[2], longitudResultat[2]))
	{
		valid = false;
		cout << "Comment :=>> Error comprovant operador d'assignacio entre vectors" << endl;
		grade -= 2;
	}

	Vector<int> v3(v);
	if (!comparaVectors(v3, resultat[3], longitudResultat[3]))
	{
		valid = false;
		cout << "Comment :=>> Error comprovant constructor copia" << endl;
		grade -= 2;
	}
	v.redimensiona(20);
	for (int i = 5; i < 10; i++)
		v[i] = i - 5;
	for (int i = 10; i < 15; i++)
		v[i] = 15 - (i - 10) - 1;
	for (int i = 15; i < 20; i++)
		v[i] = i;
	if (!comparaVectors(v, resultat[4], longitudResultat[4]))
	{
		valid = false;
		cout << "Comment :=>> Error redimensionant un vector a un tamany mes gran" << endl;
		grade -= 2;
	}
	v.sort();
	if (!comparaVectors(v, resultat[5], longitudResultat[5]))
	{
		valid = false;
		cout << "Comment :=>> Error ordenant el vector" << endl;
		grade -= 2;
	}

	const int MAX_PERSONES = 10;

	Persona persones[MAX_PERSONES] = { {"B", 20},{ "A", 20 }, {"B", 30}, {"D", 40}, {"C", 50},
										{"C", 20}, {"D", 25}, {"E", 30}, {"B", 40}, {"D", 30} };
	Persona personesResultat[MAX_PERSONES] = { { "A", 20 },{ "B", 20 },{ "C", 20 },{ "D", 25 },{ "B", 30 },
										{ "D", 30 },{ "E", 30 },{ "B", 40 },{ "D", 40 },{ "C", 50 } };

	Vector<Persona> vPersona;
	vPersona.redimensiona(MAX_PERSONES);
	for (int i = 0; i < MAX_PERSONES; i++)
		vPersona[i] = persones[i];
	if (!comparaVectors(vPersona, persones, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> Error redimensionant i inicialitzant el vector de persones" << endl;
		grade -= 2;
	}
	Vector<Persona> vPersona2 = vPersona;
	if (!comparaVectors(vPersona2, persones, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> Error comprovant operador d'assignacio entre vectors de persones" << endl;
		grade -= 2;
	}

	Vector<Persona> vPersona3(vPersona);
	if (!comparaVectors(vPersona3, persones, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> Error constructor de còpia al vector de persones" << endl;
		grade -= 2;
	}

	Persona p;
	p = vPersona[-1];
	if ((p.getNom() != "") && (p.getEdat() != 0))
	{
		valid = false;
		cout << "Comment :=>> Error comprovant limits vector (acces a index negatiu)" << endl;
		grade -= 2;
	}
	p = vPersona[MAX_PERSONES];
	if ((p.getNom() != "") && (p.getEdat() != 0))
	{
		valid = false;
		cout << "Comment :=>> Error comprovant limits vector (acces a index superior al limit)" << endl;
		grade -= 2;
	}
	vPersona.sort();
	if (!comparaVectors(vPersona, personesResultat, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> Error ordenant el vector" << endl;
		grade -= 2;
	}

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}