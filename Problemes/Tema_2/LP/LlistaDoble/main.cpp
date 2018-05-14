#include "LlistaDoble.h"
#include <iostream>
using namespace std;


void creaLlista(LlistaDoble &l, int valors[], int nValors)
{
	Node *aux = NULL;
	for (int i= 0; i < nValors; i++)
		aux = l.insereixNext(valors[i], aux);
}

void destrueixLlista(LlistaDoble &l)
{
	if (!l.esBuida())
	{
		while (l.eliminaNext(NULL) != NULL);
	}
}

bool comparaLlista(LlistaDoble &l, int valors[], int nValors)
{
	bool iguals = true;
	Node *aux = l.getInici();
	int i = 0;
	while (iguals && (aux != NULL) && (i < nValors))
	{
		if (aux->getValor() != valors[i])
			iguals = false;
		else
		{
			aux = aux->getNext();
			i++;
		}
	}
	iguals = iguals && (aux == NULL) && (i == nValors);
	aux = l.getFinal();
	i = nValors - 1;
	while (iguals && (aux != NULL) && (i >= 0))
	{
		if (aux->getValor() != valors[i])
			iguals = false;
		else
		{
			aux = aux->getPrev();
			i--;
		}
	}
	return (iguals && (aux == NULL) && (i == -1));
}

Node *getPosicioLlista(LlistaDoble &l, int posicio)
{
	Node *nodePosicio = NULL;
	Node *aux = l.getInici();
	for (int i = 0; i < posicio; i++)
	{
		nodePosicio = aux;
		aux = aux->getNext();
	}
	return nodePosicio;
}

bool testInsereixNext()
{
	const int N_PROVES = 8;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = {	{0, 2, 4, 6}, 
										{0, 2, 4, 6},
										{ 0, 2, 4, 6 },
										{ 0, 2, 4, 6 },
										{ 0, 2, 4, 6 },
										{0},
										{0},
										{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 4, 4, 1, 1, 0 };
	int posicioInserir[N_PROVES] = { 0, 1, 2, 3, 4, 0, 1, 0 };
	int valorInserir = 1;
	int resultatLlista[N_PROVES][5] = { { 1, 0, 2, 4, 6 },
										{ 0, 1, 2, 4, 6 },
										{ 0, 2, 1, 4, 6 },
										{ 0, 2, 4, 1, 6 },
										{ 0, 2, 4, 6, 1 },
										{1, 0},
										{0, 1},
										{1} };
	int nValorsResultat[N_PROVES] = { 5, 5, 5, 5, 5, 2, 2, 1 };
	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		Node *posicio = getPosicioLlista(l, posicioInserir[i]);
		l.insereixNext(valorInserir, posicio);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}

bool testInsereixPrev()
{
	const int N_PROVES = 8;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0 },
	{ 0 },
	{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 4, 4, 1, 1, 0 };
	int posicioInserir[N_PROVES] = { 1, 2, 3, 4, 0, 1, 0, 0 };
	int valorInserir = 1;
	int resultatLlista[N_PROVES][5] = { { 1, 0, 2, 4, 6 },
	{ 0, 1, 2, 4, 6 },
	{ 0, 2, 1, 4, 6 },
	{ 0, 2, 4, 1, 6 },
	{ 0, 2, 4, 6, 1 },
	{ 1, 0 },
	{ 0, 1 },
	{ 1 } };
	int nValorsResultat[N_PROVES] = { 5, 5, 5, 5, 5, 2, 2, 1 };
	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		Node *posicio = getPosicioLlista(l, posicioInserir[i]);
		l.insereixPrev(valorInserir, posicio);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}


bool testEliminaNext()
{
	const int N_PROVES = 8;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0 },
	{ 0 },
	{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 4, 4, 1, 1, 0 };
	int posicioEliminar[N_PROVES] = { 0, 1, 2, 3, 4, 0, 1, 0 };
	int resultatLlista[N_PROVES][4] = { { 2, 4, 6 },
	{ 0, 4, 6 },
	{ 0, 2, 6 },
	{ 0, 2, 4 },
	{ 0, 2, 4, 6 },
	{ },
	{ 0 },
	{  } };
	int nValorsResultat[N_PROVES] = { 3, 3, 3, 3, 4, 0, 1, 0 };
	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		Node *posicio = getPosicioLlista(l, posicioEliminar[i]);
		l.eliminaNext(posicio);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}


bool testEliminaPrev()
{
	const int N_PROVES = 8;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0 },
	{ 0 },
	{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 4, 4, 1, 1, 0 };
	int posicioEliminar[N_PROVES] = { 2 , 3, 4, 0, 1, 0, 1, 0 };
	int resultatLlista[N_PROVES][4] = { { 2, 4, 6 },
	{ 0, 4, 6 },
	{ 0, 2, 6 },
	{ 0, 2, 4 },
	{ 0, 2, 4, 6 },
	{},
	{ 0 },
	{} };
	int nValorsResultat[N_PROVES] = { 3, 3, 3, 3, 4, 0, 1, 0 };
	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		Node *posicio = getPosicioLlista(l, posicioEliminar[i]);
		l.eliminaPrev(posicio);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}


bool testEliminaActual()
{
	const int N_PROVES = 8;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0, 2, 4, 6 },
	{ 0 },
	{ 0 },
	{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 4, 4, 1, 1, 0 };
	int posicioEliminar[N_PROVES] = { 1 , 2, 3, 4, 0, 1, 0, 0 };
	int resultatLlista[N_PROVES][4] = { { 2, 4, 6 },
	{ 0, 4, 6 },
	{ 0, 2, 6 },
	{ 0, 2, 4 },
	{ 0, 2, 4, 6 },
	{},
	{ 0 },
	{} };
	int nValorsResultat[N_PROVES] = { 3, 3, 3, 3, 4, 0, 1, 0 };
	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		Node *posicio = getPosicioLlista(l, posicioEliminar[i]);
		l.eliminaActual(posicio);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}

int main()
{
	bool valid = true;
	float grade = 10;

	if (!testInsereixNext())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode insereixNext" << endl;
		grade -= 2;
	}
	if (!testInsereixPrev())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode insereixPrev" << endl;
		grade -= 2;
	}
	if (!testEliminaNext())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode eliminaNext" << endl;
		grade -= 2;
	}
	if (!testEliminaPrev())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode eliminaPrev" << endl;
		grade -= 2;
	}
	if (!testEliminaActual())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode eliminaActual" << endl;
		grade -= 2;
	}

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;
	return 0;
}