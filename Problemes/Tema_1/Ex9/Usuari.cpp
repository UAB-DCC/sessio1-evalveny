#include "Usuari.h"
#include <string>
using namespace std;

std::ifstream& operator>> (std::ifstream& fitxer, Usuari &u)
{
	fitxer >> u.m_usuari;
	fitxer >> u.m_email;
	fitxer >> u.m_contrassenya;
	return fitxer;
}