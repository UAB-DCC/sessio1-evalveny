
#include "Punt.h"
#include <iostream>
using namespace std;

const int MAXPUNTS1 = 3;
const int MAXPUNTS2 = 5;

void centroide(Punt* p1, Punt* p2,Punt* centroid)
{
	Punt* pAux;
	pAux = p1;

	float x = 0;
	float y = 0;
	int numVertex = 0;

	while (pAux != p2)
	{
		x += pAux->getX();
		y += pAux->getY();
		pAux++;
		numVertex++;
	}
	x += pAux->getX();
	y += pAux->getY();
	numVertex++;

	centroid->setX(x / numVertex);
	centroid->setY(y / numVertex);
	
}

void inicialitza(Punt* p1, Punt* p2, float* vx,float* vy)
{
	Punt* pAux;
	pAux = p1;

	while (pAux != p2)
	{
		pAux->setX(*vx);
		pAux->setY(*vy);
		vx++;
		vy++;		
		pAux++;
	}
	pAux->setX(*vx);
	pAux->setY(*vy);	
}

int main()
{
	Punt poligon1[MAXPUNTS1];
	float valors1X[MAXPUNTS1] = { 10, 15, 5};
	float valors1Y[MAXPUNTS1] = { 5, 10, 10};

	Punt poligon2[MAXPUNTS2];
	float valors2X[MAXPUNTS2] = { 0, 10, 10, 5, 0 };
	float valors2Y[MAXPUNTS2] = { 0, 0, 10, 15, 10 };

	Punt centroid1,centroid2;

	inicialitza(&poligon1[0], &poligon1[MAXPUNTS1 - 1], &valors1X[0], &valors1Y[0]);
	inicialitza(&poligon2[0], &poligon2[MAXPUNTS2 - 1], &valors2X[0], &valors2Y[0]);

	centroide(&poligon1[0], &poligon1[MAXPUNTS1 - 1],&centroid1);
	centroide(&poligon2[0], &poligon2[MAXPUNTS2 - 1],&centroid2);

	cout << "Centroid de Poligon1 es ( " << centroid1.getX() << "," << centroid1.getY() << ")" << endl;//Hauria de donar (10,8.33333)
	cout << "Centroid de Poligon2 es ( " << centroid2.getX() << "," << centroid2.getY() << ")" << endl;//Hauria de donar (5,7)

	return 0;
}