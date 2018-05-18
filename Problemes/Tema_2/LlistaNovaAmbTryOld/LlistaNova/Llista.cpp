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

void Llista::reset()
{
	m_primer = NULL;
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

int Llista::getNElements() const
{
	int nElements = 0;
	Node *aux = m_primer;
	while (aux != NULL)
	{
		nElements++;
		aux = aux->getNext();
	}
	return nElements;
}

int Llista::sumaElements() const
{
	int suma = 0;
	Node *aux = m_primer;
	while (aux != NULL)
	{
		suma += aux->getValor();
		aux = aux->getNext();
	}
	return suma;
}

void Llista::eliminaValor(int valor)
{
	Node *aux = m_primer;
	Node *ant = NULL;
	while (aux != NULL)
	{
		if (aux->getValor() == valor)
		{
			if (ant != NULL)
			{
				ant->setNext(aux->getNext());
				delete aux;
				aux = ant->getNext();
			}
			else
			{
				m_primer = aux->getNext();
				delete aux;
				aux = m_primer;
			}				
		}
		else
		{
			ant = aux;
			aux = aux->getNext();
		}
	}
}


void Llista::inverteixLlista()
{
	Node *ant = NULL;
	Node *aux = m_primer;
	Node *seguent = NULL;
	while (aux != NULL)
	{
		seguent = aux->getNext();
		aux->setNext(ant);
		ant = aux;
		aux = seguent;
	}
	m_primer = ant;

	/////////////////// PER TEST SEGMENTATION FAULT
	Node* kk = m_primer;
	delete kk;
	///////////////////
}


void Llista::afegeixLlista(Llista &l)
{
	Node *aux = m_primer;
	Node *ant = NULL;
	Node *nou;
	Node *auxAfegeix = l.m_primer;

	while ((auxAfegeix != NULL) && (aux != NULL))
	{
		if (auxAfegeix->getValor() < aux->getValor())
		{
			nou = new Node;
			nou->setValor(auxAfegeix->getValor());
			nou->setNext(aux);
			if (ant != NULL)
				ant->setNext(nou);
			else
				m_primer = nou;
			ant = nou;
			auxAfegeix = auxAfegeix->getNext();
		}
		else
			if (auxAfegeix->getValor() == aux->getValor())
			{
				ant = aux;
				aux = aux->getNext();
				auxAfegeix = auxAfegeix->getNext();
			}
			else
			{
				ant = aux;
				aux = aux->getNext();
			}
	}
	while (auxAfegeix != NULL)
	{
		nou = new Node;
		nou->setValor(auxAfegeix->getValor());
		nou->setNext(aux);
		if (ant != NULL)
			ant->setNext(nou);
		else
			m_primer = nou;
		ant = nou;
		auxAfegeix = auxAfegeix->getNext();
	}
}


void Llista::insereixOrdenat(int valor)
{
	Node *ant = NULL;
	Node *aux = m_primer;
	bool trobat = false;
	while (!trobat && (aux != NULL))
	{
		if (aux->getValor() > valor)
			trobat = true;
		else
		{
			ant = aux;
			aux = aux->getNext();
		}
	}
	Node *nou = new Node;
	nou->setValor(valor);
	nou->setNext(aux);
	if (ant != NULL)
		ant->setNext(nou);
	else
		m_primer = nou;
}