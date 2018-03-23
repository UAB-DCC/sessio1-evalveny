#include "TemperaturaSetmana.h"
#include <fstream>
#include <iostream>
#include <string>

TemperaturaSetmana::TemperaturaSetmana()
{
}

void TemperaturaSetmana::llegeixTemperatures(string nomFitxer)
{
	ifstream fitxer;

	fitxer.open(nomFitxer.c_str());
	if(fitxer.is_open())
	{
		for(int hora = 0; hora < MAX_TEMPERATURES; hora++)
		{
			for(int dia = 0; dia < DIES_SETMANA; dia++)
			{
				int temp;
				fitxer >> temp;
				m_temperatures[dia].registraTemperatura(temp, hora);
			}
		}
		fitxer.close();
	}
}

void TemperaturaSetmana::calculaResum()
{
	for(int dia = 0; dia < DIES_SETMANA; dia++)
	{
		m_temperatures[dia].calculaResum();
	}
}

void TemperaturaSetmana::guardaResum()
{
	ofstream fitxer;

	fitxer.open("sortida1.txt");
	if(fitxer.is_open())
	{
		for(int dia = 0; dia < DIES_SETMANA; dia++)
		{
			fitxer << m_temperatures[dia].getMinima() << " " << m_temperatures[dia].getMaxima() << " " << m_temperatures[dia].getMitjana() << endl;
		}
		fitxer.close();
	}
}