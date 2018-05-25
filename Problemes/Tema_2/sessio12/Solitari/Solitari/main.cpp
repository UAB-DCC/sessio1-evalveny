#include <iostream>
#include "Joc.h"

using namespace std;

float testInicialitza()
{
	float punts = 0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------" << endl;
	cout << "Comment :=>> Iniciant test INICIALITZAR   " << endl;
	cout << "Comment :=>> -----------------------------" << endl;
	cout << "Comment :=>>" << endl;

	Joc joc;
	Carta cBaralla, cDestapada, cPila[N_PALS];
	Carta cBarallaEsperada(0,1);
	Carta cDestapadaEsperada(PALCARTABUIDA,0);
	Carta cPilaEsperada[N_PALS];
	for (int i = 0; i < N_PALS; i++)
	{
		cPilaEsperada[i].setCarta(PALCARTABUIDA, 0);
	}
	
	joc.donaJoc(cBaralla, cDestapada, cPila);

	cout << "Comment :=>> -----------" << endl;
	cout << "Comment :=>> JOC QUEDA  " << endl;
	cout << "Comment :=>> -----------" << endl;
	joc.escriuJoc();

	if ( (cBaralla == cBarallaEsperada) && (cDestapada == cDestapadaEsperada) && (cPila[0] == cPilaEsperada[0]) && (cPila[1] == cPilaEsperada[1]) && (cPila[2] == cPilaEsperada[2]) )
	{
		cout << "Comment :=>> OK Iniciant Joc " << endl;		
		punts = 2;
	}
	else
	{
		cout << "Comment :=>> -------------------" << endl;
		cout << "Comment :=>> ERROR Iniciant Joc " << endl;
		cout << "Comment :=>> -------------------" << endl;
		cout << "Comment :=>> JOC ESPERAT" << endl;
		cout << "Comment :=>> -------------------" << endl;
		cout << "Comment :=>> Baralla" << endl;
		cout << "Comment :=>> ";
		cBarallaEsperada.escriuCarta();
		cout << endl;

		cout << "Comment :=>> Destapades" << endl;
		cout << "Comment :=>> ";
		cDestapadaEsperada.escriuCarta();
		cout << endl;
		for (int pal = 0; pal < N_PALS; pal++)
		{
			cout << "Comment :=>> Resultat " << pal << endl;
			cout << "Comment :=>> ";
			cPilaEsperada[pal].escriuCarta();
			cout << endl;
		}
	}

	return punts;
}

float testTreureCartaBaralla()
{
	float punts = 0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>> Iniciant test TREURECARTABARALLA " << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	Joc joc;
	Carta cBaralla, cDestapada, cPila[N_PALS];
	Carta cBarallaEsperada(1, 1);
	Carta cDestapadaEsperada(0, 1);
	Carta cPilaEsperada[N_PALS];
	for (int i = 0; i < N_PALS; i++)
	{
		cPilaEsperada[i].setCarta(PALCARTABUIDA, 0);
	}

	joc.treureCartaBaralla();
	joc.donaJoc(cBaralla, cDestapada, cPila);

	cout << "Comment :=>> -----------" << endl;
	cout << "Comment :=>> JOC QUEDA  " << endl;
	cout << "Comment :=>> -----------" << endl;
	joc.escriuJoc();

	if ((cBaralla == cBarallaEsperada) && (cDestapada == cDestapadaEsperada) && (cPila[0] == cPilaEsperada[0]) && (cPila[1] == cPilaEsperada[1]) && (cPila[2] == cPilaEsperada[2]))
	{
		cout << "Comment :=>> OK Iniciant Joc " << endl;
		punts = 2;
	}
	else
	{
		cout << "Comment :=>> ----------------------------" << endl;
		cout << "Comment :=>> ERROR Treient Carta Baralla " << endl;
		cout << "Comment :=>> ----------------------------" << endl;
		cout << "Comment :=>> JOC ESPERAT" << endl;
		cout << "Comment :=>> ----------------------------" << endl;
		cout << "Comment :=>> Baralla" << endl;
		cout << "Comment :=>> ";
		cBarallaEsperada.escriuCarta();
		cout << endl;

		cout << "Comment :=>> Destapades" << endl;
		cout << "Comment :=>> ";
		cDestapadaEsperada.escriuCarta();
		cout << endl;
		for (int pal = 0; pal < N_PALS; pal++)
		{
			cout << "Comment :=>> Resultat " << pal << endl;
			cout << "Comment :=>> ";
			cPilaEsperada[pal].escriuCarta();
			cout << endl;
		}
	}
	return punts;
}

float testPosaCartaAPal()
{
	float punts = 0;
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------" << endl;
	cout << "Comment :=>> Iniciant test POSAR CARTA A PAL" << endl;
	cout << "Comment :=>> -------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	Joc joc;
	Carta cBaralla, cDestapada, cPila[N_PALS];
	Carta cBarallaEsperada(1, 1);
	Carta cDestapadaEsperada(PALCARTABUIDA, 0);
	Carta cPilaEsperada[N_PALS];
	for (int i = 0; i < N_PALS; i++)
	{
		cPilaEsperada[i].setCarta(PALCARTABUIDA, 0);
	}
	cPilaEsperada[0].setCarta(0, 1);

	joc.treureCartaBaralla();
	joc.posarCartaAPal(CORS);

	joc.donaJoc(cBaralla, cDestapada, cPila);

	cout << "Comment :=>> -----------" << endl;
	cout << "Comment :=>> JOC QUEDA  " << endl;
	cout << "Comment :=>> -----------" << endl;
	joc.escriuJoc();

	if ((cBaralla == cBarallaEsperada) && (cDestapada == cDestapadaEsperada) && (cPila[0] == cPilaEsperada[0]) && (cPila[1] == cPilaEsperada[1]) && (cPila[2] == cPilaEsperada[2]))
	{
		cout << "Comment :=>> OK Iniciant Joc " << endl;
		punts = 2;
	}
	else
	{
		cout << "Comment :=>> -------------------------" << endl;
		cout << "Comment :=>> ERROR Posant Carta a Pal " << endl;
		cout << "Comment :=>> -------------------------" << endl;
		cout << "Comment :=>> JOC ESPERAT" << endl;
		cout << "Comment :=>> -------------------------" << endl;
		cout << "Comment :=>> Baralla" << endl;
		cout << "Comment :=>> ";
		cBarallaEsperada.escriuCarta();
		cout << endl;

		cout << "Comment :=>> Destapades" << endl;
		cout << "Comment :=>> ";
		cDestapadaEsperada.escriuCarta();
		cout << endl;
		for (int pal = 0; pal < N_PALS; pal++)
		{
			cout << "Comment :=>> Resultat " << pal << endl;
			cout << "Comment :=>> ";
			cPilaEsperada[pal].escriuCarta();
			cout << endl;
		}
	}
	return punts;
}

float testPosarDestapadesABaralla()
{
	float punts = 0;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test POSAR DESTAPADES A BARALLA" << endl;
	cout << "Comment :=>> ----------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	Joc joc;
	Carta cBaralla, cDestapada, cPila[N_PALS];
	Carta cBarallaEsperada(1, 1);
	Carta cDestapadaEsperada(PALCARTABUIDA, 0);
	Carta cPilaEsperada[N_PALS];
	for (int i = 0; i < N_PALS; i++)
	{
		cPilaEsperada[i].setCarta(PALCARTABUIDA, 0);
	}
	cPilaEsperada[0].setCarta(0, 3);
	cPilaEsperada[3].setCarta(3, 1);

	joc.treureCartaBaralla();
	joc.posarCartaAPal(CORS);
	joc.treureCartaBaralla();
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
	{
		correcte = joc.treureCartaBaralla();		
	}
	joc.posarDestapadesABaralla();
	
	joc.donaJoc(cBaralla, cDestapada, cPila);

	cout << "Comment :=>> -----------" << endl;
	cout << "Comment :=>> JOC QUEDA  " << endl;
	cout << "Comment :=>> -----------" << endl;
	joc.escriuJoc();

	if ((cBaralla == cBarallaEsperada) && (cDestapada == cDestapadaEsperada) && (cPila[0] == cPilaEsperada[0]) && (cPila[1] == cPilaEsperada[1]) && (cPila[2] == cPilaEsperada[2]))
	{
		cout << "Comment :=>> OK Iniciant Joc " << endl;
		punts = 2;
	}
	else
	{
		cout << "Comment :=>> ----------------------------------" << endl;
		cout << "Comment :=>> ERROR Posant DEstapades a BARALLA " << endl;
		cout << "Comment :=>> ----------------------------------" << endl;
		cout << "Comment :=>> JOC ESPERAT" << endl;
		cout << "Comment :=>> ----------------------------------" << endl;
		cout << "Comment :=>> Baralla" << endl;
		cout << "Comment :=>> ";
		cBarallaEsperada.escriuCarta();
		cout << endl;

		cout << "Comment :=>> Destapades" << endl;
		cout << "Comment :=>> ";
		cDestapadaEsperada.escriuCarta();
		cout << endl;
		for (int pal = 0; pal < N_PALS; pal++)
		{
			cout << "Comment :=>> Resultat " << pal << endl;
			cout << "Comment :=>> ";
			cPilaEsperada[pal].escriuCarta();
			cout << endl;
		}
	}
	return punts;
}

float testJocComplert()
{
	float punts = 0;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------" << endl;
	cout << "Comment :=>> Iniciant test COMPLERT" << endl;
	cout << "Comment :=>> ----------------------" << endl;
	cout << "Comment :=>>" << endl;

	Joc joc;
	Carta cBaralla, cDestapada, cPila[N_PALS];
	Carta cBarallaEsperada(1, 2);
	Carta cDestapadaEsperada(2, 1);
	Carta cPilaEsperada[N_PALS];
	for (int i = 0; i < N_PALS; i++)
	{
		cPilaEsperada[i].setCarta(PALCARTABUIDA, 0);
	}
	cPilaEsperada[0].setCarta(0, 4);
	cPilaEsperada[3].setCarta(3, 2);

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
	int i = 0;
	while (correcte)
	{
		correcte = joc.treureCartaBaralla();
	}
	joc.posarDestapadesABaralla();
	joc.posarCartaAPal(CORS);
	joc.treureCartaBaralla();
	joc.treureCartaBaralla();

	joc.donaJoc(cBaralla, cDestapada, cPila);

	cout << "Comment :=>> -----------" << endl;
	cout << "Comment :=>> JOC QUEDA  " << endl;
	cout << "Comment :=>> -----------" << endl;
	joc.escriuJoc();

	if ((cBaralla == cBarallaEsperada) && (cDestapada == cDestapadaEsperada) && (cPila[0] == cPilaEsperada[0]) && (cPila[1] == cPilaEsperada[1]) && (cPila[2] == cPilaEsperada[2]))
	{
		cout << "Comment :=>> OK Iniciant Joc " << endl;
		punts = 2;
	}
	else
	{
		cout << "Comment :=>> -------------------" << endl;
		cout << "Comment :=>> ERROR Joc Complert " << endl;
		cout << "Comment :=>> -------------------" << endl;
		cout << "Comment :=>> JOC ESPERAT" << endl;
		cout << "Comment :=>> -------------------" << endl;
		cout << "Comment :=>> Baralla" << endl;
		cout << "Comment :=>> ";
		cBarallaEsperada.escriuCarta();
		cout << endl;

		cout << "Comment :=>> Destapades" << endl;
		cout << "Comment :=>> ";
		cDestapadaEsperada.escriuCarta();
		cout << endl;
		for (int pal = 0; pal < N_PALS; pal++)
		{
			cout << "Comment :=>> Resultat " << pal << endl;
			cout << "Comment :=>> ";
			cPilaEsperada[pal].escriuCarta();
			cout << endl;
		}
	}
	return punts;
}


int main()
{
	float grade = 0;

	grade += testInicialitza();
	grade += testTreureCartaBaralla();
	grade += testPosaCartaAPal();
	grade += testPosarDestapadesABaralla();
	grade += testJocComplert();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
