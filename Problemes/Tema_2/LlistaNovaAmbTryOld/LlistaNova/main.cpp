#include "Llista.h"
#include <iostream>
using namespace std;

#include <signal.h>


typedef void(*SignalHandlerPointer)(int);

void SignalHandler(int signal)
{
	if (signal == SIGSEGV) {
		throw "Segmentation fault";
	}
	else {
		throw "Other Error";
	}
}


void escriuLlista(Llista &l, SignalHandlerPointer previousHandler)
{
	previousHandler = signal(SIGSEGV, SignalHandler);
	try
	{
		Node *aux = l.getInici();
		cout << "Comment :=>>  [ ";
		while (aux != NULL)
		{
			cout << aux->getValor();
			aux = aux->getNext();
			if (aux != NULL) cout << ",";
		}
		cout << " ]" << endl;
	}
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR EXECUCIO a EscriuLlista: " <<e << endl;
		l.reset();
		throw e;
	}
}

void escriuVector(int v[],int mida)
{
	cout << "Comment :=>>  [ ";
	for (int i = 0; i < mida; i++)
	{
		cout << v[i];		
		if (i != mida-1) cout << ",";
	}		
	cout << " ]" << endl;
}

void creaLlista(Llista &l, int valors[], int nValors, SignalHandlerPointer previousHandler)
{
	Node *aux = NULL;
	previousHandler = signal(SIGSEGV, SignalHandler);
	try
	{
		for (int i = 0; i < nValors; i++)
		{
			aux = l.insereixNext(valors[i], aux);
		}
	}
	catch (const char *e)
	//catch (...)
	{
		cout << "Comment :=>> ERROR EXECUCIO a crearLlista: " <<e << endl;
		l.reset();
		throw e;
	}		
}

void destrueixLlista(Llista &l, SignalHandlerPointer previousHandler)
{
	if (!l.esBuida())
	{
		previousHandler = signal(SIGSEGV, SignalHandler);
		try
		{
			while (l.eliminaNext(NULL) != NULL);
		}
		//catch (...)
		catch (const char *e)
		{
			cout << "Comment :=>> ERROR EXECUCIO a destrueixLlista: " <<e << endl;
			l.reset();
			throw e;
		}
	}
}

bool comparaLlista(Llista &l, int valors[], int nValors, SignalHandlerPointer previousHandler)
{
	bool iguals = true;
	Node *aux = l.getInici();
	int i = 0;
	previousHandler = signal(SIGSEGV, SignalHandler);
	try
	{
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
	//catch (...)
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR EXECUCIO a compararLlista: "<<e << endl;
		l.reset();
		throw e;		
	}

}


float testGetNElements(SignalHandlerPointer previousHandler)
{
	const int N_PROVES = 3;
	float punts = 0;
	int valorsLlista[N_PROVES][3] = { { 0, 2, 4 },{},{ 0 } };
	int nValorsLlista[N_PROVES] = { 3, 0, 1 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test CREAR LLISTA: NElements   " << endl;
	cout << "Comment :=>> ----------------------------------------" << endl;
	
	try
	{
		for (int i = 0; i < N_PROVES; i++)
		{
			//previousHandler = signal(SIGSEGV, SignalHandler);
		
			cout << "Comment :=>> Llista:" << i << endl;
			cout << "Comment :=>> Llista Original:" << endl;
			escriuVector(valorsLlista[i], nValorsLlista[i]);
			Llista l;
			creaLlista(l, valorsLlista[i], nValorsLlista[i], previousHandler);
			cout << "Comment :=>> Llista Creada:" << endl;
			escriuLlista(l, previousHandler);
			int nElems = l.getNElements();
			if (nElems != nValorsLlista[i])
			{
				cout << "Comment :=>> ERROR nombre Elements Llista incorrecte. Elements calculats: " << nElems << " : Elements esperats : " << nValorsLlista[i] << endl;
			}
			else
			{
				punts += 0.4;
				cout << "Comment :=>> OK nombre Elements Llista. Elements calculats: " << nElems << endl;
			}
			cout << "Comment :=>> ----------------------------------------" << endl;		
		}
	catch (...)
	{
		cout << "Comment :=>> ERROR EXECUCIO a TEST getNelements" << endl;
		l.reset();
		throw;
	}
	return punts;
}

float testSumaElements()// SignalHandlerPointer previousHandler)
{
	const int N_PROVES = 4;
	float punts = 0;
	int valorsLlista[N_PROVES][3] = { { 0, 2, 4 },{},{ 3 },{ 0 } };
	int nValorsLlista[N_PROVES] = { 3, 0, 1, 1 };
	int suma[N_PROVES] = { 6, 0, 3, 0 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------" << endl;
	cout << "Comment :=>> Iniciant test SUMA ELEMENTS   " << endl;
	cout << "Comment :=>> ------------------------------" << endl;


	for (int i = 0; i < N_PROVES; i++)
	{
		//previousHandler = signal(SIGSEGV, SignalHandler);
		try
		{
			cout << "Comment :=>> Llista:" << i << endl;
			cout << "Comment :=>> Llista Original:" << endl;
			escriuVector(valorsLlista[i], nValorsLlista[i]);

			Llista l;
			creaLlista(l, valorsLlista[i], nValorsLlista[i]);// , previousHandler);
			cout << "Comment :=>> Llista Creada:" << endl;
			escriuLlista(l);//, previousHandler);
			int sumaObtinguda = l.sumaElements();
			if (sumaObtinguda != suma[i])
			{
				cout << "Comment :=>> ERROR suma Elements. Suma calculada: " << sumaObtinguda << " : Suma esperada : " << suma[i] << endl;
			}
			else
			{
				cout << "Comment :=>> OK suma Elements. Suma calculada: " << sumaObtinguda << endl;
				punts += 0.4;
			}
			cout << "Comment :=>> ------------------------------" << endl;
		}
		catch (...)
		{
			cout << "Comment :=>> ERROR EXECUCIO a sumaelement" << endl;
			throw;
		}
	}
	return punts;
}


float testEliminaValor()//SignalHandlerPointer previousHandler)
{
	const int N_PROVES = 6;
	float punts = 0;
	int valorsLlista[N_PROVES][5] = { { 0, 2, 4, 2, 5 },
	{ 2, 2, 2 },
	{ 2, 0, 4 },
	{ 4, 0, 2 },
	{},
	{ 1, 3, 5 } };
	int nValorsLlista[N_PROVES] = { 5, 3, 3, 3, 0, 3 };
	int resultatLlista[N_PROVES][3] = { { 0, 4, 5 },
	{},
	{ 0, 4 },
	{ 4, 0 },
	{},
	{ 1, 3, 5 } };
	int nValorsResultat[N_PROVES] = { 3, 0, 2, 2, 0, 3 };
	int valors[N_PROVES] = { 2, 2, 2, 2, 2, 2 };
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------" << endl;
	cout << "Comment :=>> Iniciant test ELIMINA VALOR   " << endl;
	cout << "Comment :=>> ------------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		//previousHandler = signal(SIGSEGV, SignalHandler);
		try
		{
			cout << "Comment :=>> Llista:" << i << endl;
			cout << "Comment :=>> Llista Original:" << endl;
			escriuVector(valorsLlista[i], nValorsLlista[i]);

			Llista l;
			creaLlista(l, valorsLlista[i], nValorsLlista[i]);// , previousHandler);
			cout << "Comment :=>> Llista Creada ABANS ELIMINAR VALOR:" << endl;
			escriuLlista(l);// , previousHandler);
			l.eliminaValor(valors[i]);
			cout << "Comment :=>> Llista Creada DESPRES ELIMINAR VALOR: " << valors[i] << endl;
			escriuLlista(l);// , previousHandler);
			if (comparaLlista(l, resultatLlista[i], nValorsResultat[i]))//, previousHandler))
			{
				cout << "Comment :=>> OK ELIMINA VALOR." << endl;
				punts += 0.25;
			}
			else
			{
				cout << "Comment :=>> ERROR ELIMINA VALOR." << endl;
				cout << "Comment :=>> Llista Esperada despres ELIMINAR VALOR:" << endl;
				escriuVector(resultatLlista[i], nValorsResultat[i]);
			}
			cout << "Comment :=>> ------------------------------" << endl;
		}
		catch (...)
		{
			cout << "Comment :=>> ERROR EXECUCIO a eliminaValor" << endl;
			throw;
		}
	}
	return punts;
}


float testInverteixLlista(SignalHandlerPointer previousHandler)
{
	const int N_PROVES = 5;
	float punts = 0;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 5 },
	{ 2, 2, 2, 2 },
	{ 2 },
	{ 4, 2 },
	{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 1, 2, 0 };
	int resultatLlista[N_PROVES][4] = { { 5, 4, 2, 0 },
	{ 2, 2, 2, 2 },
	{ 2 },
	{ 2, 4 },
	{} };
	int nValorsResultat[N_PROVES] = { 4, 4, 1, 2, 0 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------" << endl;
	cout << "Comment :=>> Iniciant test INVERTEIX LLISTA" << endl;
	cout << "Comment :=>> ------------------------------" << endl;

	previousHandler = signal(SIGSEGV, SignalHandler);
	try
	{
		for (int i = 0; i < N_PROVES; i++)
		{
		
				cout << "Comment :=>> Llista:" << i << endl;
				cout << "Comment :=>> Llista Original:" << endl;
				escriuVector(valorsLlista[i], nValorsLlista[i]);

				Llista l;
				creaLlista(l, valorsLlista[i], nValorsLlista[i], previousHandler);
				cout << "Comment :=>> Llista Creada ABANS INVERTIR LLISTA:" << endl;
				escriuLlista(l, previousHandler);
				l.inverteixLlista();
				cout << "Comment :=>> Llista DESPRES INVERTIR LLISTA:" << endl;
				escriuLlista(l , previousHandler);
				if (comparaLlista(l, resultatLlista[i], nValorsResultat[i], previousHandler))
				{
					cout << "Comment :=>> OK INVERTIR LLISTA." << endl;
					punts += 0.35;
				}
				else
				{
					cout << "Comment :=>> ERROR INVERTIR LLISTA." << endl;
					cout << "Comment :=>> Llista Esperada despres INVERTIR LLISTA:" << endl;
					escriuVector(resultatLlista[i], nValorsResultat[i]);
				}
				cout << "Comment :=>> ------------------------------" << endl;			
		}
	}
	//catch (...)
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR EXECUCIO a TEST InverteixLlista" <<e<< endl;
		throw e;
	}
	return punts;
}

/*
float testAfegeixLlista(SignalHandlerPointer previousHandler)
{
	const int N_PROVES = 8;
	float punts = 0;
	int valorsLlista[N_PROVES][4] = { { 0, 2, 4, 5 },
	{ 0, 1, 2, 3 },
	{ 2, 4, 6, 8 },
	{ 0, 1 },
	{ 3, 5, 7 },
	{},
	{ 2 },
	{} };
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 2, 3, 0, 1, 0 };
	int valorsLlistaAfegeix[N_PROVES][4] = { { 0, 1, 3, 5 },
	{ 0, 1, 2, 3 },
	{ 1, 3, 5, 7 },
	{ 2, 3 },
	{ 0, 2 },
	{ 1, 3 },
	{},
	{} };
	int nValorsLlistaAfegeix[N_PROVES] = { 4, 4, 4, 2, 2, 2, 0, 0 };
	int resultatLlista[N_PROVES][8] = { { 0, 1, 2, 3, 4, 5 },
	{ 0, 1, 2, 3 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
	{ 0, 1, 2, 3 },
	{ 0, 2, 3, 5, 7 },
	{ 1, 3 },
	{ 2 },
	{} };
	int nValorsResultat[N_PROVES] = { 6, 4, 8, 4, 5, 2, 1, 0 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------------" << endl;
	cout << "Comment :=>> Iniciant test AFEGEIX LLISTA" << endl;
	cout << "Comment :=>> ----------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		previousHandler = signal(SIGSEGV, SignalHandler);
		try
		{
			cout << "Comment :=>> Llista:" << i << endl;
			cout << "Comment :=>> Llista Original 1:" << endl;
			escriuVector(valorsLlista[i], nValorsLlista[i]);

			Llista l;
			creaLlista(l, valorsLlista[i], nValorsLlista[i], previousHandler);
			cout << "Comment :=>> Llista1 Creada ABANS AFEGIR LLISTA:" << endl;
			escriuLlista(l, previousHandler);

			cout << "Comment :=>> Llista Original 2:" << endl;
			escriuVector(valorsLlistaAfegeix[i], nValorsLlistaAfegeix[i]);

			Llista lAfegeix;
			creaLlista(lAfegeix, valorsLlistaAfegeix[i], nValorsLlistaAfegeix[i], previousHandler);
			cout << "Comment :=>> Llista2 Creada ABANS AFEGIR LLISTA:" << endl;
			escriuLlista(lAfegeix, previousHandler);


			l.afegeixLlista(lAfegeix);
			cout << "Comment :=>> Llista1+2 DESPRES AFEGIR LLISTA:" << endl;
			escriuLlista(l, previousHandler);

			if (comparaLlista(l, resultatLlista[i], nValorsResultat[i], previousHandler))
			{
				cout << "Comment :=>> OK AFEGIR LLISTES." << endl;
				punts += 0.25;
			}
			else
			{
				cout << "Comment :=>> ERROR AFEGIR LLISTES." << endl;
				cout << "Comment :=>> Llista Esperada despres AFEGIR LLISTA 1 i 2:" << endl;
				escriuVector(resultatLlista[i], nValorsResultat[i]);
			}
			cout << "Comment :=>> ----------------------------" << endl;
		}
		catch (const char *e)
		{
			cout << "Comment :=>> " << e << endl;
		}
	}
	return punts;
}

float testInsereixOrdenat(SignalHandlerPointer previousHandler)
{
	const int N_PROVES = 8;
	float punts = 0;
	int valorsLlista[N_PROVES][4] = { { 2, 4, 6 },
	{ 2, 4, 6 },
	{ 2, 4, 6 },
	{ 2, 4, 6 },
	{ 2 },
	{ 2 },
	{ 2, 4 },
	{} };
	int nValorsLlista[N_PROVES] = { 3, 3, 3, 3, 1, 1, 2, 0 };
	int valors[N_PROVES] = { 1, 3, 5, 7, 1, 3, 1, 2 };
	int resultatLlista[N_PROVES][4] = { { 1, 2, 4, 6 },
	{ 2, 3, 4, 6 },
	{ 2, 4, 5, 6 },
	{ 2, 4, 6, 7 },
	{ 1, 2 },
	{ 2, 3 },
	{ 1, 2, 4 },
	{ 2 } };
	int nValorsResultat[N_PROVES] = { 4, 4, 4, 4, 2, 2, 3, 1 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------" << endl;
	cout << "Comment :=>> Iniciant test INSERIR ORDENAT" << endl;
	cout << "Comment :=>> -----------------------------" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		previousHandler = signal(SIGSEGV, SignalHandler);
		try
		{
			cout << "Comment :=>> Llista:" << i << endl;
			cout << "Comment :=>> Llista Original 1:" << endl;
			escriuVector(valorsLlista[i], nValorsLlista[i]);

			Llista l;
			creaLlista(l, valorsLlista[i], nValorsLlista[i], previousHandler);
			cout << "Comment :=>> Llista Creada ABANS INSERIR ELEMENT: [" << valors[i] << "]" << endl;
			escriuLlista(l, previousHandler);

			l.insereixOrdenat(valors[i]);

			cout << "Comment :=>> Llista DESPRES INSERIR ELEMENT: [" << valors[i] << "]" << endl;
			escriuLlista(l, previousHandler);
			if (comparaLlista(l, resultatLlista[i], nValorsResultat[i], previousHandler))
			{
				cout << "Comment :=>> OK INSERIR ELEMENT ORDENAT." << endl;
				punts += 0.25;
			}
			else
			{
				cout << "Comment :=>> ERROR INSERIR ELEMENT ORDENAT." << endl;
				cout << "Comment :=>> Llista Esperada despresINSERIR ELEMENT ORDENAT:[" << valors[i] << "]" << endl;
				escriuVector(resultatLlista[i], nValorsResultat[i]);
			}
			cout << "Comment :=>> -----------------------------" << endl;
		}
		catch (const char *e)
		{
			cout << "Comment :=>> " << e << endl;
		}
	}
	return punts;
}
*/

int main()
{
	float grade = 0;

	SignalHandlerPointer previousHandler;
	previousHandler = signal(SIGSEGV, SignalHandler); //SIGSEGV Illegal storage access

//	grade += testGetNElements();// previousHandler);
//	grade += testSumaElements();// previousHandler);
	//grade += testEliminaValor();// previousHandler);
	grade += testInverteixLlista(previousHandler);
//	grade += testAfegeixLlista(previousHandler);
//	grade += testInsereixOrdenat(previousHandler);

	if (grade < 0)
		grade = 0.0;
	if (grade >= 10.0)
	{
		grade = 10;
		cout << "Comment :=>> Final del test sense errors" << endl;
	}
	cout << "Grade :=>> " << grade << endl;

	return 0;
}