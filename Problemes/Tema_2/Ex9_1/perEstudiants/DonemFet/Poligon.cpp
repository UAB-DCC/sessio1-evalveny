#include "Poligon.h"

using namespace std;

void Poligon::init( string nomFitxer)
{
	//Afegir codi
}

void Poligon::escriu()
{
	for (int i = 0; i < m_nVertexs; i++)
	{
		cout << m_vertexs[i].getX() << " " << m_vertexs[i].getY() << endl;
	}
}