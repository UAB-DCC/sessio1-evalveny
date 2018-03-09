#include "Espectacle.h"

class LlistatEspectacles
{
public:
	LlistatEspectacles();
	~LlistatEspectacles();

	bool afegeixEspectacle(Espectacle& e);
	int compraEntrades(string nom, string dia, int nEntrades, float& preu);

private:
	static const int MAXESPECTACLES = 100;
	Espectacle m_espectacles[MAXESPECTACLES];
	int m_NEspectacles;

	int buscaEspectacle(string nom, string dia);
};

