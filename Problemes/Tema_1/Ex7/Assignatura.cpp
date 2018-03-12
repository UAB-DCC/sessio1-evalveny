#include "Assignatura.h"


void Assignatura::afegeixEstudiant (const Estudiant &e)
{
	if (m_nEstudiants < (MAXESTUDIANTS))
	{
		m_estudiants[m_nEstudiants].setNom(e.getNom());
		m_estudiants[m_nEstudiants].setNota(e.getNota());
		m_nEstudiants++;
	}
}
void Assignatura::calculaHistograma() 
{
	for (int i = 0; i < m_nEstudiants; i++)
	{
		m_histograma.registra(m_estudiants[i].getNota());
	}
}

int Assignatura::notaMesRepetida() const
{
	int posMaxim = 0;
	for (int i = 1; i < RANG_NOTES; i++)
	{
		if (m_histograma.getValor(i) > m_histograma.getValor(posMaxim))
			posMaxim = i;
	}
	return posMaxim;
}