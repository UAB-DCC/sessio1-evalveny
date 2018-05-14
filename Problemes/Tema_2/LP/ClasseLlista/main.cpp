#include "Llista.h"
#include <iostream>
using namespace std;


void creaLlista(Llista &l, int valors[], int nValors)
{
	Node *aux = NULL;
	for (int i= 0; i < nValors; i++)
		aux = l.insereixNext(valors[i], aux);
}

void destrueixLlista(Llista &l)
{
	if (!l.esBuida())
	{
		while (l.eliminaNext(NULL) != NULL);
	}
}

bool comparaLlista(Llista &l, int valors[], int nValors)
{
	bool iguals = true;
	Node *aux = l.getInici();
	int i = 0;
	while (iguals && (aux != NULL))
	{
		if (aux->getValor() != valors[i])
			iguals = false;
		else
		{
			aux = aux->getNext();
			i++;
		}
	}
	return (iguals && (aux == NULL) && (i == nValors));
}

bool testGetNElements()
{
	const int N_PROVES = 3;
	bool valid = true;
	int valorsLlista[N_PROVES][3] = { {0, 2, 4}, {}, {0  } };
	int nValorsLlista[N_PROVES] = { 3, 0, 1 };
	for (int i = 0; i < N_PROVES; i++)
	{
		Llista l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		valid = valid && (l.getNElements() == nValorsLlista[i]);
	}
	return valid;
}

bool testSumaElements()
{
	const int N_PROVES = 4;
	bool valid = true;
	int valorsLlista[N_PROVES][3] = { { 0, 2, 4 },{ },{ 3 },{ 0 } };
	int nValorsLlista[N_PROVES] = { 3, 0, 1, 1 };
	int suma[N_PROVES] = { 6, 0, 3, 0 };
	for (int i = 0; i < N_PROVES; i++)
	{
		Llista l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		valid = valid && (l.sumaElements() == suma[i]);
	}
	return valid;
}


bool testEliminaValor()
{
	const int N_PROVES = 6;
	bool valid = true;
	int valorsLlista[N_PROVES][5] = {	{ 0, 2, 4, 2, 5 },
										{ 2, 2, 2},
										{ 2, 0, 4 },
										{4, 0, 2}, 
										{}, 
										{1, 3, 5} };
	int nValorsLlista[N_PROVES] = { 5, 3, 3, 3, 0, 3 };
	int resultatLlista[N_PROVES][3] = {	{ 0, 4, 5 },
										{  },
										{ 0, 4},
										{ 4, 0}, 
										{},
										{ 1, 3, 5} }; 
	int nValorsResultat[N_PROVES] = { 3, 0, 2, 2, 0, 3 };
	int valors[N_PROVES] = { 2, 2, 2, 2, 2, 2 };
	for (int i = 0; i < N_PROVES; i++)
	{
		Llista l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		l.eliminaValor(valors[i]);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}


bool testInverteixLlista()
{
	const int N_PROVES = 5;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 5},
	{ 2, 2, 2, 2},
	{ 2 },
	{ 4, 2},
	{ } };
	int nValorsLlista[N_PROVES] = { 4, 4, 1, 2, 0 };
	int resultatLlista[N_PROVES][4] = { { 5, 4, 2, 0 },
	{ 2, 2, 2, 2 },
	{ 2},
	{ 2, 4},
	{  } };
	int nValorsResultat[N_PROVES] = { 4, 4, 1, 2, 0 };

	for (int i = 0; i < N_PROVES; i++)
	{
		Llista l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		l.inverteixLlista();
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}

bool testAfegeixLlista()
{
	const int N_PROVES = 8;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 5 },
	{ 0, 1, 2, 3 },
	{ 2, 4, 6, 8 },
	{ 0, 1 },
	{ 3, 5, 7},
	{},
	{2},
	{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 2, 3, 0, 1, 0 };
	int valorsLlistaAfegeix[N_PROVES][4] = { { 0, 1, 3, 5 },
	{ 0, 1, 2, 3 },
	{ 1, 3, 5, 7 },
	{ 2, 3 },
	{ 0, 2},
	{1, 3},
	{},
	{} };
	int nValorsLlistaAfegeix[N_PROVES] = { 4, 4, 4, 2, 2, 2, 0, 0 };
	int resultatLlista[N_PROVES][8] = { { 0, 1, 2, 3, 4, 5 },
	{ 0, 1, 2, 3 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
	{ 0, 1, 2, 3 },
	{0, 2, 3, 5, 7},
	{ 1, 3 }, 
	{ 2 },
	{} };
	int nValorsResultat[N_PROVES] = { 6, 4, 8, 4, 5, 2, 1, 0 };

	for (int i = 0; i < N_PROVES; i++)
	{
		Llista l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		Llista lAgegeix;
		creaLlista(lAgegeix, valorsLlistaAfegeix[i], nValorsLlistaAfegeix[i]);
		l.afegeixLlista(lAgegeix);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}

bool testInsereixOrdenat()
{
	const int N_PROVES = 8;
	bool valid = true;
	int valorsLlista[N_PROVES][4] = { { 2, 4, 6 },
	{ 2, 4, 6 },
	{ 2, 4, 6 },
	{ 2, 4, 6 },
	{ 2 },
	{ 2 },
	{ 2, 4},
	{ } };
	int nValorsLlista[N_PROVES] = { 3, 3, 3, 3, 1, 1, 2, 0 };
	int valors[N_PROVES] = { 1, 3, 5, 7, 1, 3, 1, 2};
	int resultatLlista[N_PROVES][4] = { { 1, 2, 4, 6 },
	{ 2, 3, 4, 6 },
	{ 2, 4, 5, 6 },
	{ 2, 4, 6, 7 },
	{ 1, 2 },
	{ 2, 3 },
	{ 1, 2, 4 },
	{ 2 } };
	int nValorsResultat[N_PROVES] = { 4, 4, 4, 4, 2, 2, 3, 1 };
	for (int i = 0; i < N_PROVES; i++)
	{
		Llista l;
		creaLlista(l, valorsLlista[i], nValorsLlista[i]);
		l.insereixOrdenat(valors[i]);
		valid = valid && (comparaLlista(l, resultatLlista[i], nValorsResultat[i]));
	}
	return valid;
}


int main()
{
	bool valid = true;
	float grade = 10;

	if (!testGetNElements())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode getNElements" << endl;
		grade -= 2;
	}
	if (!testSumaElements())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode sumaElements" << endl;
		grade -= 2;
	}
	if (!testEliminaValor())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode eliminaValor" << endl;
		grade -= 2;
	}
	if (!testInverteixLlista())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode inverteixLlista" << endl;
		grade -= 2;
	}
	if (!testAfegeixLlista())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode afegeixLlista" << endl;
		grade -= 2;
	}
	if (!testInsereixOrdenat())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode insereixOrdenat" << endl;
		grade -= 2;
	}

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;
	return 0;
}