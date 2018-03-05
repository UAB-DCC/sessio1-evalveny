//
//  ParitatParell.cpp
//  funcions de repàs
//

#include "ParitatParell.h"
#include <iostream>

using namespace std;


bool bitParitatParell (int* trama)
{
	int compteUns = 0;
	for (int i = 0; i <= 7; i++)
	{
		if (trama[i] == 1) {
			compteUns++;
		}
	}

	return (compteUns % 2 == 0);
}
