#pragma once
#include <string>

using namespace std;

typedef struct
{
	int graus, minuts, segons;
	char referencia;
} Posicio;

typedef struct
{
	string descripcio;
	Posicio longitud;
	Posicio latitud;
} Ubicacio;

bool omplePosicio(Posicio &pos, int graus, int minuts, int segons, char ref);
bool ompleUbicacio(Ubicacio &ub, string descripcio, Posicio longitud, Posicio latitud);

float distanciaUbicacions(Ubicacio &ubicacioOrigen,	Ubicacio & ubicacioFinal);
float distancia(Ubicacio llistaUbicacions[], int nUbicacions, string ubicacioOrigen, string ubicacioFinal);
