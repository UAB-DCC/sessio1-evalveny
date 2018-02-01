//Definicions amb la variable d'activació de la llibreria gràfica, GRAPHICS
#include "Definitions.h"


//Includes de les llibreries gràfiques
#ifdef GRAPHICS
#define SDL_MAIN_HANDLED
#include "lib\libreria.h"
#include <windows.h>
#endif

//Mida del taulell
const int MIDA_TOTAL = 480;



int main(int argc, char* argv[])
{
#ifdef GRAPHICS
	// Declaració de l’objecte de la classe Screen amb una mida determinada
	Screen pantalla = Screen(MIDA_TOTAL, MIDA_TOTAL);

	// Inicialització de la variable “mao” amb el gràfic “mao.png”
	//imatge guardada al directori de treball del projecte
	Sprite mao = Sprite("mao.png");

	//Mostra la pantalla gràfica
	pantalla.show();

	//Dibuixa el maó dalt a l'esquerra de la pantalla
	mao.draw(0, 0); //(columna/fila)

	//Actualització de la pantalla                      	
	pantalla.update();
	
	//Espera 5s
	Sleep(5000);

	//Destrueix la pantalla tancant-la degudament
	pantalla.~Screen();
#endif

	return 0;
}

