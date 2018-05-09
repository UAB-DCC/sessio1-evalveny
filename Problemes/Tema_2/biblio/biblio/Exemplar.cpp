#include "Exemplar.h"



Exemplar::Exemplar()
{
	m_prestat = false;
	m_dataPrestec = "";
	m_dataRetorn = "";
}


Exemplar::~Exemplar()
{
}


bool Exemplar::prestar(const string &data)
{
	bool correcte = false;
	if (!m_prestat)
	{
		m_prestat = true;
		m_dataPrestec = data;
		m_dataRetorn = "";
		correcte = true;
	}
	return correcte;
}


bool Exemplar::retornar(const string &data)
{
	bool correcte = false;
	if (m_prestat)
	{
		m_prestat = false;
		m_dataRetorn = data;
		m_dataPrestec = "";
		correcte = true;
	}
	return correcte;
}

