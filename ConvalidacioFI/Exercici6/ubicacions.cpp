#include "ubicacions.h"
#include <math.h>


bool correcteGMS(int valor, int limit)
{
	return ((valor >= 0) && (valor <= limit));
}

bool omplePosicio(Posicio &pos, int graus, int minuts, int segons, char ref)
{
	bool correcte = true;
	if (correcteGMS(graus, 180) && correcteGMS(minuts, 60) && correcteGMS(segons, 60))
	{
		pos.graus = graus;
		pos.minuts = minuts;
		pos.segons = segons;
		pos.referencia = ref;
	}
	else
		correcte = false;
	return correcte;
}

bool ompleUbicacio(Ubicacio &ub, string descripcio, Posicio longitud, Posicio latitud)
{
	bool correcte = true;
	if (((longitud.referencia == 'E') || (longitud.referencia == 'O')) &&
		((latitud.referencia == 'N') || (latitud.referencia == 'S')))
	{
		ub.descripcio = descripcio;
		ub.longitud = longitud;
		ub.latitud = latitud;
	}
	else
		correcte = false;
	return correcte;
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

int cercaUbicacio(Ubicacio llistaUbicacions[], int nUbicacions, string descripcio)
{
	bool trobat = false;
	int i = 0;
	while ((i < nUbicacions) && !trobat)
	{
		if (llistaUbicacions[i].descripcio == descripcio)
			trobat = true;
		else
			i++;
	}
	if (trobat)
		return i;
	else
		return -1;
}

float distancia(Ubicacio llistaUbicacions[], int nUbicacions, string ubicacioOrigen, string ubicacioFinal)
{
	float distancia = -1;
	int posOrigen = cercaUbicacio(llistaUbicacions, nUbicacions, ubicacioOrigen);
	if (posOrigen != -1)
	{
		int posFinal = cercaUbicacio(llistaUbicacions, nUbicacions, ubicacioFinal);
		if (posFinal != -1)
		{
			distancia = distanciaUbicacions(llistaUbicacions[posOrigen], llistaUbicacions[posFinal]);
		}
	}
	return distancia;
}
