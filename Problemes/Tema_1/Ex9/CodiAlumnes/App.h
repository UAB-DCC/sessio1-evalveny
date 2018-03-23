#pragma once
#include "Descarrega.h"
#include <string>
#include <fstream>
using namespace std;


class App
{
public:
	App() { m_nom = ""; m_descripcio = ""; m_tamany = 0 }
	void setApp(const string &nom, const string &descripcio, int tamany)
	{
		m_nom = nom; m_descripcio = descripcio; m_tamany = tamany;
	}
	string getNom() const { return m_nom; }
	string getDescripcio() const { return m_descripcio; }
	int getTamany() const { return m_tamany; }
	friend std::ofstream& operator<< (std::ofstream& fitxer, const App &a);
private:
	string m_nom;
	string m_descripcio;
	int m_tamany;
};
