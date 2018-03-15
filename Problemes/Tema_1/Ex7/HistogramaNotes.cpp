

#include "HistogramaNotes.h"
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

HistogramaNotes::HistogramaNotes()
{
	for (int i = 0; i < RANG_NOTES; i++)
		m_notes[i] = 0;
}

bool HistogramaNotes::registra(float valor)
{
	bool resultat = false;
	
	if ((valor >= 0) && (valor <= 10))
	{
		int intPart = (int)valor;
		m_notes[intPart]++;
		resultat = true;
	}
	return resultat;
}

int HistogramaNotes::getValor(int posicio) const
{
	if ((posicio >= 0) && (posicio <= 10))
		return m_notes[posicio];
	else
		return -1;
}