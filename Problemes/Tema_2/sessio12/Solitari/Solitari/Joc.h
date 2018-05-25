
#include "Carta.h"
#include <stack>
#include <forward_list>
#include<iterator>

const int CORS = 0;
const int DIAMANTS = 1;
const int PIQUES = 2;
const int TREVOLS = 3;


const int N_CARTES = 13;
const int N_PALS  = 4;
//const int N_PILES_INTER  = 7;



class Joc
{
public:
    Joc();
    ~Joc();

    bool treureCartaBaralla();
    bool posarDestapadesABaralla();
    bool posarCartaAPal(int pal);
	void escriuJoc();
	void donaJoc(Carta& cBaralla, Carta& cDestapada, Carta cPila[N_PALS])const;

private:
	std::stack<Carta> m_baralla;
	std::stack<Carta> m_destapades;
	std::stack<Carta> m_pilaResultat[N_PALS];
	//std::stack<Carta> m_pilaIntermedia[N_PILES_INTER];
};

