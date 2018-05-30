#include "LlistaDoble.h"
#include <iostream>
using namespace std;

void escriuValors(int valors[], int nValors)
{
	cout << "Comment :=>> Valors:[";
	for (int i = 0; i < nValors-1; i++)
	{
		cout << valors[i] << ",";
	}
	cout << valors[nValors - 1] << "]" << endl;
}

void creaLlista(LlistaDoble &l, int valors[], int nValors)
{
	Node *aux = NULL;
	for (int i = nValors-1; i >=0; i--)
		aux = l.insereixPrev(valors[i], aux);
}

void destrueixLlista(LlistaDoble &l)
{
	while (l.getInici()!=NULL)
	{
		l.eliminaActual(l.getInici());
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

float testInsereixPrev()
{
	const int N_PROVES = 8;
	float punts = 0;

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

	cout << "Comment :=>> ===============================================" << endl;
	cout << "Comment :=>> comprovant metode insereixPrev " << endl;
	cout << "Comment :=>> ===============================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;

		cout << "Comment :=>> Creant Llista: " << i << endl;
		escriuValors(valorsLlista[i], nValorsLlista[i]);

		creaLlista(l, valorsLlista[i], nValorsLlista[i]);

		cout << "Comment :=>> Afegint element Prev: " << valorInserir << " a la posicio: " << posicioInserir[i] << endl;

		Node *posicio = getPosicioLlista(l, posicioInserir[i]);
		l.insereixPrev(valorInserir, posicio);
		cout << "Comment :=>> Comparant llista obtinguda" << endl;

		bool valid = comparaLlista(l, resultatLlista[i], nValorsResultat[i]);

		if (valid)
		{
			cout << "Comment :=>> OK llista obtinguda despres AFEGIRPREV" << endl;
			punts += 0.625;
		}
		else
		{
			cout << "Comment :=>> ERRORK llista obtinguda despres AFEGIRPREV" << endl;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return punts;
}


float testEliminaActual()
{
	const int N_PROVES = 8;
	float punts = 0;
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

	cout << "Comment :=>> ===============================================" << endl;
	cout << "Comment :=>> comprovant metode eliminaActual " << endl;
	cout << "Comment :=>> ===============================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;
		cout << "Comment :=>> Creant Llista: " << i << endl;
		escriuValors(valorsLlista[i], nValorsLlista[i]);

		creaLlista(l, valorsLlista[i], nValorsLlista[i]);

		cout << "Comment :=>> Eliminant element Actual a la posicio: " << posicioEliminar[i] << endl;
		Node *posicio = getPosicioLlista(l, posicioEliminar[i]);
		l.eliminaActual(posicio);

		cout << "Comment :=>> Comparant llista obtinguda" << endl;
		bool valid = comparaLlista(l, resultatLlista[i], nValorsResultat[i]);
		if (valid)
		{
			cout << "Comment :=>> OK llista obtinguda despres ELIMINAACT" << endl;
			punts += 0.625;
		}
		else
		{
			cout << "Comment :=>> ERRORK llista obtinguda despres ELIMINAACT" << endl;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return punts;
}

int main()
{
	bool valid = true;
	float grade = 0;

	grade += testInsereixPrev();

	cout << "Comment :=>> Punts despres de metode insereixPrev: " <<grade << endl;
		

	grade += testEliminaActual();
	
	cout << "Comment :=>> Punts despres de metode EliminaActual: " << grade << endl;
	
	if (grade==10)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;
	return 0;
}