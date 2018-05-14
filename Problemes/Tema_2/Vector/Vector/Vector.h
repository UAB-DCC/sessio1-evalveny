#include "Punt.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector() {
		m_array = NULL; m_longitud = 0;}
	Vector(const Vector& v);
	~Vector();
	void redimensiona(int longitud);
	int longitud();
	Punt& operator[] (int nIndex);
	Vector& operator = (const Vector& v);	
private:
	Punt *m_array;
	int m_longitud;
	Punt m_valorDefecte;
};

