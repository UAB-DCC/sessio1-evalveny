#include "LlistatEspectacles.h"
#include <fstream>
using namespace std;



LlistatEspectacles::LlistatEspectacles()
{
	m_NEspectacles = 0;
	m_espectacles = NULL;
}


LlistatEspectacles::~LlistatEspectacles()
{
	if(m_espectacles!=NULL)
		delete[] m_espectacles;
}

LlistatEspectacles::LlistatEspectacles(int nMaxEspectacles)
{
	m_espectacles = new Espectacle[nMaxEspectacles];	
	m_NEspectacles = 0;
	m_maxEspectacles = nMaxEspectacles;
}

bool LlistatEspectacles::afegeixEspectacle(string nom, string teatre, string dia, string hora, int entradesTotals, float preu)
{
	bool correcte = false;

	if (m_NEspectacles < m_maxEspectacles)
	{
		correcte = true;
		m_espectacles[m_NEspectacles].setNom(nom);
		m_espectacles[m_NEspectacles].setTeatre(teatre);
		m_espectacles[m_NEspectacles].setDia(dia);
		m_espectacles[m_NEspectacles].setHora(hora);
		m_espectacles[m_NEspectacles].setEntradesTotals(entradesTotals);
		m_espectacles[m_NEspectacles].setPreu(preu);
		m_NEspectacles++;
	}
	return correcte;
}

int LlistatEspectacles::buscaEspectacle(string nom, string dia)
{
	int i = 0;
	bool trobat = false;
	while (!trobat && (i < m_NEspectacles))
	{
		if ((m_espectacles[i].getNom() == nom) && (m_espectacles[i].getDia() == dia))
			trobat = true;
		else
			i++;
	}
	if (trobat)
		return i;
	else return -1;
}

int LlistatEspectacles::reservaEspectacle(string nom, string dia, int nEntrades, string espectador, float& preu)
{
	int resultat = 0;
	int nEspectacle = buscaEspectacle(nom, dia);

	if (nEspectacle == -1)
		resultat = -2;
	else
	{
		if (m_espectacles[nEspectacle].getEntradesLliures() >= nEntrades)
		{
			m_espectacles[nEspectacle].reservaEntrades(nEntrades);
			m_espectacles[nEspectacle].afegeixEspectador(espectador, nEntrades);
			preu = m_espectacles[nEspectacle].getPreu() * nEntrades;
		}
		else resultat = -1;
	}
	return resultat;
}

bool LlistatEspectacles::guardaEspectadors(string nom, string dia, const char *nomFitxer)
{
	bool correcte = false;
	int nEspectacle = buscaEspectacle(nom, dia);
	if (nEspectacle >= 0)
	{
		correcte = true;
		ofstream fitxer;
		fitxer.open(nomFitxer);
		int nEspectadors;
		Espectador *espectadors = m_espectacles[nEspectacle].getEspectadors(nEspectadors);
		for (int i = 0; i < nEspectadors; i++)
			fitxer << espectadors[i].getNom() << " " << espectadors[i].getNEntrades() << endl;
		fitxer.close();
	}
	return correcte;
}
