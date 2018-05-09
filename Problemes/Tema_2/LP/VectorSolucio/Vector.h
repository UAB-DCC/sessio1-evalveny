#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
class Vector
{
public:
	Vector(): m_array(NULL), m_longitud(0), m_valorDefecte(T()) { }
	Vector(const Vector<T>& v);
	~Vector();
	void redimensiona(int longitud);
	int longitud();
	T& operator[] (int nIndex);
	Vector<T>& operator = (const Vector<T>& v);
	void sort();
private:
	T *m_array;
	int m_longitud;
	T m_valorDefecte;
};


template<class T>
Vector<T>::Vector(const Vector<T>& v)
{
	m_array = NULL;
	m_valorDefecte = T();
	*this = v;
}

template<class T>
Vector<T>::~Vector()
{
	if (m_array != NULL)
	{
		delete[] m_array;
		m_array = NULL;
	}
	m_longitud = 0;
}

template<class T>
void Vector<T>::redimensiona(int longitud)
{
	if (longitud != m_longitud)
	{
		T *arrayAux = new T[longitud];
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

template<class T>
int Vector<T>::longitud()
{
	return m_longitud;
}

template<class T>
T& Vector<T>::operator[] (int nIndex)
{
	if (nIndex >= 0 && nIndex < m_longitud)
		return m_array[nIndex];
	else
	{
		cout << "Error d'acces a l'array" << endl;
		return m_valorDefecte;
	}
}

template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v)
{
	if (m_array != NULL)
		delete[] m_array;
	m_longitud = v.m_longitud;
	m_array = new T[m_longitud];
	for (int i = 0; i < m_longitud; i++)
	{
		m_array[i] = v.m_array[i];
	}
	return *this;
}

template<class T>
void Vector<T>::sort()
{
	bool canvi = true;
	int i = 0;
	while ((i < m_longitud) && (canvi))
	{
		canvi = false;
		int j = 0;
		while (j < (m_longitud - (i + 1)))
		{
			if (m_array[j] > m_array[j + 1])
			{
				T temp;
				temp = m_array[j];
				m_array[j] = m_array[j + 1];
				m_array[j + 1] = temp;
				canvi = true;
			}
			j++;
		}
		i++;
	}
}

