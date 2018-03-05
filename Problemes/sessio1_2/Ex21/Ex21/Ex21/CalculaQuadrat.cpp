#include <iostream>
#include "CalculaQuadrat.h"
using namespace std;

void calculaQuadrat(int m1[N][M],float result[N][M])
{

	for (int col = 0; col < N; col++)
	{
		float res = 0;
		for (int fil = 0; fil < M; fil++)
		{
			res += m1[fil][col] * m1[fil][col];
		}
		for (int fil = 0; fil < M; fil++)
		{
			result[fil][col]= m1[fil][col] /res;
		}
	}
}
