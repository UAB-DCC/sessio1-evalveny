#include "Punt.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Poligon
{
public:
	Poligon();
	~Poligon();
	void init(string nomFitxer);
	void escriu();
	//Poligon& operator=(const Poligon& p);

private:
	int m_nVertexs;
	Punt* m_vertexs;
};

