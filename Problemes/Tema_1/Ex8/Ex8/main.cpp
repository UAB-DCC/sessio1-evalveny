#include "Conjunt.h"


bool testIguals(Conjunt& c1,int v[],int mida)
{
	bool iguals = false;

	if (mida == c1.getNumElements())
	{
		iguals = true;
		int j = 0;
		while (iguals && (j < mida))
		{
			if (c1.pertany(v[j])==0)
			{
				iguals = false;
			}
			else
			{
				j++;
			}
		}
	}
	
	return iguals;
}

void imprimirVector(int v[], int mida)
{
	cout << "Comment :=>> [ ";
	for (int i = 0; i < mida; i++)
	{
		cout << v[i] << ",";
	}
	cout << " ]" << endl;
}

float testConjunt()
{
	float punts = 0;
	float puntsParcials = 0;
	const int MAXTEST = 5;
	const int MAXELEMS = 15;
	int v[MAXTEST][MAXELEMS] = { { 1,2,3,4,5,6,7,8,9,10,11,12 },
	                             { 13,14,15,16,17,18,19,20,21,22,23,24 },
								 { 1,2,3,4,5,6,7,8,9,10,11,12 },
								 { 25,26,27,28,29,30,31,32,33,34,35,36 },
								 { 37,38,39,40,41,42,43,44,45,46,47,48 },
	                           };
	int mida[MAXTEST] = { 12,12,12,12,12 };
	//Conjunt c[MAXTEST];

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------" << endl;
	cout << "Comment :=>> Iniciant test conjunt" << endl;
	cout << "Comment :=>> ---------------------" << endl;
	cout << "Comment :=>>" << endl;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ----------------------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test conjunt: Inicialitzacio, imprimir i pertany:" << endl;
	cout << "Comment :=>> ----------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;
	cout << "Comment :=>> CONJUNT N: [ el1,el2,...,eln ]" << endl;
	for (int i = 0; i < MAXTEST; i++)
	{
		Conjunt c(v[i], mida[i]);
		cout << "Comment :=>> CONJUNT " << i << ": ";
		c.imprimir();

		bool iguals = testIguals(c, v[i], mida[i]);

		if (!iguals)
		{
			cout << "Comment :=>> ERROR CONJUNT " << i << ": SOLUCIO ";
			imprimirVector(v[i], mida[i]);
		}
		else
		{
			puntsParcials += 0.4;
		}

	}
	
	cout << "Comment :=>> -------------------------------------------------------" << endl;
	cout << "Comment :=>> Final test conjunt: Inicialitzacio, imprimir i pertany:" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 2)" << endl;
	cout << "Comment :=>> -------------------------------------------------------" << endl;
	punts += puntsParcials;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------------------------------" << endl;
	cout << "Comment :=>> Iniciant test conjunt: Constructor Copia i operador ==" << endl;
	cout << "Comment :=>> ------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;

	Conjunt c(v[0], mida[0]);
	Conjunt copiat(c);
	cout << "Comment :=>> CONJUNT : ";
	copiat.imprimir();

	bool iguals = testIguals(copiat, v[0], mida[0]);

	if (!iguals)
	{
		cout << "Comment :=>> ERROR CONJUNT COPIAT: SOLUCIO ";
		imprimirVector(v[0], mida[0]);
	}
	else
	{
		cout << "Comment :=>> CORRECTE CONSTRUCTOR COPIA " << endl;
		puntsParcials += 0.5;
		int vOpIg[MAXELEMS] = { 12,11,10,9,8,7,6,5,4,3,2,1 };
		Conjunt cOpIg(vOpIg, mida[0]);
		if (c == cOpIg)
		{
			cout << "Comment :=>> CORRECTE OPERADOR == " << endl;
			puntsParcials += 0.5;
		}
		else
		{
			cout << "Comment :=>> ERROR OPERADOR == ";
		}		
	}

	cout << "Comment :=>> ----------------------------------------------------" << endl;
	cout << "Comment :=>> Final test conjunt: Constructor Copia i operador ==:" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 1)" << endl;
	cout << "Comment :=>> ----------------------------------------------------" <<endl;
	punts += puntsParcials;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------" << endl;
	cout << "Comment :=>> Iniciant test conjunt: +=" << endl;
	cout << "Comment :=>> -------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;

	int vResSuma[MAXELEMS*MAXTEST] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24, 1,2,3,4,5,6,7,8,9,10,11,12 , 25,26,27,28,29,30,31,32,33,34,35,36 , 37,38,39,40,41,42,43,44,45,46,47,48};
	int midaResSuma = mida[0];

	for (int i = 1; i < MAXTEST; i++)
	{
		Conjunt c2(v[i], mida[i]);
		c = c + c2;
		midaResSuma += mida[i];
	}
	cout << "Comment :=>> CONJUNTS SUMATS: " <<endl;
	for (int i = 0; i < MAXTEST; i++)
	{
		imprimirVector(v[i],mida[i]);
	}
	cout << "Comment :=>> RESULTAT CONJUNT TOTAL SUMAT: " <<endl;
	cout << "Comment :=>> ";
	c.imprimir();
	iguals = testIguals(c, vResSuma, midaResSuma);

	if (!iguals)
	{
		cout << "Comment :=>> ERROR CONJUNT SUMAT: SOLUCIO " <<endl;
		imprimirVector(vResSuma, midaResSuma);
	}
	else
	{
		cout << "Comment :=>> CORRECTE CONJUNT SUMAT "<<endl;
		puntsParcials += 2;
	}

	cout << "Comment :=>> ----------------------" << endl;
	cout << "Comment :=>> Final test conjunt: +:" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 2)" << endl;
	cout << "Comment :=>> ----------------------" << endl;
	punts += puntsParcials;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------------" << endl;
	cout << "Comment :=>> Iniciant test conjunt: + element" << endl;
	cout << "Comment :=>> --------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;
	int vResSumaElement[MAXELEMS*MAXTEST+1] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24, 1,2,3,4,5,6,7,8,9,10,11,12 , 25,26,27,28,29,30,31,32,33,34,35,36 , 37,38,39,40,41,42,43,44,45,46,47,48,50 };
	int midaResSumaElement = midaResSuma+1;

	c = c + 50;
	cout << "Comment :=>> CONJUNT: " <<endl;
	imprimirVector(vResSuma, midaResSuma);
	cout << "Comment :=>> ELEMENT A SUMAR 50. "<<endl;
	cout << "Comment :=>> RESULTAT CONJUNT SUMAT ELEMENT: "<<endl;
	c.imprimir();

	iguals = testIguals(c, vResSumaElement, midaResSumaElement);

	if (!iguals)
	{
		cout << "Comment :=>> ERROR CONJUNT SUMAT ELEMENT: SOLUCIO " <<endl;
		imprimirVector(vResSumaElement, midaResSumaElement);
	}
	else
	{
		cout << "Comment :=>> CORRECTE CONJUNT SUMAT ELEMENT" << endl;
		puntsParcials += 1.5;
	}

	cout << "Comment :=>> -------------------------------" << endl;
	cout << "Comment :=>> Final test conjunt: +=: element" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 1.5)" << endl;
	cout << "Comment :=>> -------------------------------" << endl;
	punts += puntsParcials;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------" << endl;
	cout << "Comment :=>> Iniciant test conjunt: -=" << endl;
	cout << "Comment :=>> -------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;

	int vResResta[MAXELEMS*MAXTEST+1] = { 1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12 , 37,38,39,40,41,42,43,44,45,46,47,48,50 };
	int midaResResta = midaResSumaElement;

	for (int i = 1; i < MAXTEST; i=i+2)
	{
		Conjunt c2(v[i], mida[i]);
		c = c - c2;
		midaResResta -= mida[i];
	}

	cout << "Comment :=>> CONJUNTS RESTATS: " << endl;
	imprimirVector(vResSumaElement, midaResSumaElement);
	for (int i = 1; i < MAXTEST; i=i+2)
	{
		imprimirVector(v[i], mida[i]);
	}
	cout << "Comment :=>> RESULTAT CONJUNT TOTAL RESTAT: " << endl;
	cout << "Comment :=>> ";
	c.imprimir();

	iguals = testIguals(c, vResResta, midaResResta);

	if (!iguals)
	{
		cout << "Comment :=>> ERROR CONJUNT RESTAT: SOLUCIO " <<endl;
		imprimirVector(vResResta, midaResResta);
	}
	else
	{
		cout << "Comment :=>> CORRECTE CONJUNT RESTAT " << endl;
		puntsParcials += 2;
	}

	cout << "Comment :=>> -----------------------" << endl;
	cout << "Comment :=>> Final test conjunt: -=:" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 2)" << endl;
	cout << "Comment :=>> -----------------------" << endl;
	punts += puntsParcials;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>> Iniciant test conjunt: -= element" << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	puntsParcials = 0;
	int vResRestaElement[MAXELEMS*MAXTEST - 1] = { 1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12 , 37,38,39,40,41,42,43,44,45,46,47,48 };
	int midaResRestaElement = midaResResta-1;

	c = c- 50;
	cout << "Comment :=>> CONJUNT: ";
	imprimirVector(vResResta, midaResResta);
	cout << "Comment :=>> ELEMENT A RESTAR 50. " << endl;
	cout << "Comment :=>> RESULTAT CONJUNT RESTAR ELEMENT: " << endl;
	c.imprimir();

	cout << "Comment :=>> CONJUNT RESTANT ELEMENT: " <<endl;
	cout << "Comment :=>> ";
	c.imprimir();

	iguals = testIguals(c, vResRestaElement, midaResRestaElement);

	if (!iguals)
	{
		cout << "Comment :=>> ERROR CONJUNT RESTA ELEMENT: SOLUCIO " <<endl;
		imprimirVector(vResRestaElement, midaResRestaElement);
	}
	else
	{
		cout << "Comment :=>> CORRECTE CONJUNT RESTA ELEMENT" <<endl;
		puntsParcials += 1.5;
	}

	cout << "Comment :=>> -------------------------------" << endl;
	cout << "Comment :=>> Final test conjunt: -=: element" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 1.5)" << endl;
	cout << "Comment :=>> -------------------------------" << endl;
	punts += puntsParcials;

	return punts;

}


int main()
{
	float grade = 0;

	grade += testConjunt();
	
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;

}