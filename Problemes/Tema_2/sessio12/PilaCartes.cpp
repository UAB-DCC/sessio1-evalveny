#include "PilaCartes.h"

PilaCartes::PilaCartes()
{
    //ctor
    m_top = NULL;
}

PilaCartes::~PilaCartes()
{
    //dtor
    m_top = NULL;
}

 void PilaCartes::push(Carta& carta)
 {
    NodeCarta* auxNCarta = new NodeCarta;
	auxNCarta->setValor(carta);
	auxNCarta->setNext(m_top);
	m_top = auxNCarta;

 }

 void PilaCartes::pop()
 {
    NodeCarta* auxNCarta;
	auxNCarta = m_top->getNext();
	delete m_top;
	m_top = auxNCarta;

 }

 Carta& PilaCartes::top() const
 {
     return m_top->getValor();
 }

 bool PilaCartes::esBuida() const
 {
    return m_top == NULL;
 }

void PilaCartes::escriuPila()
{
    NodeCarta* aux;

    aux= m_top;

    while (aux !=NULL)
    {
        aux->getValor().escriuCarta();
        cout << " # ";
        aux = aux->getNext();
    }
    cout << endl;
}
