#pragma once
#include <string>
using namespace std;

class Persona
{
public:
	Persona();
	Persona(const string &nom, int edat) : m_nom(nom), m_edat(edat) {}
	~Persona();
	string getNom() const { return m_nom; }
	int getEdat() const { return m_edat; }
	void setNom(const string &nom) { m_nom = nom; }
	void setEdat(int edat) { m_edat = edat;  }
private:
	string m_nom;
	int m_edat;
};