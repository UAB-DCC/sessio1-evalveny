#include "Estudiant.h"
#include <iostream>
using namespace std;

bool Estudiant::buscaAssignatura(int codi, std::forward_list<AssignaturaExpedient>::iterator& actual, std::forward_list<AssignaturaExpedient>::iterator& anterior)
{
	bool trobat = false;
	bool existeix = true;
	anterior = m_assignatures.before_begin();
	actual = m_assignatures.begin();
	while ((actual != m_assignatures.end()) && (!trobat)&&existeix)
	{
		if (codi == actual->getCodi())
		{
			trobat = true;
		}
		else
		{
			if (codi > actual->getCodi())
				existeix = false;
			else
			{
				anterior = actual;
				actual++;
			}
		}
	}
	return trobat;
}

bool Estudiant::afegeixAssignatura(int codi, int nCredits)
{
	bool trobat = false;
	std::forward_list<AssignaturaExpedient>::iterator anterior;
	std::forward_list<AssignaturaExpedient>::iterator actual;
	
	trobat = buscaAssignatura(codi,actual,anterior);
	if (!trobat)
	{
		m_assignatures.insert_after(anterior, AssignaturaExpedient(codi, nCredits));
		m_nAssignatures++;
	}
	
	return !trobat;
}

void Estudiant::mostraAssignatures()
{
	std::forward_list<AssignaturaExpedient>::iterator aux;
	for (aux = m_assignatures.begin(); aux != m_assignatures.end(); aux++)
		cout << (*aux).getCodi() << " " << (*aux).getCredits() << endl;	
}

bool Estudiant::eliminaAssignatura(int codi)
{
	bool trobat = false;
	std::forward_list<AssignaturaExpedient>::iterator anterior;
	std::forward_list<AssignaturaExpedient>::iterator actual;

	trobat = buscaAssignatura(codi, actual, anterior);
	if (trobat)
	{
		actual = m_assignatures.erase_after(anterior);
		m_nAssignatures--;
	}

    return trobat;	
}