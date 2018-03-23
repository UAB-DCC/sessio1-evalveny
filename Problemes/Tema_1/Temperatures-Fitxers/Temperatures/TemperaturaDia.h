#pragma once

const int MAX_TEMPERATURES = 24;

class TemperaturaDia
{
public:
	TemperaturaDia();

	void registraTemperatura(int temperatura, int hora);
	void calculaResum();
	int getMinima();
	int getMaxima();
	int getMitjana();

private:
	int m_temperatures[MAX_TEMPERATURES];
	int m_minima;
	int m_maxima;
	int m_mitjana;
};
