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
	// Inicialitzaci� de la part gr�fica del joc
	// *******************************************
	//Inicialitza Part grafica
	Screen jocLib(MIDAX, MIDAY);
	
	//Mostrem finestra
	jocLib.show();
	
	
	
	// AFEGIR CODI: Definici� del grafic del fons

	// AFEGIR CODI: Definici� i inicialitzaci� de la matriu que representar� 
	// les caselles al tauler
	
	// Variables d'ajuda per agafar posici� ratol�
	int xMouse = 0;
	int yMouse = 0;


	do 
	{
		jocLib.processEvents();

		if (Mouse_getButLeft())
		{
			xMouse = Mouse_getX();
			yMouse = Mouse_getY();

			// AFEGIR CODI: Agafar posici� de la casella on s'ha clicat
			// S'haur� de controlar si el clic correspon a la casella origen o
			// a la casella final del moviment

			// AFEGIR CODI: Si ja hem clicat origen i dest�,
			// fer comprovaci� que el moviment sigui correcte i, si ho �es
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
