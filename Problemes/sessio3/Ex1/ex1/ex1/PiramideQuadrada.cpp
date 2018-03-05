/*
FALTA TEST SET
*/

#include "PiramideQuadrada.h"
#include <math.h>

PiramideQuadrada::PiramideQuadrada()
{
}

void PiramideQuadrada::setLongitud(float longitud)
{
	_longitud = longitud;
}

void PiramideQuadrada::setAlcada(float alcada)
{
	_alcada = alcada;
}

bool PiramideQuadrada::esValid()
{
	return ((_longitud >= 0) && (_alcada >= 0) );
}

float PiramideQuadrada::volum()
{
	return (pow(_longitud, 2) * _alcada) / (float)3;
}

float PiramideQuadrada::area()
{
	float l2 = pow(_longitud, 2);
	return l2 + (_longitud * sqrt(l2 + pow(2 * _alcada, 2)));
}
