#include "Tauler.h"

Tauler::Tauler()
{
}


Tauler::~Tauler()
{
}

void Tauler::inicialitza()
{
	m_fons.create("data/tauler.png");
	m_fitxaBlanca.create("data/fitxa_blanca.png");
	m_fitxaNegra.create("data/fitxa_negra.png");
	m_tornBlanc.create("data/torn_blanc.png");
	m_tornNegre.create("data/torn_negre.png");
	m_fitxaBlancaSel.create("data/fitxa_blanca_sel.png");
	m_fitxaNegraSel.create("data/fitxa_negra_sel.png");
	m_avis.create("data/avis_error.png");
}

void Tauler::dibuixa(int torn, bool avis)
{

	m_fons.draw(0, 0);

	for (int i = 0; i < MIDATAULER; i++)
	{
		for (int j = 0; j < MIDATAULER; j++)
		{
			if (m_matriuEstat[j][i] == FITXA_BLANCA)
			{
				m_fitxaBlanca.draw(INIPANTALLAX + i * MIDACASELLA, INIPANTALLAY + j * MIDACASELLA);
			}
			if (m_matriuEstat[j][i] == FITXA_BLANCA_SEL)
			{
				m_fitxaBlancaSel.draw(INIPANTALLAX + i * MIDACASELLA, INIPANTALLAY + j * MIDACASELLA);
			}
			if (m_matriuEstat[j][i] == FITXA_NEGRA)
			{
				m_fitxaNegra.draw(INIPANTALLAX + i * MIDACASELLA, INIPANTALLAY + j * MIDACASELLA);
			}
			if (m_matriuEstat[j][i] == FITXA_NEGRA_SEL)
			{
				m_fitxaNegraSel.draw(INIPANTALLAX + i * MIDACASELLA, INIPANTALLAY + j * MIDACASELLA);
			}
		}
	}
	if (torn == TORN_BLANC)
		m_tornBlanc.draw(POSICIO_TORN_X, POSICIO_TORN_Y);
	else
		m_tornNegre.draw(POSICIO_TORN_X, POSICIO_TORN_Y);

	if (avis)
		m_avis.draw(POSICIO_AVIS_X, POSICIO_AVIS_Y);
}


bool Tauler::validaClick(int x, int y, int(&fila), int(&columna))
{
	if ((x >= INIPANTALLAX) && (x <= FIPANTALLAX) && (y >= INIPANTALLAY) && (y <= FIPANTALLAX))
	{
		columna = (x - INIPANTALLAX) / MIDACASELLA;
		fila = (y - INIPANTALLAY) / MIDACASELLA;
		columna = columna + 1;
		fila = fila + 1;
		printf("Columna Fila %d %d \n", fila, columna);
		return true;
	}
	else
		return false;
}

void Tauler::marcaCasella(int(fila), int(columna), int torn)
{
	if (torn == TORN_BLANC)
		m_matriuEstat[fila - 1][columna - 1] = FITXA_BLANCA_SEL;
	else
		m_matriuEstat[fila - 1][columna - 1] = FITXA_NEGRA_SEL;
}

bool Tauler::processaMoviment(int filaOrigen, int columnaOrigen, int filaDesti, int columnaDesti, int torn)
{
	int color = m_matriuEstat[filaOrigen - 1][columnaOrigen - 1];
	int difx = filaDesti - filaOrigen;
	int dify = columnaDesti - columnaOrigen;
	bool retorno = false;
	if (((color == FITXA_BLANCA_SEL) && (torn == TORN_BLANC)) | ((color == FITXA_NEGRA_SEL) && (torn == TORN_NEGRE)))
	{
		if (m_matriuEstat[filaDesti - 1][columnaDesti - 1] == 0)
		{
			if (color == FITXA_NEGRA_SEL)
			{
				if ((difx == 1) && ((dify == 1) || (dify == -1)))
				{
					m_matriuEstat[filaDesti - 1][columnaDesti - 1] = FITXA_NEGRA;
					m_matriuEstat[filaOrigen - 1][columnaOrigen - 1] = 0;
					retorno = true;
				}
			}
			else if (color == FITXA_BLANCA_SEL)
			{
				if ((difx == -1) && ((dify == 1) || (dify == -1)))
				{
					m_matriuEstat[filaDesti - 1][columnaDesti - 1] = FITXA_BLANCA;
					m_matriuEstat[filaOrigen - 1][columnaOrigen - 1] = 0;
					retorno = true;
				}

			}
		}
	}
	if (!retorno)
	{
		if (torn == TORN_BLANC) m_matriuEstat[filaOrigen - 1][columnaOrigen - 1] = FITXA_BLANCA;
		else m_matriuEstat[filaOrigen - 1][columnaOrigen - 1] = FITXA_NEGRA;

	}
	return retorno;
}

bool Tauler::checkOrigenValid(int filaO, int columnaO, int torn)
{
	if (m_matriuEstat[filaO - 1][columnaO - 1] == torn)
		return true;
	else
		return false;

}