#include "Node.h"

class Pila
{
public: 
	Pila() {m_top = NULL; };
	~Pila();
	void push(int val);
	void pop();
	int top() { return m_top->getValor(); }
	bool empty() { return (m_top == NULL); }
private:
	Node* m_top;
};
