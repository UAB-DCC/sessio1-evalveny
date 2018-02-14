/*
Test set:
4
###
10
###
12
###
*/

#include <iostream>

using namespace std;

int main()
{
	int maxim, num1, num2, suma, i;

    cout << "Introdueix fins quin numero de fibonacci vols: ";
	cin >> maxim;
	num1 = 1;
	num2 = 2;
	cout << "#";
	cout << "1#" << num1 << "#" << num2 << "#";
	for(i = 3; i < maxim; i++)
	{
		suma = num1 + num2;
		cout << suma << "#";
		num1 = num2;
		num2 = suma;
	}
	return 0;
}
