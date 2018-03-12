#include "Joc.h"

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

	Partida partida;
	partida.inicialitza();


	// ************************************************************
	// Inicialitzacions dels paràmetres del joc
	// ************************************************************

	int x = 0;
	int y = 0;

	do {
		jocLib.processEvents();


		if (Mouse_getButLeft())
		{
			x = Mouse_getX();
			y = Mouse_getY();
			partida.processaClick(x, y);
		}

		if (partida.getMovimentComplet())
		{
			bool check = partida.ferMoviment();
			if (check)
				partida.canviaTorn();
		}

		partida.visualitza();

		// Actualitza la pantalla
		jocLib.update();

		// ***********************************************************************
		// Sortirem del primer bucle si pressionem ESC o ens quedem sense vides
		// ***********************************************************************
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

}
