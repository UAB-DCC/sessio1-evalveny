#include "Punt.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAXVERTEXS = 50;

class Poligon
{
public:
	~Poligon();
	void init(string nomFitxer);
	void escriu();
	
private:
	int m_nVertexs;
	Punt m_vertexs[MAXVERTEXS];

};

