#include "TemperaturaSetmana.h"

TemperaturaSetmana::TemperaturaSetmana()
{
}

void TemperaturaSetmana::llegeixTemperatures(string nomFitxer)
{
	ifstream fitxer;

	//fitxer.open(nomFitxer.c_str());
	fitxer.open(nomFitxer);
	if(fitxer.is_open())
	{
		for (int dia = 0; dia < DIESSETMANA; dia++)
		{
			m_temperatures[dia].llegeixTemperaturaDia(fitxer);
		}	
		
		//fitxer >> (*this);
		fitxer.close();
	}
}

void TemperaturaSetmana::getTemperaturaSetmana(int temp[DIESSETMANA][MAXTEMPERATURES])
{
	for (int d = 0; d < DIESSETMANA; d++)
	{
		m_temperatures[d].getTemperatura(temp[d]);
	}		
}
void TemperaturaSetmana::calculaResum()
{
	for(int dia = 0; dia < DIESSETMANA; dia++)
	{
		m_temperatures[dia].calculaResum();
	}
}

void TemperaturaSetmana::guardaResum(string nomFitxer)
{
	ofstream fitxer;

	fitxer.open(nomFitxer);
	if(fitxer.is_open())
	{
		for(int dia = 0; dia < DIESSETMANA; dia++)
		{
			m_temperatures[dia].guardaResumDia(fitxer);
		}
		//fitxer << (*this);

		fitxer.close();
	}
}

/*istream& operator >> (istream& input, TemperaturaSetmana& tSetmana)
{
	for (int dia = 0; dia < tSetmana.DIESSETMANA; dia++)
	{
		input >> tSetmana.m_temperatures[dia];
	}	
	return input;
}

ostream& operator<< (ostream& output, const TemperaturaSetmana& tSetmana)
{
	
	for (int dia = 0; dia < tSetmana.DIESSETMANA; dia++)
	{
		output << tSetmana.m_temperatures[dia];
	}
	return output;
}
*/