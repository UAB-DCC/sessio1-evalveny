#include "TemperaturaDia.h"
#include "TemperaturaSetmana.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	TemperaturaSetmana tSetmana;

	tSetmana.llegeixTemperatures("fitxer1.txt");
	tSetmana.calculaResum();
	tSetmana.guardaResum();

	return 0;
}