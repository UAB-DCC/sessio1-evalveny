#include "Assignatura.h"
#include <forward_list>

#include <string>
using namespace std;


class Estudiant
{
public:
	Estudiant() { m_nAssigActual = 0;}
	Estudiant(const string &nom, const string &niu)
	{
		m_nom = nom;
		m_NIU = niu;
		m_nAssigActual = 0;		
	}
	bool buscaAssignatura(int codi, int& pos);
	bool afegeixAssignatura(int codi, int nCredits);
	void mostraAssignatures();
	int getNAssigActual() { return m_nAssigActual; }
	string& getNIU() { return m_NIU; }	
private:
	static const int MAX_ASSIGNATURES = 10;
	string m_nom;
	string m_NIU;
	AssignaturaExpedient m_assignatures[MAX_ASSIGNATURES];
	int m_nAssigActual;	
};

