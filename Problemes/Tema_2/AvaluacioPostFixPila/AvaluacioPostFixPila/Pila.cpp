#include "Pila.h"


Pila::~Pila()
{
	while (m_top != NULL)
	{
		Node* aux = m_top;
		m_top = m_top->getNext();
		delete aux;
	}
}


void Pila::push(int val)
{
	Node* aux = new Node;
	aux->setValor(val);
	aux->setNext(m_top);
	m_top = aux;
	aux = NULL;
}

void Pila::pop()
{
	Node* aux = m_top;
	m_top = aux->getNext();
	delete aux;
	aux = NULL;
}
