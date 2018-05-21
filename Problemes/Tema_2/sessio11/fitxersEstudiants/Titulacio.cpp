#include "Titulacio.h"
#include <iostream>
using namespace std;

bool Titulacio::buscaEstudiant(const string& niu, std::forward_list<Estudiant>::iterator& actual, std::forward_list<Estudiant>::iterator& anterior)
{
	//afegir codi
}

//Aquest metode el modificareu amb bescarEstudiant
bool Titulacio::afegeixEstudiant(Estudiant &e)
{
	bool trobat = false;
	std::forward_list<Estudiant>::iterator anterior = m_estudiants.before_begin();
	std::forward_list<Estudiant>::iterator actual = m_estudiants.begin();
	while ((actual != m_estudiants.end()) && (!trobat))
	{
		Estudiant estActual = *actual;
		if (e.getNIU() < estActual.getNIU())
			trobat = true;
		else
		{
			anterior = actual;
			actual++;
		}
	}
	if (!trobat)
	{
		m_estudiants.insert_after(anterior, e);
		m_nEstudiants++;
	}
	return trobat;
}



bool Titulacio::afegeixAssignaturaEstudiant(const string& niu, int codiAssig, int nCredits)
{
	//Afegir codi
}

void Titulacio::mostraEstudiants()
{
	std::forward_list<Estudiant>::iterator aux;
	for (aux = m_estudiants.begin(); aux != m_estudiants.end(); aux++)
		cout << (*aux).getNIU() << endl;
}

void Titulacio::eliminaEstudiants()
{
	//Afegir codi
}
