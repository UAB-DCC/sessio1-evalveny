#pragma once

class Store
{
public:
	Store();
	bool afegeixApp(const string &nom, const string &descripcio, int tamany);
	bool afegeixUsuari(const string &nom, const string &email, const string &contrassenya);
	bool afegeixDescarrega(const string &nomApp, const string &nomUsuari, const string &data, int temps, int valoracio);
	void llegeixUsuaris(const string &nomFitxer);
	void escriuDescarregues(const string &nomFitxer, const string &nomApp);

private:




};