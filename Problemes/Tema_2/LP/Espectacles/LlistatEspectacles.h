#pragma once

#include "Espectacle.h"

class LlistatEspectacles
{
public:
	LlistatEspectacles();
	LlistatEspectacles(int nMaxEspectacles);
	~LlistatEspectacles();

	bool afegeixEspectacle(string nom, string teatre, string dia, string hora, int entradesTotals, float preu);
	int reservaEspectacle(string nom, string dia, int nEntrades, string espectador, float& preu);
	bool guardaEspectadors(string nom, string dia, const char *nomFitxer);

private:
	Espectacle *m_espectacles;
	int m_maxEspectacles;
	int m_NEspectacles;

	int buscaEspectacle(string nom, string dia);
};

