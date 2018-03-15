#include "Activitat.h"

Activitat::Activitat(string nom, int maximParticipants, int edatMinima, int edatMaxima, string dia, string hora)
{
	m_nom = nom;
	m_maximParticipants = maximParticipants;
	m_numParticipants = 0;
	m_edatMinima = edatMinima;
	m_edatMaxima= edatMaxima; 
	m_dia = dia;
	m_hora = hora;
}

void Activitat::copiaValor(const Activitat& a)
{
	m_nom = a.m_nom;
	m_maximParticipants = a.m_maximParticipants;
	m_edatMinima = a.m_edatMinima;
	m_edatMaxima = a.m_edatMaxima;
	m_dia = a.m_dia;
	m_hora = a.m_hora;
	m_numParticipants = a.m_numParticipants;
}
int Activitat::afegeixParticipant(const Usuari& u)
{
	int codiRetorn=0;
	int edatUsuari= u.getEdat();
	if ((edatUsuari >= m_edatMinima) && (edatUsuari <= m_edatMaxima))
	{
		string nom = u.getNom();
		if(buscaParticipant(nom))
		{
			codiRetorn = -2;
		}
		else
		{
			if (m_numParticipants < m_maximParticipants)
			{
				m_participants[m_numParticipants].copiaValor(u);
				m_numParticipants++;
			}
			else
			{
				codiRetorn = -3;
			}
		}
	}
	else
	{
		codiRetorn = -1;
	}
	return codiRetorn;
}

bool Activitat::buscaParticipant(string& nom)
{
	bool trobat = false;
	int i = 0;
	while( (!trobat)&&(i<m_numParticipants))
	{
		if (m_participants[i].getNom() == nom)
		{
			trobat = true;
		}
		else
		{
			i++;
		}
	}

	return trobat;
}