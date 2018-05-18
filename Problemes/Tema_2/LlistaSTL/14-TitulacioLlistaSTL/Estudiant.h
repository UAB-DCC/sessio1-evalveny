#pragma once
#include "Assignatura.h"
#include <forward_list>

#include <string>
using namespace std;


class Estudiant
{
public:
	Estudiant() { m_nAssignatures = 0; }
	Estudiant(const string &nom, const string &niu)
	{
		m_nom = nom;
		m_NIU = niu;
		m_nAssignatures = 0;
	}
	bool buscaAssignatura(int codi, std::forward_list<AssignaturaExpedient>::iterator& actual, std::forward_list<AssignaturaExpedient>::iterator& anterior);
	bool afegeixAssignatura(int codi, int nCredits);
	void mostraAssignatures();
	//string &recuperaNIU() { return m_NIU; }
	int getNAssignatures() { return m_nAssignatures; }
	string& getNIU() { return m_NIU; }
	bool eliminaAssignatura(int codi);

private:
	string m_nom;
	string m_NIU;
	std::forward_list<AssignaturaExpedient> m_assignatures;
	int m_nAssignatures;
};

