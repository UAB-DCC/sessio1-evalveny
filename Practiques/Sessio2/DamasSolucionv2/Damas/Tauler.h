#pragma once
#include "lib/libreria.h"

const int MIDATAULER = 8;

//========================================================================
// Mida Pantalla
const int MIDAX = 624;
const int MIDAY = 680;

//========================================================================
// Inici del taulell respecte la cantonada superior esquerre
const int INIPANTALLAX = 0;
const int INIPANTALLAY = 58;

//========================================================================
// Fi del taulell respecte la cantonada inferior dreta
const int FIPANTALLAX = 624;
const int FIPANTALLAY = 680;
const int MIDACASELLA = 78;

const int POSICIO_TORN_X = 120;
const int POSICIO_TORN_Y = 10;
const int POSICIO_AVIS_X = 250;
const int POSICIO_AVIS_Y = 10;

const int TORN_BLANC = 1;
const int TORN_NEGRE = 2;

const int FITXA_BLANCA = 1;
const int FITXA_NEGRA = 2;
const int FITXA_BLANCA_SEL = 11;
const int FITXA_NEGRA_SEL = 22;

class Tauler
{
public:
	Tauler();
	~Tauler();
	void inicialitza();
	void dibuixa(int torn, bool avis);
	bool validaClick(int x, int y, int(&fila), int(&columna));
	bool processaMoviment(int filaorigen, int columnaorigen, int filadestino, int columnadestino, int torn);
	void marcaCasella(int(fila), int(columna), int torn);
	bool checkOrigenValid(int m_filaOrigen, int m_columnaOrigen, int torn);
private:
	Sprite m_fitxaBlanca;
	Sprite m_fitxaNegra;
	Sprite m_fitxaBlancaSel;
	Sprite m_fitxaNegraSel;
	Sprite m_fons;
	Sprite m_avis;
	Sprite m_tornBlanc;
	Sprite m_tornNegre;
	int m_matriuEstat[MIDATAULER][MIDATAULER] = { { 0,2,0,2,0,2,0,2 },{ 2,0,2,0,2,0,2,0 },{ 0,2,0,2,0,2,0,2 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 1,0,1,0,1,0,1,0 },{ 0,1,0,1,0,1,0,1 },{ 1,0,1,0,1,0,1,0 } };;
};
