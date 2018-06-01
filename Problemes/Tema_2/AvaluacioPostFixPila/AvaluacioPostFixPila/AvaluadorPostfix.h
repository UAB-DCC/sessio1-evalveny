#include "Pila.h"
#include <iostream>
#include <string>
using namespace std;

class AvaluadorPostfix
{
public:
	AvaluadorPostfix();
	~AvaluadorPostfix();
	float avaluar(string expressio);
private:
	Pila m_operands;
};
