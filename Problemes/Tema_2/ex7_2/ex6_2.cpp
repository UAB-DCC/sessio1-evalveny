/*
Enunciat:
Digues quin contingut tenen els dos enters del vector.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int x[2] = { 0,5 };
	int *p = &x[0];

	(*p)++;
	*(++p) += 1;
	p--;
	++*p;

	cout << x[0] << " " << x[1] << endl;

	system("pause");
	return 0;
}


