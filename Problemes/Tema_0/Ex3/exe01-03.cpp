/*
Test set:
3
###
5
###
7
###
*/

#include <iostream>

using namespace std;

void escriureTaula(int taula)
{
	int calcul;

    for(calcul = 1; calcul <= 10; calcul++)
	{
		cout << taula << "*" << calcul << "=" << (taula * calcul) << endl;
	}
}

int main()
{
	int taula;

    cout << "Introdueix un numero: ";
	cin >> taula;
	escriureTaula(taula);
	return 0;
}
