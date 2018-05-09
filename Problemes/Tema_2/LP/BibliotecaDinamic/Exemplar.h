#pragma once
#include <string>
using namespace std;

class Exemplar
{
public:
	Exemplar();
	~Exemplar();

	void setCodi(int codi) { m_codi = codi; }
	int getCodi() { return m_codi; }
	bool estaPrestat() { return m_prestat; }
	bool prestar(const string &data);
	bool retornar(const string &data);

private:
	int m_codi; 
	bool m_prestat;
	string m_dataPrestec;
	string m_dataRetorn;
};

