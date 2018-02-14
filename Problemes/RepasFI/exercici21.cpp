/*
Test set:
Pere
10
Joan
5
###
Pere
1
Joan
9
###
*/

#include <iostream>
#include "string.h"

using namespace std;

struct empleat{
	string nom;
	int salari;
};

int main()
{
	empleat empleat[2];

	cin >> empleat[0].nom;
	cin >> empleat[0].salari;
	cin.ignore();
	cin >> empleat[1].nom;
	cin >> empleat[1].salari;
	if(empleat[0].salari > empleat[1].salari)
	{
		cout << "En " << empleat[0].nom << " guanya mes que en " << empleat[1].nom;
	}
	else
	{
		cout << "En " << empleat[1].nom << " guanya mes que en " << empleat[0].nom;
	}
	return 0;
}
