#include "Llibre.h"


Llibre::Llibre(const string &titol, const string &autor, int nExemplars)
{
	m_titol = titol;
	m_autor = autor;
	m_nExemplars = nExemplars;
	std::forward_list<Exemplar>::iterator actual = m_exemplars.begin();
	for (int i = 0; i < m_nExemplars; i++)
	{
		Exemplar e;
		e.setCodi(i + 1);
		actual=m_exemplars.insert_after(actual,e);		
	}
		
}


Llibre::~Llibre()
{
}

Llibre& Llibre::operator=(const Llibre& l)
{
	if (this != &l)
	{
		m_titol = l.m_titol;
		m_autor = l.m_autor;
		m_nExemplars = l.m_nExemplars;
		if (!m_exemplars.empty())
		{
			m_exemplars.clear();
		}
			
		if (m_nExemplars > 0)
		{
			std::forward_list<Exemplar>::const_iterator actualL = l.m_exemplars.begin();
			std::forward_list<Exemplar>::iterator actualThis = m_exemplars.before_begin();
			
			while (actualL!= l.m_exemplars.end())
			{
				actualThis = m_exemplars.insert_after(actualThis,(*actualL));
				actualL++;
			}				
		}
		
	}
	return *this;
}
//NOTA: const_iterator

void Llibre::setNExemplars(int nExemplars)
{
	if (m_exemplars.empty())
	{
		m_nExemplars = nExemplars;
		std::forward_list<Exemplar>::iterator actual = m_exemplars.before_begin();
		for (int i = 0; i < m_nExemplars; i++)
		{
			Exemplar e;
			e.setCodi(i + 1);
			actual = m_exemplars.insert_after(actual,e);
		}		
	}
}

void Llibre::addExemplar()
{
	if (m_nExemplars > 0)
	{
		std::forward_list<Exemplar>::iterator actual = m_exemplars.begin();
		for (int i = 0; i < m_nExemplars-1; i++)
		{
			actual++;
		}
		Exemplar e;
		e.setCodi(m_nExemplars+1);
		m_exemplars.insert_after(actual, e);
	}
	else
	{
		Exemplar e;
		e.setCodi(1);
		m_exemplars.insert_after(m_exemplars.before_begin(), e);
		
	}
	m_nExemplars++;
}

bool Llibre::prestar(const string &data, int &codiExemplar)
{
	bool disponible = false;
	
	std::forward_list<Exemplar>::iterator actual = m_exemplars.begin();

	while (!disponible && (actual != m_exemplars.end()))
	{
		if (!(*actual).estaPrestat())
		{
			disponible = true;
			codiExemplar = (*actual).getCodi();
			(*actual).prestar(data);
		}
		else
			actual++;
	}	
	return disponible;
}

bool Llibre::retornar(const string &data, int codiExemplar)
{
	bool trobat = false;
	bool retornat = false;
	std::forward_list<Exemplar>::iterator actual = m_exemplars.begin();

	while (!trobat && (actual != m_exemplars.end()))
	{
		if ((*actual).getCodi() == codiExemplar)
		{
			retornat = (*actual).retornar(data);
			trobat = true;
		}
		else
			actual++;
	}
	return retornat;
}
