#pragma once
#include <string>
using namespace std;
#include "Estudiant.h"

class Titulacio
{
private:
	string m_nom;
	int m_nEstudiants;
	std::forward_list<Estudiant> m_estudiants;
public:
	bool buscaEstudiant(const string& niu, std::forward_list<Estudiant>::iterator& actual, std::forward_list<Estudiant>::iterator& anterior);
	bool afegeixEstudiant(Estudiant &e);
	bool afegeixAssignaturaEstudiant(const string& niu, int codiAssig, int nCredits);
	void mostraEstudiants();
	void eliminaEstudiants();
	void eliminaAssignatura(int codi);

};
