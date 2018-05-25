#include "Joc.h"

#include <stdlib.h>

Joc::Joc()
{
    for (int valor = N_CARTES; valor > 0; valor--)
        for (int pal = N_PALS - 1; pal >= 0; pal--)
        {
            Carta c;
            c.setCarta (pal, valor);
            m_baralla.push(c);
        }
}

Joc::~Joc()
{
    //dtor
}

// Treu una carta de la baralla i la posa a m_destapades
bool Joc::treureCartaBaralla()
{
    bool movimentFet = false;

    if (!m_baralla.empty())
    {
        m_destapades.push(m_baralla.top());
        m_baralla.pop();
        movimentFet = true;
    }
    return movimentFet;
}

// Passar totes les cartes de la Sortida a la Baralla en ordre invers
bool Joc::posarDestapadesABaralla()
{
    bool movimentFet = false;

    if (!m_destapades.empty())
    {
        movimentFet = true;
        while (!m_destapades.empty())
        {
            m_baralla.push(m_destapades.top());
            m_destapades.pop();
        }
    }
    return movimentFet;

}



// Passar la primera carta de Sortida al pal indicat si es possible.
//Es a dir: si el pal de la carta es correcte
//          i la numeracio es correlativa a la que hi ha o es l'as a l'inici.
bool Joc::posarCartaAPal(int pal)
{
    bool movimentFet = false;

    if ( !m_destapades.empty())
    {
        if (m_destapades.top().getPal() == pal)
        {
            if (m_pilaResultat[pal].empty())
            {
                if ( (m_destapades.top().getValor()) == 1)
                {
                     movimentFet = true;
                     m_pilaResultat[pal].push(m_destapades.top());
                     m_destapades.pop();
                }
            }
            else
            {
                if ( (m_destapades.top().getValor()) == m_pilaResultat[pal].top().getValor()+1)
                {
                     movimentFet = true;
                     m_pilaResultat[pal].push(m_destapades.top());
                     m_destapades.pop();
                }
            }
        }
    }

    return movimentFet;
}

void Joc::donaJoc(Carta& cBaralla, Carta& cDestapada, Carta cPila[N_PALS])const
{
	Carta c(PALCARTABUIDA,0);
	if (!m_baralla.empty()) 	
		cBaralla = m_baralla.top();
	else 
		cBaralla = c;
	if (!m_destapades.empty())
		cDestapada = m_destapades.top();
	else
		cDestapada = c;

	for (int i = 0; i < N_PALS; i++)
	{
		if (!m_pilaResultat[i].empty())
			cPila[i] = m_pilaResultat[i].top();
		else
			cPila[i] = c;
	}
}

void Joc::escriuJoc()
{
	cout << "Comment :=>> Baralla" << endl;
	if (!m_baralla.empty())
	{
		cout << "Comment :=>> ";
		m_baralla.top().escriuCarta();
	}
	cout << endl;

    cout << "Comment :=>> Destapades" << endl;
	if (!m_destapades.empty())
	{
		cout << "Comment :=>> ";
		m_destapades.top().escriuCarta();
	}
	cout << endl;
    for (int pal = 0; pal < N_PALS; pal++)
    {
        cout << "Comment :=>> Resultat " <<  pal << endl;
		if (!m_pilaResultat[pal].empty())
		{
			cout << "Comment :=>> ";
			m_pilaResultat[pal].top().escriuCarta();
		}
		cout << endl;
    }

}
