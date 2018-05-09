#pragma once

#include "Exemplar.h"
#include <string>
using namespace std;

class Llibre
{
public:
	Llibre();
	Llibre(const string &titol, const string &autor, int nExemplars);
	~Llibre();

	void setTitol(const string &titol) { m_titol = titol; }
	void setAutor(const string &autor) { m_autor = autor; }
	void setNExemplars(int nExemplars);
	string &getTitol() { return m_titol; }
	string &getAutor() { return m_autor; }
	int getNExemplars() { return m_nExemplars; }

	bool prestar(const string &data, int &codiExemplar);
	bool retornar(const string &data, int codiExemplar);


private:
	string m_titol;
	string m_autor;
	int m_nExemplars;
	Exemplar *m_exemplars;
};

