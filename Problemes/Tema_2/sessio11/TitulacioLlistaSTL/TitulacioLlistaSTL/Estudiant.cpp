#include "Estudiant.h"
#include <iostream>
using namespace std;

bool Estudiant::buscaAssignatura(int codi, int& pos)
{
	bool trobat = false;
	pos = 0;
	
	while ((pos <= m_nAssigActual) && (!trobat))
	{
		if (codi == m_assignatures[pos].getCodi())
		{
			trobat = true;
		}
		else
		{
			pos++;			
		}
	}
	return trobat;
}

bool Estudiant::afegeixAssignatura(int codi, int nCredits)
{
	bool inserit = false;
	
	if (m_nAssigActual < MAX_ASSIGNATURES)
	{
		bool trobat = false;
		int pos;
		trobat = buscaAssignatura(codi, pos);
		if (!trobat)
		{
			m_assignatures[m_nAssigActual].setCodi(codi);
			m_assignatures[m_nAssigActual].setCredits(nCredits);
			m_nAssigActual++;
			inserit = true;
		}
	}

	return inserit;
}

void Estudiant::mostraAssignatures()
{
	for (int pos = 0; pos < m_nAssigActual; pos++)
	{
		cout << m_assignatures[pos].getCodi() << " " << m_assignatures[pos].getCredits() << endl;
	}
}

bool Estudiant::eliminaAssignatura(int codi)
{
	bool trobat = false;
	int posAct;
	trobat = buscaAssignatura(codi, posAct);
	if (trobat)
	{
		for (int pos = posAct; pos < m_nAssigActual-1; pos++)
		{
			m_assignatures[pos]=m_assignatures[pos + 1];
		}
		m_nAssigActual--;
	}
    return trobat;	
}