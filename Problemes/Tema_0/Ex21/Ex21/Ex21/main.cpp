
#include "CalculaQuadrat.h"
#include <math.h>
#include <iostream>
using namespace std;

void mostraMatriu(int m[N][M])
{
	cout << "Comment :=>>" << "[" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Comment :=>>"  << "[";
		for (int j = 0; j < M; j++)
		{
			cout << " " << m[i][j];
		}
		cout << "]" << endl;
	}		
	cout << "Comment :=>>" << "]" << endl;
}
void mostraMatriu(float m[N][M])
{
	cout << "Comment :=>>"<< "[" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Comment :=>>" << "[";
		for (int j = 0; j < M; j++)
		{
			cout << " " << m[i][j];
		}
		cout << "]" << endl;
	}
	cout << "Comment :=>>" << "]" << endl;
}
bool comparaFloat(float f1, float f2)
{
	float epsilon = 0.0001;
	bool aux= (fabs(f1 - f2) < epsilon);
	return aux;

}
bool comparaMatriu(float m1[N][M], float m2[N][M])
{
	bool iguals = true;
	int i = 0;
	while ((iguals) && (i < N))
	{
		int j = 0;
		while ((iguals) && (j < M))
		{
			if (! comparaFloat(m1[i][j],m2[i][j]))
				iguals = false;
			j++;
		}
		i++;
	}
	return iguals;
}

float testCalculaQuadratsMatriu()
{
	const int NPROVES = 2;


	int ParamsMatriu[NPROVES][N][M] =
	{
		{ {0, 1, 2},{3,4,5},{6,7,8}},
		{ {2, 3, 5},{3,4,9},{6,7,3}}
	};

	float resultat[NPROVES][N][M] =
	{
		{ {0, 0.0151515, 0.0215054},{0.0666667, 0.0606061, 0.0537634},{0.133333, 0.106061, 0.0860215}},
		{ {0.0408163, 0.0405405, 0.0434783},{0.0612245, 0.0540541, 0.0782609},{0.122449, 0.0945946, 0.026087}}
	};

	float matriuResultat[N][M];

	float reduccio = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test Quadrat matrius" << endl;
	cout << "Comment :=>> ===================================" << endl;

	for (int i = 0; i < NPROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Matrius a fer calcul quadrats: " << endl;
		mostraMatriu(ParamsMatriu[i]);
		cout << endl;
		
		calculaQuadrat(ParamsMatriu[i],matriuResultat);
		cout << "Comment :=>> Resultat obtingut: " << endl;
		mostraMatriu(matriuResultat);
		cout << endl;
		if (comparaMatriu(matriuResultat, resultat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR. S'esperava: " << endl;
			mostraMatriu(resultat[i]);
			reduccio += 5.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	return reduccio;
}

int main()
{
	float grade = 10.0;

	grade -= testCalculaQuadratsMatriu();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}