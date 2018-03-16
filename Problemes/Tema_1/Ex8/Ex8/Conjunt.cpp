#include "Conjunt.h"

Conjunt::Conjunt(const Conjunt& c)
{
	for (int i = 0; i < c.m_numElems; i++)
	{
		m_elements[i] = c.m_elements[i];
	}
	m_numElems = c.m_numElems;
}

Conjunt::Conjunt(int v[], int mida)
{
	if (mida <= MAXELEMENTS)
	{
		for (int i = 0; i < mida; i++)
		{
			m_elements[i] = v[i];
		}
		m_numElems = mida;
	}
}

int Conjunt::pertany(int el)
{
	int compta = 0;

	for (int i = 0;i< m_numElems;i++)
	{
		if (m_elements[i] == el)
		{
			compta++;
		}		
	}
	return compta;
}

void Conjunt::imprimir() const
{
	cout << "[ ";
	for (int i = 0; i < m_numElems; i++)
	{
		cout << m_elements[i] << ",";
	}
	cout << " ]" <<endl;		
}

Conjunt Conjunt::operator+ (const Conjunt& c)
{
	Conjunt cRes(m_elements, m_numElems);

	if ((m_numElems + c.m_numElems) <= MAXELEMENTS)
	{
		for (int i = 0; i < c.m_numElems; i++)
		{
			cRes.m_elements[cRes.m_numElems] = c.m_elements[i];
			cRes.m_numElems++;
		}
	}

	return cRes;
}

Conjunt Conjunt::operator+ (const int& el)
{
	Conjunt cRes(m_elements, m_numElems);

	if (m_numElems < MAXELEMENTS - 1)
	{
		cRes.m_elements[m_numElems] = el;
		cRes.m_numElems++;
	}
	return cRes;
}

Conjunt Conjunt::operator- (const int& el)
{
	Conjunt cRes(m_elements,m_numElems);
	bool trobat = false;
	int j = 0;
	while (!trobat && (j < m_numElems))
	{
		if (m_elements[j] == el)
		{
			cRes.m_elements[j] = cRes.m_elements[cRes.m_numElems - 1];
			cRes.m_numElems--;
			trobat = true;
		}
		else
		{
			j++;
		}
	}
	return cRes;
}

Conjunt Conjunt::operator- (const Conjunt& c)
{
	Conjunt cRes(m_elements, m_numElems);
	for (int i = 0; i < c.m_numElems; i++)
	{
		cRes = cRes - c.m_elements[i];		
	}
	
	return cRes;	
}

bool Conjunt::operator==(const Conjunt &c)
{
	bool iguals = true;
	if (m_numElems != c.m_numElems)
	{
		iguals = false;
	}
	else
	{
		int i = 0;
		while( (i < m_numElems) && iguals)
		{
			if (pertany(m_elements[i]) != pertany(c.m_elements[i]))
			{
				iguals = false;
			}
			else
			{
				i++;
			}
		}
	}
	
	return iguals;
}