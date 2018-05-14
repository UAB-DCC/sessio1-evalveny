

#include "Llista.h"

Llista::Llista()
{
    //ctor
     m_primer = NULL;
}

Llista::~Llista()
{
    //dtor
	while (m_primer != NULL)
		eliminaNext(NULL);
}

bool Llista::esBuida() const
{
    return (m_primer == NULL);
}

Node *Llista::getInici() const
{
    return m_primer;
}


Node *Llista::insereixNext(const int& valor, Node *posicio)
{
	Node* aux = new Node;
	if (aux != NULL)
	{
		aux->setValor(valor);
		if (posicio == NULL)
		{
			aux->setNext(m_primer);
			m_primer = aux;
		}
		else
		{
			aux->setNext(posicio->getNext());
			posicio->setNext(aux);
		}
	}
	return aux;
}

Node *Llista::eliminaNext(Node *posicio)
{
 	Node* aux;
	Node *seguent = NULL;
	if (posicio == NULL)
	{
		aux = m_primer;
		m_primer = aux->getNext();
		delete aux;
		seguent = m_primer;
	}
	else
	{
		aux = posicio->getNext();
		if (aux != NULL)
        {
            posicio->setNext(aux->getNext());
            seguent = aux->getNext();
            delete aux;
        }
	}
	return seguent;
}

