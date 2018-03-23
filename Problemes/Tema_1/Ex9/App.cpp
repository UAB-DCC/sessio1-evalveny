#include "App.h"

void App::afegeixDescarrega(const string &nomUsuari, const string &data, int temps)
{
	if (m_nDescarregues < MAX_DESCARREGUES)
	{
		m_descarregues[m_nDescarregues].setDescarrega(nomUsuari, data, temps);
		m_nDescarregues++;
	}
}

bool App::afegeixValoracio(const string &nomUsuari, int valoracio)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nDescarregues))
	{
		if (m_descarregues[i].getUsuari() == nomUsuari)
		{
			trobat = true;
			m_descarregues[i].setValoracio(valoracio);
		}
		else
			i++;
	}
	return trobat;
}

std::ofstream& operator<< (std::ofstream& fitxer, const App &a)
{
	fitxer << a.m_nom << endl;
	fitxer << a.m_descripcio << endl;
	fitxer << a.m_tamany << endl;
	fitxer << a.m_nDescarregues << endl;
	for (int i = 0; i < a.m_nDescarregues; i++)
		fitxer << a.m_descarregues[i];
	return fitxer;
}