/*
Test set:
1
2
3
4
6
5
0
0
-1
-1
###
10.5
22.1
-32.2
45.3
65.2
-56.4
0
0
19.45
-18.34
###
*/

#include <iostream>

using namespace std;

const int MAX = 5;

typedef struct
{
    float real;
    float imaginari;
} Complex;

void llegeixComplex (Complex& c)
{
    cin >> c.real;
    cin >> c.imaginari;
}

int main()
{
    Complex arrayComplex[MAX];
    Complex suma = {0,0};

    for (int i = 0; i< MAX; i++)
        llegeixComplex(arrayComplex[i]);

    for (int i = 0; i< MAX; i++)
    {
        suma.real += arrayComplex[i].real;
        suma.imaginari += arrayComplex[i].imaginari;
    }

    cout << "(" << suma.real << "," << suma.imaginari << ")";
    return 0;
}
