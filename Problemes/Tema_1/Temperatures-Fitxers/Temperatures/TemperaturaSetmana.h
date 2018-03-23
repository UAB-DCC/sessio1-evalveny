#pragma once
#include "TemperaturaDia.h"
#include <string>
using namespace std;

const int DIES_SETMANA = 7;

class TemperaturaSetmana
{
public:
	TemperaturaSetmana();

	void llegeixTemperatures(string nomFitxer);
	void calculaResum();
	void guardaResum();

private:
	TemperaturaDia m_temperatures[DIES_SETMANA];
};
