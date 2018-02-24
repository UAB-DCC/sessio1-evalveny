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
	
	
	
	// AFEGIR CODI: Definició del grafic del fons

	// AFEGIR CODI: Definició i inicialització de la matriu que representarà 
	// les caselles al tauler
	
	// Variables d'ajuda per agafar posició ratolí
	int xMouse = 0;
	int yMouse = 0;


	do 
	{
		jocLib.processEvents();

		if (Mouse_getButLeft())
		{
			xMouse = Mouse_getX();
			yMouse = Mouse_getY();

			// AFEGIR CODI: Agafar posició de la casella on s'ha clicat
			// S'haurà de controlar si el clic correspon a la casella origen o
			// a la casella final del moviment

			// AFEGIR CODI: Si ja hem clicat origen i destí,
			// fer comprovació que el moviment sigui correcte i, si ho ´es
			// fer el moviment
						
		}


		// AFEGIR CODI: Pintem Fons

		// AFEGIR CODI: Pintem peces sobre el tauler

		// Actualitza la pantalla
		jocLib.update();

		// ***********************************************************************
		// Sortim del bucle si pressionem ESC
		// ***********************************************************************
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

}
