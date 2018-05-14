#include "Espectacle.h"



Espectacle::Espectacle()
{
	m_NEntradesLliures = 0;
	m_NEntradesTotals = 0;
	m_nEspectadors = 0;
	m_espectadors = NULL;
}


Espectacle::~Espectacle()
{
	if (m_espectadors != NULL)
		delete[] m_espectadors;
}

void Espectacle::setEntradesTotals(int nEntrades) 
{ 
	m_NEntradesTotals = nEntrades; 
	m_NEntradesLliures = nEntrades;
	if (m_espectadors == NULL)
	{ 
		m_espectadors = new Espectador[nEntrades];
		m_nEspectadors = 0;
	}
}

void Espectacle::afegeixEspectador(string nom, int nEntrades)
{
	m_espectadors[m_nEspectadors].setNom(nom);
	m_espectadors[m_nEspectadors].setNEntrades(nEntrades);
	m_nEspectadors++;

}
