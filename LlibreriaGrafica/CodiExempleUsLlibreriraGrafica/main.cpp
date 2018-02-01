// main.cpp: Exemple d'ús de la llibreria gràfica on es llegeix un fitxer d'entrada es mou un mao
// com s'indica al fitxer i s'escriu el recorregut realitzat en un fitxer.
//

//Definicions amb la variable d'activació de la llibreria gràfica, __viz_graphics__
#include "Definitions.h"

//Includes de les llibreries gràfiques
#ifdef GRAPHICS
	#define SDL_MAIN_HANDLED 
	#include "lib\libreria.h"
	#include <windows.h>
#endif 

#include <iostream>
#include <fstream>

//Mida del taulell
const int MIDA_TAULELL = 480;

//Numero de caselles i moviments
const int CASELLES = 8;
const int MOVIMENTS = 7;

//Funció per la lectura de la posició inicial del maó
void readInitialPosition(const std::string& filename, int *X, int *Y)
{
	std::ifstream file;
	file.open(filename.c_str()); //filename.c_str
	if (file.is_open())
	{
		file >> *X >> *Y;
		file.close();
	}
	else
	{
		std::cout << "error: file not found" << std::endl;
	}
}

//Funció per a guardar el fitxer de sortida amb els moviments
void writeExitPath(const std::string& filename, int X[], int Y[], int lengthMov)
{
	std::ofstream fileOut;
	fileOut.open(filename.c_str());
	if (fileOut.is_open())
	{
		for (int i = 0; i < lengthMov; i++)
		{
			fileOut << X[i] << " " << Y[i] << std::endl;
		}
		fileOut.close();
	}
	else
	{
		std::cout << "error: file not found" << std::endl;
	}
}



int main(int argc, char* argv[])
{
	//Arxius per llegir i escriure per paràmetre
	if (argc == 3) 
	{

		#ifdef GRAPHICS
			// Declaració i instanciació de l’objecte de la classe Screen amb un tamany determinat
			Screen pantalla = Screen(MIDA_TAULELL, MIDA_TAULELL);

			// Inicialització de la variable “mao” amb el gràfic “mao.png” 
			Sprite mao = Sprite("mao.png");
			// Inicialització de la variable “cbuida” amb el gràfic “cnegre.png” 
			Sprite cbuida = Sprite("cnegre.png");
		#endif

		//Declaració variables per la posició del maó
		int posX = 0;
		int	posY = 0;
		readInitialPosition(argv[1], &posX, &posY); 
		
		//Inicialització dels vectors per guardar el camí X,Y
		int pathX[MOVIMENTS];
		int pathY[MOVIMENTS];

		#if GRAPHICS
			//Pantalla gràfica
			pantalla.show();
			//Dibuixa el maó
			mao.draw(posX * mao.getScaleY(), posY * mao.getScaleX()); //(columna/fila)

			//Actualització de la pantalla				
			pantalla.update();
			Sleep(500);
		#endif

		//guardem posició inicial
		pathX[0]=posX;
		pathY[0]=posY;
		
		//Bucle principal del joc
		do {
			#if GRAPHICS
				//Dibuix de la nova posició del maó i casella buida a l'anterior posició
				cbuida.draw(posX * cbuida.getScaleX(), (posY)* cbuida.getScaleX());
				mao.draw(posX * mao.getScaleX(), (posY + 1) * mao.getScaleX());

				pantalla.update();
				Sleep(500);
			#endif

			//Actualitza i guarda la nova posició 
			pathX[posY]=posX;
			pathY[posY]=posY;
			posY++;

		} while (posY <= MOVIMENTS-1);

		//Guardem els punts X,Y del camí seguit
		writeExitPath(argv[2], pathX, pathY, MOVIMENTS); 

		#if GRAPHICS
			//Instruccio necesaria per poder finalitzar els gràfics de la pantalla
			pantalla.~Screen();
		#endif
	}
	return 0;
}
