#pragma once

#include "Poligon.h"


class ConjuntPoligons
{
public:
	ConjuntPoligons();
	void init(int numPols, string nomf);
	~ConjuntPoligons();
	void escriu();
	void calculaEscriuCentroid();

private:
	int m_numPoligons;
	Poligon* m_poligons;
};

