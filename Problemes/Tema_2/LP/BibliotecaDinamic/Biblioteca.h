#pragma once

#include "Llibre.h"

class Biblioteca
{
public:
	Biblioteca();
	~Biblioteca();

	void llegirLlibres(const char *nomFitxer);
	bool cercarLlibre(const string &titol, Llibre &llibre);
private:
	Llibre *m_llibres;
	int m_nLlibres;
};

