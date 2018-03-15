#include "Usuari.h"

Usuari::Usuari(string codi, string nom, int edat)
{
	m_codi = codi;
	m_nom = nom;
	m_edat = edat;
}

void Usuari::copiaValor(const Usuari& u)
{
	m_codi = u.m_codi;
	m_nom = u.m_nom;
	m_edat = u.m_edat;
}