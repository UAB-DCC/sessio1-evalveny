#include "stdafx.h"
#include "Poligon.h"
#include <iostream>
#include <fstream>

using namespace std;


Poligon::Poligon()
{
}


Poligon::~Poligon()
{
	delete[] m_vertexs;
	m_vertexs = NULL;
}


void Poligon::init( string nomFitxer)
{
	ifstream fitxer;

	fitxer.open(nomFitxer.c_str());
	//fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		fitxer >> m_nVertexs;
		m_vertexs = new Punt[m_nVertexs];
		float x, y;
		fitxer >> x >> y;
		int i = 0;
		while ( (!fitxer.eof()) && (i<m_nVertexs))
		{
			m_vertexs[i].setX(x);
			m_vertexs[i].setY(y);
			fitxer >> x >> y;
			i++;
		}
		fitxer.close();
	}
	else
	{
		cout << "error de fitxer";
	}
}

void Poligon::centroid(Punt* cent)
{
	float x, y;
	x = 0;
	y = 0;
	for (int i = 0; i < m_nVertexs; i++)
	{
		x += m_vertexs[i].getX();
		y += m_vertexs[i].getY();
	}
	cent->setX(x / m_nVertexs);
	cent->setY(y / m_nVertexs);

}
void Poligon::escriu()
{
	for (int i = 0; i < m_nVertexs; i++)
	{
		cout << m_vertexs[i].getX() << " " << m_vertexs[i].getY() << endl;
	}
}