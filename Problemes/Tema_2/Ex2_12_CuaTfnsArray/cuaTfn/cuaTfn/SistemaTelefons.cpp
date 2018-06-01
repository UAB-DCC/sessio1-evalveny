#include "SistemaTelefons.h"

SistemaTelefons::SistemaTelefons()
{

}

void SistemaTelefons::introduirTelefon(string telf)
{
	m_cuaTelefons.addTfn(telf);
}

string& SistemaTelefons::servirTelefon()
{
	return m_cuaTelefons.getTfn();
}

void SistemaTelefons::eliminarTot()
{
	m_cuaTelefons.eliminaTot();
}