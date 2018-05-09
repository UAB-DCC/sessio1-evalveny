#include "Llibre.h"

class Biblioteca
{
public:
	Biblioteca() { m_nLlibres = 0; m_llibres = NULL; };
	~Biblioteca();

	void llegirLlibres(const string &nomFitxer);
	bool cercarLlibre(const string &titol, Llibre &llibre);
	int nombreLlibres() { return m_nLlibres; }
	
private:
	Llibre *m_llibres;
	int m_nLlibres;
};

