
#ifndef LLISTA_H
#define LLISTA_H

#include "Node.h"

class LlistaDoble
{
    public:
        LlistaDoble();
        ~LlistaDoble();

		bool esBuida() const;
		Node *getInici() const;
		Node *getFinal() const;
		Node *insereixNext(const int &valor, Node *posicio);
		Node *insereixPrev(const int &valor, Node *posicio);
		Node *eliminaNext(Node *posicio);
		Node *eliminaPrev(Node *posicio);
		Node *eliminaActual(Node *posicio);

		
    private:
        Node* m_primer;
		Node* m_ultim;
};

#endif // LLISTAAUTOR_H
