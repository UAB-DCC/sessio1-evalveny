#include <fstream>
#include <iostream>
#include <string>
using namespace std;


const int MAXTEMPERATURES = 24;

class TemperaturaDia
{
public:
	TemperaturaDia();
	void llegeixTemperaturaDia(ifstream& fitxer);
	//void registraTemperatura(int temperatura, int hora);
	void calculaResum();
	void getTemperatura(int v[MAXTEMPERATURES]);
	int getMinima() { return m_minima; };
	int getMaxima() { return m_maxima; };
	int getMitjana() { return m_mitjana;};
	void guardaResumDia(ofstream& fitxer);
//	friend istream &operator >> (istream &input, TemperaturaDia& tDia);
//	friend ostream &operator<< (ostream &output, const TemperaturaDia& tDia);
	
private:
	int m_temperatures[MAXTEMPERATURES];
	int m_minima;
	int m_maxima;
	int m_mitjana;
};
