
#ifndef LLISTA_H
#define LLISTA_H

#include "Node.h"

class Llista
{
    public:
        Llista();
        ~Llista();

        bool esBuida() const;
        Node *getInici() const;
        Node *insereixNext(const int& valor, Node *posicio);
        Node *eliminaNext(Node *posicio);

		int getNElements() const;
		int sumaElements() const;
		void eliminaValor(int valor);
		void inverteixLlista();
		void afegeixLlista(Llista &l);
		void insereixOrdenat(int valor);
		
    private:
        Node* m_primer;
};

#endif // LLISTAAUTOR_H
