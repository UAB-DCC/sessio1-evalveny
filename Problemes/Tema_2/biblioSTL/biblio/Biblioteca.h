#include "Llibre.h"

class Biblioteca
{
public:
	Biblioteca() { m_nLlibres = 0; };
	~Biblioteca();

	void llegirLlibres(const string &nomFitxer);
	bool cercarLlibre(const string &titol, Llibre &llibre);
	int nombreLlibres() { return m_nLlibres; }
	
private:
	std::forward_list<Llibre> m_llibres;
	int m_nLlibres;
};

