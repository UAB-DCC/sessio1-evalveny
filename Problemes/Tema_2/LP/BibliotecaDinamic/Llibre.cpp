#include "Llibre.h"


Llibre::Llibre()
{
	m_nExemplars = 0;
	m_exemplars = NULL;
}

Llibre::Llibre(const string &titol, const string &autor, int nExemplars)
{
	m_titol = titol;
	m_autor = autor;
	m_nExemplars = nExemplars;
	m_exemplars = new Exemplar[m_nExemplars];
	for (int i = 0; i < m_nExemplars; i++)
		m_exemplars[i].setCodi(i + 1);
}


Llibre::~Llibre()
{
	if (m_exemplars != NULL)
		delete[] m_exemplars;
}


void Llibre::setNExemplars(int nExemplars)
{
	if (m_exemplars == NULL)
	{
		m_nExemplars = nExemplars;
		m_exemplars = new Exemplar[m_nExemplars];
		for (int i = 0; i < m_nExemplars; i++)
			m_exemplars[i].setCodi(i + 1);
	}
}


bool Llibre::prestar(const string &data, int &codiExemplar)
{
	bool disponible = false;
	int i = 0;
	while (!disponible && (i < m_nExemplars))
	{
		if (!m_exemplars[i].estaPrestat())
			disponible = true;
		else
			i++;
	}
	if (disponible)
	{
		codiExemplar = m_exemplars[i].getCodi();
		m_exemplars[i].prestar(data);
	}
	return disponible;

}

bool Llibre::retornar(const string &data, int codiExemplar)
{
	bool trobat = false;
	bool retornat = false;
	int i = 0;
	while (!trobat && (i < m_nExemplars))
	{
		if (m_exemplars[i].getCodi() == codiExemplar)
			trobat = true;
		else
			i++;
	}
	if (trobat)
		retornat = m_exemplars[i].retornar(data);
	return retornat;

}
