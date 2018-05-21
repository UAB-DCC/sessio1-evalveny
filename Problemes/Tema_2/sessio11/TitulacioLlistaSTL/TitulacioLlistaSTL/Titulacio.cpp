#include "Titulacio.h"
#include <iostream>
using namespace std;

bool Titulacio::buscaEstudiant(const string& niu, std::forward_list<Estudiant>::iterator& actual, std::forward_list<Estudiant>::iterator& anterior)
{
	bool trobat = false;
	bool existeix = true;

	anterior = m_estudiants.before_begin();
	actual = m_estudiants.begin();
	while ((actual != m_estudiants.end())&&!trobat&&existeix)
	{
		Estudiant estActual = *actual;
		if ((*actual).getNIU() == niu)
		{
			trobat = true;
		}
		else
		{
			if ((*actual).getNIU() > niu)
			{
				existeix = false;
			}
			else
			{
				anterior = actual;
				actual++;
			}
		}
	}
	return trobat;
}

bool Titulacio::afegeixEstudiant(Estudiant &e)
{
	bool trobat = false;
	std::forward_list<Estudiant>::iterator anterior; 
	std::forward_list<Estudiant>::iterator actual;
	
	trobat = buscaEstudiant(e.getNIU(),actual,anterior);

	if (!trobat)
	{
		m_estudiants.insert_after(anterior, e);
		m_nEstudiants++;
	}
	return !trobat;	
}

bool Titulacio::afegeixAssignaturaEstudiant(const string& niu, int codiAssig, int nCredits)
{
	bool trobat = false;
	bool inserida = false;
	std::forward_list<Estudiant>::iterator anterior;
	std::forward_list<Estudiant>::iterator actual;
	trobat = buscaEstudiant(niu, actual,anterior);
	if (trobat)
	{
		inserida = actual->afegeixAssignatura(codiAssig, nCredits);
	}
	return inserida;
}

void Titulacio::mostraEstudiants()
{
	std::forward_list<Estudiant>::iterator aux;
	for (aux = m_estudiants.begin(); aux != m_estudiants.end(); aux++)
		cout << (*aux).getNIU() << endl;
}

void Titulacio::eliminaEstudiants()
{
	std::forward_list<Estudiant>::iterator anterior = m_estudiants.before_begin();
	std::forward_list<Estudiant>::iterator actual = m_estudiants.begin();
	while (actual != m_estudiants.end())
	{
		Estudiant estActual = *actual;
		if (estActual.getNAssigActual() == 0)
		{
			actual = m_estudiants.erase_after(anterior);
			m_nEstudiants--;
		}
		else
		{
			anterior = actual;
			actual++;
		}
	}
}

void Titulacio::eliminaAssignatura(int codi)
{
	std::forward_list<Estudiant>::iterator anterior = m_estudiants.before_begin();
	std::forward_list<Estudiant>::iterator actual = m_estudiants.begin();
	while (actual != m_estudiants.end())
	{
		actual->eliminaAssignatura(codi);		
	}
	eliminaEstudiants();
}