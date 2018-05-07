
#include "Poligon.h"

int main()
{
	Poligon poligon0;
	Poligon  poligon1;
	cout << "POLIGON 0" << endl;
	cout << "=========" << endl;
	poligon0.init("pols0.txt");

	poligon0.escriu();

	poligon1 = poligon0;
	
	cout << "POLIGON 1" << endl;
	cout << "=========" << endl;
	poligon1.escriu();
	cout << "POLIGON 1" << endl;
	cout << "=========" << endl;
	poligon1.init("pols1.txt");

	poligon1.escriu();

	return 0;
}