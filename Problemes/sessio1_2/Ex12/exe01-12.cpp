/*
Test set:
programar
###
rossor
###
refer
###
*/

#include <iostream>

using namespace std;

bool esPalindrom(string frase)
{
	bool palindrom;
	int i = 0;
	do
	{
		palindrom = frase[i] == frase[frase.length() - i - 1];
		i++;
	}while((palindrom) && (i < frase.length() / 2));
	return palindrom;
}

int main()
{
	string frase;

    cout << "Introdueix una paraula:" <<endl;
	getline(cin, frase);
	if(esPalindrom(frase))
	{
		cout << "SI";
	}
	else
	{
		cout << "NO";
	}
	cout << " es palindrom";
	return 0;
}
