#include "stdafx.h"
#include "ConjuntPoligons.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


ConjuntPoligons::ConjuntPoligons()
{
}


ConjuntPoligons::~ConjuntPoligons()
{
}

void ConjuntPoligons::init(int numPols, string nomf)
{
	m_numPoligons = numPols;
	m_poligons = new Poligon[m_numPoligons];
		
	for (int i = 0; i < m_numPoligons;i++)
	{
		string nomFVertex;
		stringstream convert;
		convert << i;
		
		nomFVertex = nomf + convert.str() + ".txt";
		m_poligons[i].init(nomFVertex);
	}	
}

void ConjuntPoligons::escriu()
{
	for (int i = 0; i <m_numPoligons; i++)
	{
		m_poligons[i].escriu();
	}
}

void ConjuntPoligons::calculaEscriuCentroid()
{
	Punt pt;
	for (int i = 0; i <m_numPoligons; i++)
	{
		m_poligons[i].centroid(&pt);
		cout << pt.getX() << " " << pt.getY() << endl;
	}

}