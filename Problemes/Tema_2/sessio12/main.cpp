#include <iostream>
#include "Joc.h"

using namespace std;


int main()
{
    Joc joc;

    joc.treureCartaBaralla();
    joc.posarCartaAPal(CORS);
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();
    joc.posarCartaAPal(TREVOLS);

    joc.treureCartaBaralla();
    joc.posarCartaAPal(CORS);
    joc.treureCartaBaralla();
    joc.posarCartaAPal(DIAMANTS);
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();
    joc.posarCartaAPal(TREVOLS);

    joc.treureCartaBaralla();
    joc.posarCartaAPal(CORS);
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();

    joc.treureCartaBaralla();
    joc.posarCartaAPal(CORS);
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();
    joc.posarCartaAPal(TREVOLS);

    bool correcte = joc.treureCartaBaralla();
    while (correcte)
        correcte = joc.treureCartaBaralla();

    joc.posarDestapadesABaralla();
    joc.posarCartaAPal(CORS);
    joc.treureCartaBaralla();
    joc.treureCartaBaralla();

    joc.escriuJoc();


    return 0;
}
