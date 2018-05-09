#include "Biblioteca.h"
#include <fstream>
using namespace std;


Biblioteca::Biblioteca()
{
	m_nLlibres = 0;
}


Biblioteca::~Biblioteca()
{
	if (m_llibres != NULL)
		delete[] m_llibres;
}

void Biblioteca::llegirLlibres(const char *nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	
	string titol, autor;
	int nExemplars;
	int i = 0;
	fitxer >> m_nLlibres;
	m_llibres = new Llibre[m_nLlibres];
	fitxer >> titol >> autor >> nExemplars;
	while (!fitxer.eof())
	{
		m_llibres[i].setAutor(autor);
		m_llibres[i].setTitol(titol);
		m_llibres[i].setNExemplars(nExemplars);
		i++;
		fitxer >> titol >> autor >> nExemplars;
	}
	fitxer.close();
}


bool Biblioteca::cercarLlibre(const string &titol, Llibre &llibre)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nLlibres))
	{
		if (titol == m_llibres[i].getTitol())
			trobat = true;
		else
			i++;
	}
	if (trobat)
		llibre = m_llibres[i];
	return trobat;
}