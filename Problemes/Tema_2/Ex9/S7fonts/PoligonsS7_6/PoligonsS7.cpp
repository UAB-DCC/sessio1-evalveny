// PoligonsS7.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Poligon.h"
#include <iostream>

using namespace std;

int main()
{
	string nomf;
	Punt pt;

	Poligon pol;
	pol.init("vertexs.txt");
	pol.escriu();
	pol.centroid(&pt);
	cout << pt.getX() <<" " << pt.getY() <<endl;

	system("pause");

    return 0;
}

