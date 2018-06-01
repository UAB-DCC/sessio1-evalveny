#include "CuaTelefons.h"

CuaTelefons::CuaTelefons()
{
	m_telefons = new string[MIDAINICIAL];
	m_mida = MIDAINICIAL;
	m_posIni = 0;
	m_posFi = 0;
	m_numElements=0;
}

CuaTelefons::~CuaTelefons()
{
	delete[] m_telefons;
}

void CuaTelefons::addTfn(string tfn)
{
	if (m_numElements == m_mida)
	{
		m_mida = m_mida * 2;
		string* aux = new string[m_mida];
		int posActual = m_posIni;
		for (int i = 0; i < m_numElements; i++)
		{
			aux[i] = m_telefons[posActual];
			posActual = (posActual + 1) % (m_mida / 2);
		}
		delete[] m_telefons;
		m_telefons = aux;
		aux = NULL;		
		m_posFi = m_numElements;
		m_posIni = 0;
	}
	m_telefons[m_posFi] = tfn;
	m_posFi=(m_posFi+1)%m_mida;
	m_numElements++;
}

string& CuaTelefons::getTfn()
{
	int pos = m_posIni;
	m_posIni = (m_posIni + 1) % m_mida;
	m_numElements--;
	return m_telefons[pos];
}
void CuaTelefons::eliminaTot()
{
	delete[] m_telefons;
	m_telefons = new string[MIDAINICIAL];
	m_mida = MIDAINICIAL;
	m_posIni = 0;
	m_posFi = 0;
	m_numElements = 0;
}