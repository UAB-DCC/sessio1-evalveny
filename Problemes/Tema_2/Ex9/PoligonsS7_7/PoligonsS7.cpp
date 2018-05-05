// PoligonsS7.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "ConjuntPoligons.h"
#include <iostream>

using namespace std;

int main()
{
	string nomf;
	ConjuntPoligons cjtPol;

	cjtPol.init(3,"pols");
	
	Punt pt;

	cjtPol.escriu();

	cjtPol.calculaEscriuCentroid();

	system("pause");

    return 0;
}

