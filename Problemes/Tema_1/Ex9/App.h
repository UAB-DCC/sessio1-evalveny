#pragma once
#include "Descarrega.h"
#include <string>
#include <fstream>
using namespace std;


class App
{
public:
	App() { m_nom = ""; m_descripcio = ""; m_tamany = 0; m_nDescarregues = 0; }
	void setApp(const string &nom, const string &descripcio, int tamany) 
	{
		m_nom = nom; m_descripcio = descripcio; m_tamany = tamany;
	}
	void afegeixDescarrega(const string &nomUsuari, const string &data, int temps);
	bool afegeixValoracio(const string &nomUsuari, int valoracio);
	string getNom() const { return m_nom; }
	string getDescripcio() const { return m_descripcio; }
	int getTamany() const { return m_tamany; }
	friend std::ofstream& operator<< (std::ofstream& fitxer, const App &a);
private:
	static const int MAX_DESCARREGUES = 100;
	string m_nom;
	string m_descripcio;
	int m_tamany;
	Descarrega m_descarregues[MAX_DESCARREGUES];
	int m_nDescarregues;
};
