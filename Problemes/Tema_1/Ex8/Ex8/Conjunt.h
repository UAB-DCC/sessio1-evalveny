#include <iostream>
using namespace std;

class Conjunt
{
public:
	Conjunt() { m_numElems = 0; };
	Conjunt(const Conjunt& c);
	Conjunt(int v[], int mida);

	int getNumElements() { return m_numElems; }
	int pertany(int el) const;

	Conjunt operator+(const Conjunt &c);
	Conjunt operator+(const int& el);
	Conjunt operator-(const Conjunt &c);
	Conjunt operator-(const int& el);
	bool operator==(const Conjunt &c);
	
	void imprimir()const;
private:
	static const int MAXELEMENTS = 100;
	int m_elements[MAXELEMENTS];
	int m_numElems;
};
