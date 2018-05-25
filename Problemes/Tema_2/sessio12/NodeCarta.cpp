#include "NodeCarta.h"

NodeCarta::NodeCarta()
{
    //ctor
    m_next = NULL;
}

NodeCarta::~NodeCarta()
{
    //dtor
    m_next = NULL;
}

void NodeCarta::setValor(Carta& c)
{
    m_valor.setCarta(c);
}

Carta& NodeCarta::getValor()
{
    return m_valor;
}

NodeCarta* NodeCarta::getNext() const
{
	return m_next;
}

void NodeCarta::setNext(NodeCarta* next)
{
	m_next = next;
}
