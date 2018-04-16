#include <iostream>
using namespace std;


void intercanvia(int* p_x, int* p_y)
{
	int tmp;
	tmp = *p_x;
	*p_x = *p_y;
	*p_y = tmp;
}
void intercanviaMajorMenor(int v[], int mida,int* min, int* max)
{
	*min = 0;
	*max = 0;
	for (int i = 1; i < mida; i++)
	{
		if (v[*min] < v[i])
		{
			*min = i;
		}
		if (v[*max] > v[i])
		{
			*max = i;
		}
	}
	intercanvia(&v[*min], &v[*max]);
}

const int MAX = 10;
int main()
{
	int v[MAX] = {7,8,2,4,6,1,9,10,13,11};
	int min, max;
	intercanviaMajorMenor(v, MAX,min,max);
	for (int i = 0; i < MAX; i++)
	{
		cout << v[i] <<endl;
	}
	cout << "Min: " << min << " ; Max: " << max;

	return 0;
}
