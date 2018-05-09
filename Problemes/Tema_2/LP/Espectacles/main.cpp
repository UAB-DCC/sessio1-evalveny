#include "LlistatEspectacles.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	float grade = 10;
	bool valid = true;

	LlistatEspectacles l(4);

	l.afegeixEspectacle("E1", "T1", "01/01/2017", "20:00", 10, 50.0);
	l.afegeixEspectacle("E2", "T2", "01/02/2017", "21:00", 20, 40.0);
	l.afegeixEspectacle("E3", "T3", "01/03/2017", "22:00", 5, 30.0);

	float preu;
	string espectacleR[5] = { "E4", "E2", "E2", "E2", "E2"};
	string dataR[5] = { "01/01/2017" , "01/01/2017", "01/02/2017", "01/02/2017", "01/02/2017" };
	int nEntradesR[5] = { 10, 10, 10, 10, 10 };
	string espectador[5] = { "Espectador1", "Espectador1", "Espectador1", "Espectador2", "Espectador3" };
	int resultatR[5] = { -2, -2, 0, 0, -1 };
	int preuResultat[5] = { -1, -1, 400, 400, -1 };

	for (int i = 0; i < 5; i++) 
	{
		if (l.reservaEspectacle(espectacleR[i], dataR[i], nEntradesR[i], espectador[i], preu) != resultatR[i])
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode reservaEspectacle" << endl;
			grade -= 2;
		}
		if ((preuResultat[i] != -1) && (preu != preuResultat[i]))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode reservaEspectacle (calcul preu)" << endl;
			grade -= 2;
		}
	}

	string espectacleG[5] = { "E4", "E2", "E1", "E3", "E2" };
	string dataG[5] = { "01/01/2017" , "01/01/2017", "01/01/2017", "01/03/2017", "01/02/2017" };
	bool resultatG[5] = { false, false, true, true, true };

	for (int i = 0; i < 5; i++)
	{
		if (l.guardaEspectadors(espectacleG[i], dataG[i], "Espectadors.txt") != resultatG[i])
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode guardaEspectadors" << endl;
			grade -= 2;
		}
	}
	ifstream fitxer;
	fitxer.open("Espectadors.txt");
	string nom[2] = { "Espectador1", "Espectador2" };
	int nEntradesG[2] = { 10, 10 };
	
	string n; 
	int e;
	fitxer >> n >> e;
	int nEspectadors = 0;
	while (!fitxer.eof() && (nEspectadors < 2))
	{
		if ((n != nom[nEspectadors]) || (e != nEntradesG[nEspectadors]))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode guardaEspectadors" << endl;
			grade -= 2;
		}
		nEspectadors++;
		fitxer >> n >> e;
	}
	if (!fitxer.eof())
	{
		valid = false;
		cout << "Comment :=>> Error comprovant metode guardaEspectadors" << endl;
		grade -= 2;
	}
	fitxer.close();

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;
	return 0;
}