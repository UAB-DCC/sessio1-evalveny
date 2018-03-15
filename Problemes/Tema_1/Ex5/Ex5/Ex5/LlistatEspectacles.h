#include "Espectacle.h"

class LlistatEspectacles
{
public:
	void inicialitza() { m_NEspectacles = 0; }
	//~LlistatEspectacles();
	//void setNEspectacles(int numEspectacles) { m_NEspectacles = numEspectacles; }
	bool afegeixEspectacle(Espectacle& e);
	int compraEntrades(string nom, string dia, int nEntrades, float& preu);

private:
	static const int MAXESPECTACLES = 100;
	Espectacle m_espectacles[MAXESPECTACLES];
	int m_NEspectacles;

	int buscaEspectacle(string nom, string dia);
};

