//
//  DiaGregoria.h
//  funcions de repàs
//

#ifndef repas_DiaGregoria_h
#define repas_DiaGregoria_h

#include <string>

using namespace std;

struct DiaGregoria {
	unsigned long dia;
	unsigned long mes;
	unsigned long any;
};

// exercici 2
void llegeixDia(DiaGregoria& diaCalendari);
bool esTraspas(DiaGregoria& diaCalendari);
bool esValid(DiaGregoria& diaCalendari);
int totalDies(DiaGregoria& diaCalendari);
int diferenciaDies(DiaGregoria& diaCalendari1, DiaGregoria& diaCalendari2);
int mesFrequent(DiaGregoria dates[], int nDates);

#endif