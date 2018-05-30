
#include "LlistaDoble.h"

LlistaDoble::LlistaDoble()
{
    //ctor
     m_primer = NULL;
	 m_ultim = NULL;
}

LlistaDoble::~LlistaDoble()
{
    //dtor
	while (m_ultim != NULL)
		eliminaActual(m_ultim);
}

bool LlistaDoble::esBuida() const
{
    return (m_primer == NULL);
}

Node *LlistaDoble::getInici() const
{
    return m_primer;
}

Node *LlistaDoble::getFinal() const
{
	return m_ultim;
}

/*Node *LlistaDoble::insereixNext(const int& valor, Node *posicio)
{
	Node* aux = new Node;
	if (aux != NULL)
	{
		aux->setValor(valor);
		if (posicio == NULL)
		{
			aux->setNext(m_primer);
			if (m_primer == NULL)
				m_ultim = aux;
			else
				m_primer->setPrev(aux);
			m_primer = aux;
		}
		else
		{
			aux->setNext(posicio->getNext());
			aux->setPrev(posicio);
			if (posicio->getNext() == NULL)
				m_ultim = aux;
			else
				posicio->getNext()->setPrev(aux);
			posicio->setNext(aux);
		}
	}
	return aux;
}

*/
Node *LlistaDoble::insereixPrev(const int &valor, Node *posicio)
{
	Node* aux = new Node;
	if (aux != NULL)
	{
		aux->setValor(valor);
		if (posicio == NULL)
		{
			aux->setPrev(m_ultim);
			if (m_ultim == NULL)
				m_primer = aux;
			else
				m_ultim->setNext(aux);
			m_ultim = aux;
		}
		else
		{
			aux->setPrev(posicio->getPrev());
			aux->setNext(posicio);
			if (posicio->getPrev() == NULL)
				m_primer = aux;
			else
				posicio->getPrev()->setNext(aux);
			posicio->setPrev(aux);
		}
	}
	return aux;
}

/*Node *LlistaDoble::eliminaNext(Node *posicio)
{
 	Node* aux;
	Node *seguent = NULL;
	if (posicio == NULL)
	{
		aux = m_primer;
		if (aux != NULL)
		{
			m_primer = aux->getNext();
			delete aux;
			if (m_primer != NULL)
				m_primer->setPrev(NULL);
			else
				m_ultim = NULL;
			seguent = m_primer;
		}
	}
	else
	{
		aux = posicio->getNext();
		if (aux != NULL)
        {
            posicio->setNext(aux->getNext());
            seguent = aux->getNext();
            delete aux;
			if (seguent != NULL)
				seguent->setPrev(posicio);
			else
				m_ultim = posicio;
        }
	}
	return seguent;
}

Node *LlistaDoble::eliminaPrev(Node *posicio)
{
	Node* aux;
	Node *anterior = NULL;
	if (posicio == NULL)
	{
		aux = m_ultim;
		if (aux != NULL)
		{
			m_ultim = aux->getPrev();
			delete aux;
			if (m_ultim != NULL)
				m_ultim->setNext(NULL);
			else
				m_primer = NULL;
			anterior = m_primer;
		}
	}
	else
	{
		aux = posicio->getPrev();
		if (aux != NULL)
		{
			posicio->setPrev(aux->getPrev());
			anterior = aux->getPrev();
			delete aux;
			if (anterior != NULL)
				anterior->setNext(posicio);
			else
				m_primer = posicio;
		}
	}
	return anterior;
}

*/
Node *LlistaDoble::eliminaActual(Node *posicio)
{
	Node *anterior = NULL;
	Node *seguent = NULL;
	if (posicio != NULL)
	{
		anterior = posicio->getPrev();
		seguent = posicio->getNext();
		delete posicio;
		if (anterior != NULL)
			anterior->setNext(seguent);
		else
			m_primer = seguent;
		if (seguent != NULL)
			seguent->setPrev(anterior);
		else
			m_ultim = anterior;
	}
	return seguent;
}
