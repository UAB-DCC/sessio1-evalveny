#include "Persona.h"

Persona::Persona()
{
	m_nom = "";
	m_edat = 0;
}

Persona::~Persona()
{

}

bool Persona::operator >(const Persona &p)
{
	bool mesGran = false;
	if (m_edat > p.m_edat)
		mesGran = true;
	else
		if (m_edat == p.m_edat)
			if (m_nom > p.m_nom)
				mesGran = true;
	return mesGran;
}

bool Persona::operator ==(const Persona &p)
{
	return ((m_nom == p.m_nom) && (m_edat = p.m_edat));
}

Persona &Persona::operator = (const Persona& p)
{
	m_nom = p.m_nom;
	m_edat = p.m_edat;
	return *this;
}