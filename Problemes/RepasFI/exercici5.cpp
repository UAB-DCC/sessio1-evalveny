/*
Test set:
10
###
154
###
548
###
*/

#include <iostream>

using namespace std;

int main()
{
	int num;

    cout << "Introdueix un numero: ";
	cin >> num;
	cout << "La seva representacio binaria es: ";
	cout << "#";
	while(num != 1)
    {
		cout << (num % 2);
		num /= 2;
	}
	cout << "1";
	cout << "#";
	return 0;
}
