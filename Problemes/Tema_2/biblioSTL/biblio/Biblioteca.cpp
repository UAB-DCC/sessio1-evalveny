#include "Biblioteca.h"
#include <fstream>
using namespace std;

Biblioteca::~Biblioteca()
{
	
}

void Biblioteca::llegirLlibres(const string &nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer.c_str());
	
	if (fitxer.is_open())
	{
		string titol, autor;
		int nExemplars;
					
		fitxer >> titol >> autor >> nExemplars;
		std::forward_list<Llibre>::iterator actual = m_llibres.before_begin();
		while (!fitxer.eof())
		{
			Llibre l;
			l.setAutor(autor);
			l.setTitol(titol);
			l.setNExemplars(nExemplars);
			actual=m_llibres.insert_after(actual,l);
			m_nLlibres++;
			fitxer >> titol >> autor >> nExemplars;
		}
		fitxer.close();
	}
}


bool Biblioteca::cercarLlibre(const string &titol, Llibre &llibre)
{
	bool trobat = false;
	std::forward_list<Llibre>::iterator actual = m_llibres.begin();
	
	while (!trobat && (actual!= m_llibres.end()))
	{
		if (titol == actual->getTitol())
		{
			llibre = *actual;
			trobat = true;
		}
		else
			actual++;
	}
			
	return trobat;
}