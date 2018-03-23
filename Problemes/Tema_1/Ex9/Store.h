#pragma once
#include "App.h"
#include "Usuari.h"

class Store
{
public:
	Store() { m_nAplicacions = 0; m_nUsuaris = 0; }
	bool afegeixApp(const string &nom, const string &descripcio, int tamany);
	bool afegeixUsuari(const string &nom, const string &email, const string &contrassenya);
	bool afegeixDescarrega(const string &nomApp, const string &nomUsuari, const string &data, int temps, int valoracio);
	void llegeixUsuaris(const string &nomFitxer);
	void escriuDescarregues(const string &nomFitxer, const string &nomApp);

private:
	static const int MAX_APLICACIONS = 5;
	static const int MAX_USUARIS = 5;
	App m_aplicacions[MAX_APLICACIONS];
	int m_nAplicacions;
	Usuari m_usuaris[MAX_USUARIS];
	int m_nUsuaris;

	int cercaUsuari(const string &nom) const;
	int cercaApp(const string &nom) const;

};