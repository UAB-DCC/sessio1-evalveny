#include "TemperaturaDia.h"

TemperaturaDia::TemperaturaDia()
{
}

/*void TemperaturaDia::registraTemperatura(int temperatura, int hora)
{
	if((hora >= 0) && (hora < MAXTEMPERATURES))
	{
		m_temperatures[hora] = temperatura;
	}
}*/
void TemperaturaDia::getTemperatura(int v[MAXTEMPERATURES])
{
	for (int h = 0; h < MAXTEMPERATURES; h++)
	{
		v[h] = m_temperatures[h];
	}	
}

void TemperaturaDia::calculaResum()
{
	m_minima = m_temperatures[0];
	m_maxima = m_temperatures[0];
	int mitjana = m_temperatures[0];
	for(int i = 1; i < MAXTEMPERATURES; i++)
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
	m_mitjana = mitjana / MAXTEMPERATURES;
}

/*istream& operator >> (istream& input, TemperaturaDia& tDia)
{
	for (int hora = 0; hora < tDia.MAXTEMPERATURES; hora++)
	{
		int temp;
		input >> temp;
		tDia.registraTemperatura(temp, hora);
	}
	return input;
}

ostream& operator<< (ostream& output, const TemperaturaDia& tDia)
{
	output << tDia.m_minima <<" " <<tDia.m_maxima <<" " <<tDia.m_mitjana <<endl;			
	return output;
}
*/

void TemperaturaDia::guardaResumDia(ofstream& fitxer)
{
	fitxer << m_minima << " " << m_maxima << " " << m_mitjana << endl;
}
void TemperaturaDia::llegeixTemperaturaDia(ifstream& fitxer)
{
	for (int hora = 0; hora < MAXTEMPERATURES; hora++)
	{
		int temp;
		fitxer >> temp;
		m_temperatures[hora] = temp;
	}
}
