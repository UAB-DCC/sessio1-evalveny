#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex()
{
}


Complex::~Complex()
{
}

void Complex::setReal(float r)
{
	m_real = r;
}

void Complex::setImg(float i)
{
	m_img = i;
}

float Complex::getReal()
{
	return m_real;
}

float Complex::getImg()
{
	return m_img;
}

void Complex::suma(Complex *suma)
{
	/* Aquesta funcio rep com a parametre per referencia un nombre complex li suma el nombre complex actual i retorna el resultat acumulat en el parametre suma per referencia.
	*/
	suma->setReal(m_real + suma->getReal());
	suma->setImg(m_img + suma->getImg());

}

void Complex::conjugat()
{
	/* Aquesta funció modifica el valor del nombre complex perque passi a tenir el valor del número complex	conjugat respecte a l'original 
	(recordeu que per obtenir el conjugat d'un número complex cal canviar de signe la part imaginària)
	*/

	m_img = -m_img;
}

void Complex::mostraComplex()
{
	/* Aquesta funció mostra per pantalla el número complex, en el format real img amb un endl al final. Per exemple 3 4 */
	cout << m_real << " " << m_img <<endl;
}
