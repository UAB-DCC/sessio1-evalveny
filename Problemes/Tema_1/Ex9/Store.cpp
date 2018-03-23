#include "Store.h"

bool Store::afegeixApp(const string &nom, const string &descripcio, int tamany)
{
	bool ok = false;
	if (m_nAplicacions < MAX_APLICACIONS)
	{
		ok = true;
		m_aplicacions[m_nAplicacions].setApp(nom, descripcio, tamany);
		m_nAplicacions++;
	}
	return ok;
}

bool Store::afegeixUsuari(const string &nom, const string &email, const string &contrassenya)
{
	bool ok = false;
	if (m_nUsuaris < MAX_USUARIS)
	{
		int nUsuari = cercaUsuari(nom);
		if (nUsuari == -1)
		{
			m_usuaris[m_nUsuaris].setUsuari(nom, email, contrassenya);
			m_nUsuaris++;
			ok = true;
		}
	}
	return ok;
}

bool Store::afegeixDescarrega(const string &nomApp, const string &nomUsuari, const string &data, int temps, int valoracio)
{
	bool ok = false;
	int nUsuari = cercaUsuari(nomUsuari);
	int nApp = cercaApp(nomApp);
	if ((nUsuari != -1) && (nApp != -1))
	{
		m_aplicacions[nApp].afegeixDescarrega(nomUsuari, data, temps);
		m_aplicacions[nApp].afegeixValoracio(nomUsuari, valoracio);
		ok = true;
	}
	return ok;
}


void Store::llegeixUsuaris(const string &nomFitxer)
{
	ifstream fitxer;

	fitxer.open(nomFitxer.c_str());
	if (fitxer.is_open())
	{
		m_nUsuaris = 0;
		fitxer >> m_usuaris[m_nUsuaris];
		while (!fitxer.eof())
		{
			m_nUsuaris++;
			fitxer >> m_usuaris[m_nUsuaris];
		}
	}
	fitxer.close();
}

void Store::escriuDescarregues(const string &nomFitxer, const string &nomApp)
{
	ofstream fitxer;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int nApp = cercaApp(nomApp);
		if (nApp != -1)
			fitxer << m_aplicacions[nApp];
	}
	fitxer.close();
}

int Store::cercaUsuari(const string &nom) const
{
	bool existeix = false;
	int i = 0;
	while ((i <	m_nUsuaris) && (!existeix))
	{
		if (m_usuaris[i].getNom() == nom)
			existeix = true;
		else
			i++;
	}
	if (existeix)
		return i;
	else
		return -1;
}

int Store::cercaApp(const string &nom) const
{
	bool existeix = false;
	int i = 0;
	while ((i <	m_nAplicacions) && (!existeix))
	{
		if (m_aplicacions[i].getNom() == nom)
			existeix = true;
		else
			i++;
	}
	if (existeix)
		return i;
	else
		return -1;
}