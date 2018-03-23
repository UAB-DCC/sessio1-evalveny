#include "Descarrega.h"

std::ofstream& operator<< (std::ofstream& fitxer, const Descarrega &d)
{
	fitxer << d.getUsuari() << endl;
	fitxer << d.getData() << endl;
	fitxer << d.getTemps() << endl;
	fitxer << d.getValoracio() << endl;
	return fitxer;
}