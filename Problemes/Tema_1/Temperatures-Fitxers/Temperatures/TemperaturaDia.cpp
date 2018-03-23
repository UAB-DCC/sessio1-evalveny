#include "TemperaturaDia.h"

TemperaturaDia::TemperaturaDia()
{
}

void TemperaturaDia::registraTemperatura(int temperatura, int hora)
{
	if((hora >= 0) && (hora <= 23))
	{
		m_temperatures[hora] = temperatura;
	}
}

void TemperaturaDia::calculaResum()
{
	m_minima = m_temperatures[0];
	m_maxima = m_temperatures[0];
	int mitjana = m_temperatures[0];
	for(int i = 1; i < MAX_TEMPERATURES; i++)
	{
		if(m_temperatures[i] < m_minima)
		{
			m_minima = m_temperatures[i];
		}
		if(m_temperatures[i] > m_maxima)
		{
			m_maxima = m_temperatures[i];
		}
		mitjana += m_temperatures[i];
	}
	m_mitjana = mitjana / MAX_TEMPERATURES;
}

int TemperaturaDia::getMinima()
{
	return m_minima;
}

int TemperaturaDia::getMaxima()
{
	return m_maxima;
}

int TemperaturaDia::getMitjana()
{
	return m_mitjana;
}