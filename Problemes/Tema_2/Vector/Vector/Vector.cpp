
#include"Vector.h"

Vector::Vector(const Vector& v)
{
	m_array = NULL;
	*this = v;
}


Vector::~Vector()
{
	if (m_array != NULL)
	{
		delete[] m_array;
		m_array = NULL;
	}
	m_longitud = 0;
}


void Vector::redimensiona(int longitud)
{
	if (longitud != m_longitud)
	{
		Punt *arrayAux = new Punt[longitud];
		int limit;
		if (longitud < m_longitud)
			limit = longitud;
		else
			limit = m_longitud;
		for (int i = 0; i < limit; i++)
			arrayAux[i] = m_array[i];
		delete[] m_array;
		m_array = arrayAux;
		m_longitud = longitud;
	}

}


int Vector::longitud()
{
	return m_longitud;
}


Punt& Vector::operator[] (int nIndex)
{
	if (nIndex >= 0 && nIndex < m_longitud)
		return m_array[nIndex];
	else
	{
		cout << "Error d'acces a l'array" << endl;
		return m_valorDefecte;
	}
}


Vector& Vector::operator = (const Vector& v)
{
	if (m_array != NULL)
		delete[] m_array;
	m_longitud = v.m_longitud;
	m_array = new Punt[m_longitud];
	for (int i = 0; i < m_longitud; i++)
	{
		m_array[i] = v.m_array[i];
	}
	return *this;
}


