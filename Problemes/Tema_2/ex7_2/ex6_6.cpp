/*
Enunciat:
Digues quin contingut tenen les variables x i y al finalitzar les seguents operacions.
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

const int N = 5;

int main()
{
	int x = 5, y = 10;
	int *p1;
	int **p2;

	p1 = &x;
	p2 = &p1;
	**p2 = y;
	p1 = &y;
	*p1 *= 2;
	(**p2)++;

	cout << x << " " << y;
	system("pause");
	return 0;
}
