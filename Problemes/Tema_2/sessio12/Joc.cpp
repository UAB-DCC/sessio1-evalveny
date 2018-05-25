#include "Joc.h"

#include <stdlib.h>

Joc::Joc()
{
    for (int valor = N_CARTES; valor > 0; valor--)
        for (int pal = N_PALS - 1; pal >= 0; pal--)
        {
            Carta c;
            c.setCarta (valor, pal);
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

    if (!m_baralla.esBuida())
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

    if (!m_destapades.esBuida())
    {
        movimentFet = true;
        while (!m_destapades.esBuida())
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

    if ( !m_destapades.esBuida())
    {
        if (m_destapades.top().getPal() == pal)
        {
            if (m_pilaResultat[pal].esBuida())
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

void Joc::escriuJoc()
{
    cout << "Baralla" << endl;
    m_baralla.escriuPila();
    cout << "Destapades" << endl;
    m_destapades.escriuPila();
    for (int pal = 0; pal < N_PALS; pal++)
    {
        cout << "Resultat " <<  pal << endl;
        m_pilaResultat[pal].escriuPila();
    }

}
