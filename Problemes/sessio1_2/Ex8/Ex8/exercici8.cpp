/*
Test set:
5
9
4
###
158
89
36
###
69
58
100
###
*/

#include <iostream>

using namespace std;

int mesGran(int num1, int num2, int num3)
{
	int gran;

	if(num1 > num2)
	{
		if(num1 > num3)
		{
			gran = num1;
		}
		else
		{
			gran = num3;
		}
	}
	else
	{
		if(num2>num3)
		{
			gran = num2;
		}
		else
		{
			gran = num3;
		}
	}
	return(gran);
}

int main()
{
	int num1, num2, num3, gran;

    cout << "Introdueix tres numeros:"; 
	cin >> num1;
	cin >> num2;
	cin >> num3;
	gran = mesGran(num1, num2, num3);
	cout << "El numero mes gran es: " << gran;
	return 0;
}
