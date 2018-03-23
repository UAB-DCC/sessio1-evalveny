#include "TemperaturaDia.h"

const int DIESSETMANA = 7;

class TemperaturaSetmana
{
public:
	TemperaturaSetmana();
	void llegeixTemperatures(string nomFitxer);
	void calculaResum();
	void guardaResum(string nomFitxer);
	void getTemperaturaSetmana(int temp[DIESSETMANA][MAXTEMPERATURES]);
	TemperaturaDia& getTemperaturaDia(int d) { return m_temperatures[d]; };
//	friend istream &operator >> (istream &input, TemperaturaSetmana& tS);
//	friend ostream &operator<< (ostream &output, const TemperaturaSetmana& tS);
private:
	TemperaturaDia m_temperatures[DIESSETMANA];
};
