#pragma once
#include "Tauler.h"

class Partida
{
public:
	Partida();
	~Partida();
	void inicialitza();
	void processaClick(int xMouse, int yMouse);
	void visualitza(int torn, bool avis);
	int getTorn();
	void canviaTorn(int torn);
	bool getMovimentComplet();
	bool getMovimentInvalid();
	bool ferMoviment(int torn);
private:
	Tauler m_tauler;
	int m_torn;
	int m_nPecesBlanques;
	int m_nPecesNegres;
	int m_filaOrigen;
	int m_columnaOrigen;
	int m_filaDesti;
	int m_columnaDesti;
	bool m_origen;
	bool m_movimentComplet;
	bool m_movimentInvalid;
};
