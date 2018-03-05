
#include "Racional.h"


NombreRacional::NombreRacional()
{
}

void NombreRacional::setNumerador(int numerador)
{
	_numerador = numerador;
}

void NombreRacional::setDenominador(int denominador)
{
	_denominador = denominador;
}

int NombreRacional::getNumerador()
{
	return _numerador;
}

int NombreRacional::getDenominador()
{
	return _denominador;
}

bool NombreRacional::esValid()
{
	return (_denominador != 0);
}

float NombreRacional::decimal()
{
	return (_numerador / (float) _denominador);
}

void NombreRacional::suma(NombreRacional b)
{
	_numerador = (_numerador * b._denominador) + (_denominador * b._numerador);
	_denominador = _denominador * b._denominador;
}

void NombreRacional::multiplica(NombreRacional b)
{
	_numerador = _numerador * b._numerador;
	_denominador = _denominador * b._denominador;
}

void NombreRacional::resta(NombreRacional b)
{
	int tmpDenominador = _denominador;

	_numerador = (_numerador * b._denominador) - (_denominador * b._numerador);
	_denominador = _denominador * b._denominador;
}

void NombreRacional::divideix(NombreRacional b)
{
	_numerador = _numerador * b._denominador;
	_denominador = _denominador * b._numerador;
}


