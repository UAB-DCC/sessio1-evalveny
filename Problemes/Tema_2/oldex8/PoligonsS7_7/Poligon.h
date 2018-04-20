#pragma once
#include "Punt.h"
#include <string>
using namespace std;

class Poligon
{
public:
	Poligon();
	~Poligon();
	void init(string nomFitxer);
	void centroid(Punt* cent);
	void escriu();

private:
	int m_nVertexs;
	Punt* m_vertexs;

};

