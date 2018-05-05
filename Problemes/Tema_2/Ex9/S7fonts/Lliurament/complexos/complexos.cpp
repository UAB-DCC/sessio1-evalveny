// complexos.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Complex.h"
#include <iostream>

using namespace std;


Complex *creaArrayComplexos(int *nComplexos)
{
	/* Aquesta funcio primer llegeix per teclat quants nombres complexos volem guardar i despres crea un array dinamic de nombres complexos amb tants elements com
	s'hagin indicat. La funcio retorna l'apuntador a l'array dinamic que s'ha creat. En el parametre per referencia nComplexos retornarem el nombre d'elements de l'array
	*/

	cin >> *nComplexos;
	Complex *complexos = new Complex[*nComplexos];
	return complexos;
}

void llegeixComplexos(Complex *complexos, int nComplexos)
{
	/* Aquesta funcio llegeix per teclat una sequencia de nombres complexos (primer la part real i despres la part imaginaria) i
	els guarda a l'array que es passa com a parametre. El parametre nComplexos es el nº d'elements de l'array */

	float real, img;
	for (int i = 0; i<nComplexos; i++)
	{
		cin >> real;
		cin >> img;
		complexos[i].setReal(real);
		complexos[i].setImg(img);
	}
}

void sumaComplexos(Complex *complexos, int nComplexos, Complex *suma)
{
	/* Aquesta funció calcula la suma de tots els nombres complexos de l'array que es passa com a parametre. El parametre nComplexos es el nº d'elements de l'array.
	El valor de la suma es retorna en el parametre per referencia suma. Heu d'utilitzar la funcio suma anterior */

	suma->setReal(0);
	suma->setImg(0);
	for (int i = 0; i<nComplexos; i++)
	{
		complexos[i].suma(suma);
	}
}

void conjugatComplexos(Complex *complexos, int nComplexos)
{
	/* Aquesta funcio obte el conjugat de tots els nombres complexos de l'array que es passa com a parametre, modificant els elements del propi array.
	El parametre nComplexos es el nº d'elements de l'array. Heu d'utilitzar la funcio conjugat anterior.
	*/

	for (int i = 0; i<nComplexos; i++)
	{
		complexos[i].conjugat();
	}
}

void mostraComplexos(Complex *complexos, int nComplexos)
{
	/* Aquesta funcio mostra per pantalla el valor de tots els nombres complexos de l'array que es passa com a parametre, utilitzant la funcio mostraComplex anterior.
	El parametre nComplexos es el nº d'elements de l'array.
	Cada nombre complex s'escriura com a partreal espai partimaginaria i ha d'estar seguit per un endl. Es a dir, el format de sortida ha de ser aquest 
	3 4
	5 6
	7 8
	
	*/
	
	for (int i = 0; i<nComplexos; i++)
	{
		complexos[i].mostraComplex();
	}
}

void destrueixArrayComplexos(Complex *complexos)
{
	/* Aquesta funcio ha d'alliberar la memoria dinamica ocupada per l'array de nombres complexos que es passa com a parametre */
	delete[] complexos;
}


int main()
{
	Complex *complexos;
	Complex suma;
	int nComplexos;

	complexos = creaArrayComplexos(&nComplexos);
	llegeixComplexos(complexos, nComplexos);
	sumaComplexos(complexos, nComplexos, &suma);
	suma.mostraComplex();
	conjugatComplexos(complexos, nComplexos);
	mostraComplexos(complexos, nComplexos);
	destrueixArrayComplexos(complexos);

	system("pause");

	return 0;
}

