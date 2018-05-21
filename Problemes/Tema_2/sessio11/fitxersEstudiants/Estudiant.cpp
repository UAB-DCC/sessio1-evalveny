#include "Estudiant.h"
#include <iostream>
using namespace std;

bool Estudiant::buscaAssignatura(int codi, int& pos)
{
	//Afegir codi
}

bool Estudiant::afegeixAssignatura(int codi, int nCredits)
{
	
	//Afegir codi
}

void Estudiant::mostraAssignatures()
{
	for (int pos = 0; pos < m_nAssigActual; pos++)
	{
		cout << m_assignatures[pos].getCodi() << " " << m_assignatures[pos].getCredits() << endl;
	}
}
