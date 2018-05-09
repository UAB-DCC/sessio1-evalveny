#include "Biblioteca.h"
#include <iostream>
using namespace std;

float testBiblio()
{
	float punts = 0;

	Biblioteca b;
	Llibre l;
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------" << endl;
	cout << "Comment :=>> Iniciant test Biblioteca" << endl;
	cout << "Comment :=>> ------------------------" << endl;
	cout << "Comment :=>>" << endl;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test Biblioteca: LlegirLlibres:" << endl;
	cout << "Comment :=>> ----------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	b.llegirLlibres("biblioteca.txt");
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------" << endl;
	cout << "Comment :=>> Cercant Thinking_in_Python:" << endl;
	cout << "Comment :=>> ---------------------------" << endl;
	cout << "Comment :=>>" << endl;

	bool trobat = b.cercarLlibre("Thinking_in_Python", l);
	if (trobat)
	{		
		cout << "Comment :=>> ERROR SI s'ha trobat Thinking_in_Python" << endl;		
	}
	else
	{
		cout << "Comment :=>> OK NO s'ha trobat Thinking_in_Python" << endl;
		punts += 2;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------" << endl;
	cout << "Comment :=>> Cercant The_C++_Programming_Language:" << endl;
	cout << "Comment :=>> -------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	trobat = b.cercarLlibre("The_C++_Programming_Language", l);
	if (!trobat)
	{
		cout << "Comment :=>> ERROR NO s'ha trobat The_C++_Programming_Language" << endl;
	}
	else
	{
		cout << "Comment :=>> OK SI s'ha trobat The_C++_Programming_Language" << endl;
		punts += 2;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------" << endl;
	cout << "Comment :=>> Cercant Thinking_in_C++:" << endl;
	cout << "Comment :=>> ------------------------" << endl;
	cout << "Comment :=>>" << endl;

	trobat = b.cercarLlibre("Thinking_in_C++", l);
	if (!trobat)
	{
		cout << "Comment :=>> ERROR NO s'ha trobat Thinking_in_C++" << endl;	
	}
	else
	{
		cout << "Comment :=>> OK SI s'ha trobat Thinking_in_C++" << endl;
		punts += 1;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------------------" << endl;
		cout << "Comment :=>> Retornant Thinking_in_C++(1): Tenim 6 exemplars cap prestat" << endl;
		cout << "Comment :=>> -----------------------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;

		if (l.retornar("01/01/2017", 1))
		{
			cout << "Comment :=>> ERROR a RETORNAR: permet retornar llibre Thinking_in_C++ que no esta prestat" << endl;			
		}
		else
		{
			cout << "Comment :=>> OK NO permet retornar llibre Thinking_in_C++ que no esta prestat" << endl;
			punts += 0.5;
		}

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Prestant Thinking_in_C++(1): Tenim 6 exemplars " << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;


		int codi;
		if (!l.prestar("01/01/2017", codi))
		{
			cout << "Comment :=>> ERROR a PRESTAR: NO permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;			
		}
		else
		{
			cout << "Comment :=>> OK a PRESTAR: SI permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
			punts += 0.5;
		}
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Prestant Thinking_in_C++(2): Tenim 6 exemplars " << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;
		if (!l.prestar("01/01/2017", codi))
		{
			cout << "Comment :=>> ERROR a PRESTAR: NO permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
		}
		else 
		{
			cout << "Comment :=>> OK a PRESTAR: SI permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
			punts += 0.5;
		}
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Prestant Thinking_in_C++(3): Tenim 6 exemplars " << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;
		if (!l.prestar("01/01/2017", codi))
		{
			cout << "Comment :=>> ERROR a PRESTAR: NO permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
		}
		else
		{
			cout << "Comment :=>> OK a PRESTAR: SI permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
			punts += 0.5;
		}
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Prestant Thinking_in_C++(4): Tenim 6 exemplars " << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;
		if (!l.prestar("01/01/2017", codi))
		{
			cout << "Comment :=>> ERROR a PRESTAR: NO permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
		}
		else
		{
			cout << "Comment :=>> OK a PRESTAR: SI permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
			punts += 0.5;
		}
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Prestant Thinking_in_C++(5): Tenim 6 exemplars " << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;
		if (!l.prestar("01/01/2017", codi))
		{
			cout << "Comment :=>> ERROR a PRESTAR: NO permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
		}
		else
		{
			cout << "Comment :=>> OK a PRESTAR: SI permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
			punts += 0.5;
		}
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Prestant Thinking_in_C++(6): Tenim 6 exemplars " << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;
		if (!l.prestar("01/01/2017", codi))
		{
			cout << "Comment :=>> ERROR a PRESTAR: NO permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
		}
		else
		{
			cout << "Comment :=>> OK a PRESTAR: SI permet prestar llibre Thinking_in_C++ del qual tenim exemplars sense prestar." << endl;
			punts += 0.5;
		}

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> ----------------------------------------------" << endl;
		cout << "Comment :=>> Retornant Thinking_in_C++ amb codi incorrecte " << endl;
		cout << "Comment :=>> ----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;

		if (l.retornar("01/01/2017", codi + 1))
		{
			cout << "Comment :=>> ERROR a RETORNAR: permet retornar llibre Thinking_in_C++ amb un codi de llibre inexistent" << endl;
		}
		else
		{
			cout << "Comment :=>> OK a RETORNAR: NO permet retornar llibre Thinking_in_C++ amb un codi de llibre inexistent" << endl;
			punts += 0.5;
		}

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Prestant Thinking_in_C++(7): Tenim 6 exemplars " << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;

		int codiAux = codi;
		if (l.prestar("01/01/2017", codi))
		{
			cout << "Comment :=>> ERROR a PRESTAR: SI permet prestar llibre Thinking_in_C++ del qual ja no tenim exemplars sense prestar." << endl;			
		}
		else
		{
			cout << "Comment :=>> OK a PRESTAR: NO permet prestar llibre Thinking_in_C++ del qual NO tenim exemplars sense prestar." << endl;
			punts += 0.5;			
		}

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> --------------------------------------------" << endl;
		cout << "Comment :=>> Retornant Thinking_in_C++ amb codi correcte " << endl;
		cout << "Comment :=>> --------------------------------------------" << endl;
		cout << "Comment :=>>" << endl;

		if (!l.retornar("01/01/2017", codiAux))
		{
			cout << "Comment :=>> ERROR a RETORNAR: NO permet retornar llibre Thinking_in_C++ amb un codi de llibre existent i prestat" << endl;			
		}
		else
		{
			cout << "Comment :=>> OK a RETORNAR: SI permet retornar llibre Thinking_in_C++ amb un codi de llibre existent i prestat" << endl;
			punts += 0.5;
		}
	}
	
	return punts;

}




int main()
{
	float grade = 0;

	grade += testBiblio();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}