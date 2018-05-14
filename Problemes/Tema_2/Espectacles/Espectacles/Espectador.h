#pragma once
#include <string>
using namespace std;

class Espectador
{
public:
	Espectador();
	~Espectador();

	string &getNom() { return m_nom; }
	int getNEntrades() { return m_nEntrades; }
	void setNom(string nom) { m_nom = nom; }
	void setNEntrades(int nEntrades) { m_nEntrades = nEntrades; }

private:
	string m_nom;
	int m_nEntrades;
};