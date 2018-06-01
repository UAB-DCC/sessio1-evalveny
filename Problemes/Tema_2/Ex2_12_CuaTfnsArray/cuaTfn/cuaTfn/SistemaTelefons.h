#include "CuaTelefons.h"

class SistemaTelefons
{
public:
	SistemaTelefons();
	void introduirTelefon(string telf);
	string& servirTelefon();
	void eliminarTot();
	//int TelefonsPendents() { return m_cuaTelefons.getNumTelefons(); }
	int getNumTelefons() { return m_cuaTelefons.getNumTelefons(); }

private:
	CuaTelefons m_cuaTelefons;
};
