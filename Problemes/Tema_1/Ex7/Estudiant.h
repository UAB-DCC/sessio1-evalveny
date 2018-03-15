#pragma once
#include <iostream>

using namespace std;


class Estudiant
{
public:
	Estudiant() { m_nota = 0; }
	void setNom(const string &nom) { m_nom = nom; }
	void setNota(float nota) { m_nota = nota; }
	string getNom() const { return m_nom; }
	float getNota() const { return m_nota; }
private:
	string m_nom;
	float m_nota;
};

