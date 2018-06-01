#include <stdio.h>

class Node
{
public:
	Node() { m_valor = 0; m_next = NULL; };
	~Node() { m_next = NULL; };
	void setValor(int valor) { m_valor = valor; };
	void setNext(Node* next) { m_next = next; };
	int getValor() const { return m_valor; };
	Node* getNext() { return m_next; };
private:
	int m_valor;
	Node* m_next;
};
