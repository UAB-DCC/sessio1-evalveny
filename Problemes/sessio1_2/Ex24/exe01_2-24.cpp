/*
Test set:
1
2
3
4
6
5
0
0
1
1
6
6
2
3
4
5
###
1
2
4
4
5
5
0
0
1
1
2
4
5
1
3
6
###
1
2
4
4
5
5
0
0
1
1
5
6
6
6
3
4
###
1
2
4
4
5
5
0
0
1
1
3
4
5
2
2
6
###
*/

#include <iostream>

using namespace std;

const int MAX_FITXES = 7;

typedef struct
{
    int esquerra;
    int dreta;
} Fitxa;

void llegeixFitxa (Fitxa& c)
{
    cin >> c.esquerra;
    cin >> c.dreta;
}

int main()
{
    Fitxa fitxes[MAX_FITXES];
    int valorEsq, valorDret;

    for (int i = 0; i< MAX_FITXES; i++)
        llegeixFitxa(fitxes[i]);

    cin >> valorEsq;
    cin >> valorDret;
    bool trobat = false;
    int i = 0;
    do
    {
        if ((fitxes[i].dreta == valorDret) || (fitxes[i].dreta == valorEsq) || (fitxes[i].esquerra == valorDret) || (fitxes[i].esquerra == valorEsq))
            trobat = true;
        else
            i++;
    } while ((!trobat) && (i < MAX_FITXES));
    if (trobat)
        cout << "SI";
    else
        cout << "NO";
    return 0;
}
