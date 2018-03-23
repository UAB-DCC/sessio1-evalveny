#include <iostream>
using namespace std;

class Conjunt
{
public:
	Conjunt() { m_numElems = 0; };
	Conjunt(const Conjunt& c);
	Conjunt(const int v[], int mida);

	int getNumElements() const { return m_numElems; }
	int pertany(int el) const;

	Conjunt operator+(const Conjunt &c)const;
	Conjunt operator+(const int& el)const;
	Conjunt operator-(const Conjunt &c)const;
	Conjunt operator-(const int& el)const;
	bool operator==(const Conjunt &c)const;
	
	void imprimir()const;
private:
	static const int MAXELEMENTS = 100;
	int m_elements[MAXELEMENTS];
	int m_numElems;
};
