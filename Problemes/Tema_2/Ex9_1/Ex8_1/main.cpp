
#include "Poligon.h"

int main()
{
	Poligon poligon1;
	Poligon  poligon2;
	
	poligon1.init("pols0.txt");

	poligon1.escriu();

	poligon2 = poligon1;
	
	poligon2.escriu();

	poligon2.init("pols1.txt");

	poligon2.escriu();

	return 0;
}