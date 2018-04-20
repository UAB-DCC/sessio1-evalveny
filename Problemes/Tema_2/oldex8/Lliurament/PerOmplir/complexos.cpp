// complexos.cpp: define el punto de entrada de la aplicación de consola.
//

#include "Complex.h"
#include <iostream>

using namespace std;


Complex *creaArrayComplexos(int *nComplexos)
{
	/* Aquesta funcio primer llegeix per teclat quants nombres complexos volem guardar i despres crea un array dinamic de nombres complexos amb tants elements com
	s'hagin indicat. La funcio retorna l'apuntador a l'array dinamic que s'ha creat. En el parametre per referencia nComplexos retornarem el nombre d'elements de l'array
	*/

}

void llegeixComplexos(Complex *complexos, int nComplexos)
{
	/* Aquesta funcio llegeix per teclat una sequencia de nombres complexos (primer la part real i despres la part imaginaria) i
	els guarda a l'array que es passa com a parametre. El parametre nComplexos es el nº d'elements de l'array */
}

void sumaComplexos(Complex *complexos, int nComplexos, Complex *suma)
{
	/* Aquesta funció calcula la suma de tots els nombres complexos de l'array que es passa com a parametre. El parametre nComplexos es el nº d'elements de l'array.
	El valor de la suma es retorna en el parametre per referencia suma. Heu d'utilitzar la funcio suma anterior */

}

void conjugatComplexos(Complex *complexos, int nComplexos)
{
	/* Aquesta funcio obte el conjugat de tots els nombres complexos de l'array que es passa com a parametre, modificant els elements del propi array.
	El parametre nComplexos es el nº d'elements de l'array. Heu d'utilitzar la funcio conjugat anterior.
	*/

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
	
}

void destrueixArrayComplexos(Complex *complexos)
{
	/* Aquesta funcio ha d'alliberar la memoria dinamica ocupada per l'array de nombres complexos que es passa com a parametre */

}


int main()
{
	/* El programa principal ha de fer el següent:
	1. Crear l'array dinàmic de números complexos (funció creaArrayComplexos)
	2. Llegir tots els números complexos (funció llegeixComplexos)
	3. Calcular la suma de tots els números complexos (funció sumaComplexos)
	4. Mostrar el resultat de la suma (funció mostraComplex), precedit i seguit per "#". Per exemple, #4@2#
	5. Obtenir el conjugat de tots els números complexos (funció conjugatComplexos)
	6. Mostrar el conjgat de tots els números complexos (funció mostraComplexos)
	7. Alliberar la memòria dinàmica (funció destrueixArrayComplexos)
	*/

	return 0;
}

