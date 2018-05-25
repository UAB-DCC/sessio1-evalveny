#include "Carta.h"

Carta::Carta()
{
    //ctor
    m_valor = 0;
	m_pal = 0;
}

Carta::~Carta()
{
    //dtor
}

void Carta::setCarta(Carta& c)
{
	m_valor = c.m_valor;
	m_pal = c.m_pal;
}

void Carta::setCarta(int nouvalor, int noupal)
{
	m_valor = nouvalor;
	m_pal = noupal;
}

int Carta::getValor() const
{
	return m_valor;
}

int Carta::getPal() const
{
	return m_pal;
}

void Carta::escriuCarta() const
{
    cout << m_pal << " " << m_valor;

}
