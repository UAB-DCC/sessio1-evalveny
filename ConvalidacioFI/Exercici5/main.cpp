#include "quatre_ratlla.h"
#include <iostream>

using namespace std;

void mostraMatriu(int v[N_FILES][N_COLUMNES])
{
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}


bool comparaMatrius(int v1[N_FILES][N_COLUMNES], int v2[N_FILES][N_COLUMNES])
{
	bool iguals = true;
	int i = 0;
	int j;
	while ((i < N_FILES) && iguals)
	{
		j = 0;
		while ((j < N_COLUMNES) && iguals)
		{
			if (v1[i][j] != v2[i][j])
				iguals = false;
			else j++;
		}
		i++;
	}
	return iguals;
}


float testPosaFitxa()
{
	const int N_PROVES = 5;
	int taulerInicial[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0 }
		}
	};
	int columna[N_PROVES] = { 2, 0, 1, 6, 3 };
	int jugador[N_PROVES] = { 1, 2, 1, 2, 2 };
	int taulerFinal[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 }
		},
		{
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 2 },
			{ 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0 }
		}
	};
	bool resultat[N_PROVES] = {true, false, true, true, true};

	float reduccio = 0.0;
	bool resultatObtingut;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de posar fitxa" << endl;
	cout << "Comment :=>> ============================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i+1 << endl;
		cout << "Comment :=>> Tauler inicial: " << endl;;
		mostraMatriu(taulerInicial[i]);

		resultatObtingut = posaFitxa(taulerInicial[i], columna[i], jugador[i]);

		cout << "Comment :=>> Tauler final: " << endl;
		mostraMatriu(taulerInicial[i]);

		cout << "Comment :=>> Resultat obtingut: ";
		mostraBool(resultatObtingut);
		cout << endl;
		
		if ((resultatObtingut  == resultat[i]) && comparaMatrius(taulerInicial[i], taulerFinal[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava Tauler final: " << endl;
			mostraMatriu(taulerFinal[i]);
			cout << "Comment :=>> S'esperava Valor de retorn: ";
			mostraBool(resultat[i]);
			cout << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}

float testRatllaHoritzontal()
{
	const int N_PROVES = 8;
	int taulerInicial[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 1, 0, 0, 0 }
		},
		{
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 1, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 1, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 2, 2, 2, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 2, 2, 2, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 0, 0, 2, 1, 1, 1 }
		}
	};
	int fila[N_PROVES] = { 5, 5, 5, 5, 5, 5, 5, 5 };
	int columna[N_PROVES] = { 1, 1, 1, 1, 1, 1, 1, 4 };
	bool resultat[N_PROVES] = { true, false, false, false, false, false, false, false};

	float reduccio = 0.0;
	bool resultatObtingut;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de comprovar quatre en ratlla horitzontal" << endl;
	cout << "Comment :=>> =======================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Tauler: " << endl;;
		mostraMatriu(taulerInicial[i]);

		cout << "Comment :=>> Posicio a comprovar. Fila: " << fila[i] << ", Columna: " << columna[i] << endl;

		resultatObtingut = quatreRatllaHoritzontal(taulerInicial[i], fila[i], columna[i]);

		cout << "Comment :=>> Resultat comprovacio Quatre en Ratlla: ";
		mostraBool(resultatObtingut);
		cout << endl;

		if (resultatObtingut == resultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava Valor de retorn: ";
			mostraBool(resultat[i]);
			cout << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}

float testRatllaDiagonal()
{
	const int N_PROVES = 8;
	int taulerInicial[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0 },
			{ 0, 1, 1, 1, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0 },
			{ 1, 1, 1, 1, 0, 0, 0 }
		},
		{
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 1, 0, 0, 0, 0, 0 },
			{ 1, 1, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 1, 0, 0, 0, 0 },
			{ 0, 2, 1, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 2, 1, 0, 0, 0, 0, 0 },
			{ 2, 2, 1, 0, 0, 0, 0 },
			{ 2, 1, 1, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 0, 0, 0, 0 },
			{ 0, 1, 1, 2, 0, 0, 0 },
			{ 0, 2, 2, 2, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 2, 0, 0, 0, 0, 0, 0 },
			{ 1, 2, 0, 0, 0, 0, 0 },
			{ 1, 1, 2, 2, 0, 0, 0 },
			{ 1, 2, 2, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 2, 1, 0, 2, 0, 0, 0 },
			{ 2, 2, 1, 2, 1, 1, 1 }
		}
	};
	int fila[N_PROVES] = { 2, 2, 4, 3, 3, 2, 3, 3 };
	int columna[N_PROVES] = { 1, 1, 1, 1, 1, 1, 1, 0 };
	bool resultat[N_PROVES] = { true, false, false, false, false, false, false, false };

	float reduccio = 0.0;
	bool resultatObtingut;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de comprovar quatre en ratlla diagonal" << endl;
	cout << "Comment :=>> ====================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Tauler: " << endl;;
		mostraMatriu(taulerInicial[i]);

		cout << "Comment :=>> Posicio a comprovar. Fila: " << fila[i] << ", Columna: " << columna[i] << endl;

		resultatObtingut = quatreRatllaDiagonal(taulerInicial[i], fila[i], columna[i]);

		cout << "Comment :=>> Resultat comprovacio Quatre en Ratlla: ";
		mostraBool(resultatObtingut);
		cout << endl;

		if (resultatObtingut == resultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava Valor de retorn: ";
			mostraBool(resultat[i]);
			cout << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}

int main()
{
	float grade = 10.0;

	grade -= testPosaFitxa();
	grade -= testRatllaHoritzontal();
	grade -= testRatllaDiagonal();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}