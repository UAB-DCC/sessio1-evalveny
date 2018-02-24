#include "Joc.h"

void getPosMatrix(int x, int y, int(&fila), int(&columna))
{
	if ((x >= INIPANTALLAX) && (y >= INIPANTALLAY))
	{
		columna = (x - INIPANTALLAX) / MIDACASELLA;
		fila = (y - INIPANTALLAY) / MIDACASELLA;
		columna = columna + 1;
		fila = fila + 1;
	}
	else
	{
		columna = 0;
		fila = 0;
	}
	printf("Columna Fila %d %d \n", fila, columna);
}

void dibuixarPeces(int estatinicial[8][8])
{
	Sprite fitxa_blanca;
	fitxa_blanca.create("data/fitxa_blanca.png");

	Sprite fitxa_negra;
	fitxa_negra.create("data/fitxa_negra.png");

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (estatinicial[j][i] == 1)
			{
				fitxa_blanca.draw(INIPANTALLAX + i * MIDACASELLA, INIPANTALLAY + j * MIDACASELLA);
			}
			if (estatinicial[j][i] == 2)
			{
				fitxa_negra.draw(INIPANTALLAX + i * MIDACASELLA, INIPANTALLAY + j * MIDACASELLA);
			}
		}
	}
}

void checkMovementPiece(int &fila, int &columna, int &filaantes, int &columnaantes, int (&estatinicial)[8][8])
{
	int color = estatinicial[filaantes - 1][columnaantes - 1];
	int difx = fila - filaantes;
	int dify = columna - columnaantes;
	//printf("Color difx dify %d %d %d \n", color, difx, dify);
	// ficha negra
	if (estatinicial[fila - 1][columna - 1] == 0)
	{
		if (color == 2)
		{
			if ((difx == 1) && ((dify == 1) || (dify == -1)))
			{
				estatinicial[fila - 1][columna - 1] = 2;
				estatinicial[filaantes - 1][columnaantes - 1] = 0;
			}
		}
		else if (color == 1)
		{
			if ((difx == -1) && ((dify == 1) || (dify == -1)))
			{
				estatinicial[fila - 1][columna - 1] = 1;
				estatinicial[filaantes - 1][columnaantes - 1] = 0;
			}

		}
	}
	fila = 0;
	columna = 0;
	filaantes = 0;
	columnaantes = 0;
}

//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc()
{
	// ********************************************
	// Inicialització de la part gràfica del joc
	// *******************************************
	//Inicialitza Part grafica
	Screen jocLib(MIDAX, MIDAY);
	//Mostrem finestra
	jocLib.show();


	// Assignacio del grafic del fons
	// Veiem dues maneres d'assignar una imatge.
	// Aqui primer la definim i despres li assignem una imatge
	Sprite fons;
	fons.create("data/tauler.png");

	int estatinicial[8][8] = { { 0,2,0,2,0,2,0,2 },{ 2,0,2,0,2,0,2,0 },{ 0,2,0,2,0,2,0,2 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 1,0,1,0,1,0,1,0 },{ 0,1,0,1,0,1,0,1 },{ 1,0,1,0,1,0,1,0 } };
	int x = 0;
	int y = 0;
	int cont = 2;

	int fila = 0;
	int columna = 0;
	int filaantes = 0;
	int columnaantes = 0;
	bool checkValid=false;

	do {
		jocLib.processEvents();

		if (Mouse_getButLeft())
		{
			x = Mouse_getX();
			y = Mouse_getY();
			if (cont == 2)
			{	
				getPosMatrix(x, y, fila,columna);
				if (estatinicial[fila - 1][columna - 1] > 0)
				{
					filaantes = fila;
					columnaantes = columna;
					cont--;
				}
			}
			else if (cont == 1)
			{
				getPosMatrix(x, y, fila, columna);
				checkMovementPiece(fila, columna, filaantes, columnaantes, estatinicial);
				cont = 2;
			}
		}

		// TO DO: MOVER FICHA POR TABLERO, SI ESTÁ VACÍA SE DESPLAZA, MOVERSE DE UNA LADO A OTRO
		// SESIÓN 2: CREAR CLASE TABLERO, INICIALIZACIÓN, CONCEPTO DE JUEGO Y JUGADOR 1 Y 2
		// TABLERO: CONSTRUCTOR, DIBUJO
		// MOVIMIENTO ERRONEO UN SPRITE MOVIMIENTO ERRONEO Y SE VUELVE AL TURNO

		//Pintem Fons
		fons.draw(0, 0);

		dibuixarPeces(estatinicial);

		// Actualitza la pantalla
		jocLib.update();

		// ***********************************************************************
		// Sortirem del bucle si pressionem ESC 
		// ***********************************************************************
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

}
