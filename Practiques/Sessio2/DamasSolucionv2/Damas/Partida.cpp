#include "Partida.h"

Partida::Partida()
{
}


Partida::~Partida()
{
}

void Partida::inicialitza()
{
	m_torn = TORN_BLANC;
	m_nPecesBlanques = 12;
	m_nPecesNegres = 12;
	m_filaOrigen = 0;
	m_columnaOrigen = 0;
	m_filaDesti = 0;
	m_columnaDesti = 0;
	m_tauler.inicialitza();
	m_origen = true;
	m_movimentComplet = false;
	m_movimentInvalid = false;
}

void Partida::processaClick(int xMouse, int yMouse)
{
	bool retornvalida;
	bool origenvalid;

	if (m_movimentInvalid)
		m_movimentInvalid = false;

	if (m_origen)
	{
		retornvalida = m_tauler.validaClick(xMouse, yMouse, m_filaOrigen, m_columnaOrigen);
		if (retornvalida)
		{
			origenvalid = m_tauler.checkOrigenValid(m_filaOrigen, m_columnaOrigen, m_torn);
			if (origenvalid)
			{
				m_origen = false;
				m_tauler.marcaCasella(m_filaOrigen, m_columnaOrigen, m_torn);
			}
			else
				m_movimentInvalid = true;
		}
		else
		{
			m_movimentInvalid = true;
		}
	}
	else
	{
		retornvalida = m_tauler.validaClick(xMouse, yMouse, m_filaDesti, m_columnaDesti);
		if (retornvalida)
		{
			m_origen = true;
			m_movimentComplet = true;
		}

	}

}
void Partida::visualitza()
{
	m_tauler.dibuixa(m_torn, m_movimentInvalid);
}

bool Partida::ferMoviment()
{
	bool check = m_tauler.processaMoviment(m_filaOrigen, m_columnaOrigen, m_filaDesti, m_columnaDesti, m_torn);
	if (check)
	{
		m_filaOrigen = 0;
		m_columnaOrigen = 0;
		m_filaDesti = 0;
		m_columnaDesti = 0;
		m_movimentComplet = false;
		return true;
	}
	else
	{
		m_movimentInvalid = true;
		m_filaOrigen = 0;
		m_columnaOrigen = 0;
		m_filaDesti = 0;
		m_columnaDesti = 0;
		m_movimentComplet = false;
		return false;
	}
}

bool Partida::getMovimentComplet()
{
	return m_movimentComplet;
}

void Partida::canviaTorn()
{
	m_movimentComplet = false;
	if (m_torn == TORN_BLANC)
		m_torn = TORN_NEGRE;
	else
		m_torn = TORN_BLANC;
}
