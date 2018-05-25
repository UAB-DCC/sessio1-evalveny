#include <cstddef>
#include <iostream>
using namespace std;

const int PALCARTABUIDA = 5;

class Carta
{
    public:
		Carta() { m_valor = 0; m_pal = 0; }
		Carta(int pal, int valor) { m_valor = valor; m_pal = pal; }
		Carta(const Carta& c) { m_valor = c.m_valor; m_pal = c.m_pal; }
		~Carta() {};
		bool esCartaBuida() { return m_pal == PALCARTABUIDA;}
        void setCarta(int noupal, int nouvalor) { m_valor = nouvalor; m_pal = noupal; };
		int getValor() const {return m_valor;};
		int getPal() const {return m_pal;};
		void escriuCarta() const { if (m_pal != PALCARTABUIDA) { cout << m_pal << " " << m_valor; } }
		Carta& operator=(const Carta& c) { m_valor = c.m_valor; m_pal = c.m_pal; return *this; }
		bool operator==(const Carta& c) { return ((c.m_pal == m_pal) && (c.m_valor==m_valor)); }
    private:
        int m_valor;
        int m_pal;
};

