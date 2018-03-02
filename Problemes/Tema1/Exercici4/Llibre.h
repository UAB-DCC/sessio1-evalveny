#pragma once

#include <string>
using namespace std;

class Llibre
{
public:
	void setTitol(const string &titol) { m_titol = titol; }
	void setAutor(const string &autor) { m_autor = autor; }
	void setNExemplars(int nExemplars);
	string &getTitol() { return m_titol; }
	string &getAutor() { return m_autor; }
	int getNExemplars() { return m_nExemplars; }

	bool presta(int &codiExemplar);
	bool retorna(int codiExemplar);


private:
	static const int MAX_EXEMPLARS = 10;
	string m_titol;
	string m_autor;
	int m_nExemplars;
	bool m_exemplars[MAX_EXEMPLARS];
};

