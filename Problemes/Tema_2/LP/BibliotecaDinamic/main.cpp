#include "Biblioteca.h"
#include <iostream>
using namespace std;

int main()
{
	Biblioteca b;
	Llibre l;
	float grade = 10;
	bool valid = true;

	b.llegirLlibres("biblioteca.txt");
	if (b.cercarLlibre("Thinking_in_Python", l))
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode cercarLLibre" << endl;
		grade -= 2;
	}
	bool trobat = b.cercarLlibre("The_C++_Programming_Language", l);
	if (!trobat)
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode cercarLLibre" << endl;
		grade -= 5;
	}
	trobat = b.cercarLlibre("Thinking_in_C++", l);
	if (!trobat)
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode cercarLLibre" << endl;
		grade -= 5;
	}
	else
	{
		if (l.retornar("01/01/2017", 1))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode retornar de llibre" << endl;
			grade -= 2;
		}
		int codi;
		if (!l.prestar("01/01/2017", codi))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode prestar de llibre" << endl;
			grade -= 2;
		}
		if (!l.prestar("01/01/2017", codi))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode prestar de llibre" << endl;
			grade -= 2;
		}
		if (!l.prestar("01/01/2017", codi))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode prestar de llibre" << endl;
			grade -= 2;
		}
		if (!l.prestar("01/01/2017", codi))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode prestar de llibre" << endl;
			grade -= 2;
		}
		if (!l.prestar("01/01/2017", codi))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode prestar de llibre" << endl;
			grade -= 2;
		}
		if (!l.prestar("01/01/2017", codi))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode prestar de llibre" << endl;
			grade -= 2;
		}
		if (l.retornar("01/01/2017", codi + 1))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode retornar de llibre" << endl;
			grade -= 2;
		}
		int codiAux = codi;
		if (l.prestar("01/01/2017", codi))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode prestar de llibre" << endl;
			grade -= 2;
		}
		if (!l.retornar("01/01/2017", codiAux))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode retornar de llibre" << endl;
			grade -= 2;
		}
	}
	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;

	return 0;

}