#include "ubicacions.h"
#include <math.h>


bool omplePosicio(Posicio &pos, int graus, int minuts, int segons, char ref)
{
}

bool ompleUbicacio(Ubicacio &ub, string descripcio, Posicio longitud, Posicio latitud)
{
}

float posicioToRad(Posicio pos)
{
	const float PI = 3.14159265358979323846;
	float valor = ((float)pos.graus + (((float)pos.minuts + ((float)pos.segons / 60.0))) / 60.0);
	valor = valor * PI / 180;
	if ((pos.referencia == 'N') || (pos.referencia == 'E'))
		return valor;
	else
		return -valor;
}

float distanciaUbicacions(Ubicacio &ubicacioOrigen, Ubicacio &ubicacioFinal)
{
	float latitudOrigenRadians = posicioToRad(ubicacioOrigen.latitud);
	float longitudOrigenRadians = posicioToRad(ubicacioOrigen.longitud);
	float latitudFinalRadians = posicioToRad(ubicacioFinal.latitud);
	float longitudFinalRadians = posicioToRad(ubicacioFinal.longitud);

	const float RADI_TERRA = 6378.137;
	float dLatitud = latitudFinalRadians - latitudOrigenRadians;
	float dLongitud = longitudFinalRadians - longitudOrigenRadians;

	float aux = sin(dLatitud / 2) * sin(dLatitud / 2) + cos(latitudOrigenRadians) * cos(latitudFinalRadians) * sin(dLongitud / 2) * sin(dLongitud / 2);
	float distancia = RADI_TERRA * 2 * atan2(sqrt(aux), sqrt(1 - aux));

	return distancia;
}

float distancia(Ubicacio llistaUbicacions[], int nUbicacions, string ubicacioOrigen, string ubicacioFinal)
{
}
