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
	Poligon& operator=(const Poligon& p);

private:
	int m_nVertexs;
	Punt* m_vertexs;

};

