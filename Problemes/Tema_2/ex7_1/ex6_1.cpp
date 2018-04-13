/*
Enunciat:
Digues quin contingut tenen les variables x i y al finalitzar les seguents operacions.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int x = 0, y = 1;
	int *p1, *p2;

	p1 = &x;
	p2 = &y;

	*p1 += 2;
	*p2 *= 4;

	*p1 = *p2;
	p1 = p2;
	*p1 = 10;

	cout << "x " << x << endl;
	cout << "y " << y << endl;
	
	system("pause");

	return 0;
}


