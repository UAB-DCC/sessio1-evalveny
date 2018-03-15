#include "LlistatEspectacles.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	float grade = 10;
	bool valid = true;

	LlistatEspectacles l;
	l.inicialitza();

	string nomEspectacleAfegir[3] = { "E1", "E2", "E3"};
	string nomTeatreAfegir[3] = { "T1", "T2", "T3" };
	string dataAfegir[3] = { "01/01/2017" , "01/02/2017", "01/03/2017" };
	string horaAfegir[3] = { "20:00" , "21:00" ,"22:00" };
	int nEntradesAfegir[3] = { 10, 20, 5 };
	float preuAfegir[3] = { 50.0,40.0,30.0 };
	for (int i = 0; i < 3; i++)
	{
		//Espectacle e(nomEspectacleAfegir[i], nomTeatreAfegir[i], dataAfegir[i], horaAfegir[i], nEntradesAfegir[i], preuAfegir[i]);
		Espectacle e;
		e.setNom(nomEspectacleAfegir[i]);
		e.setTeatre(nomTeatreAfegir[i]);
		e.setDia(dataAfegir[i]);
		e.setHora(horaAfegir[i]);
		e.setEntradesTotals(nEntradesAfegir[i]);
		e.setPreu(preuAfegir[i]);
		l.afegeixEspectacle(e);		
	}
	

	float preu;
	string espectacleR[5] = { "E4", "E2", "E2", "E3", "E1" };
	string dataR[5] = { "01/01/2017" , "01/01/2017", "01/02/2017", "01/03/2017", "01/01/2017" };
	int nEntradesR[5] = { 10, 10, 10, 20, 10 };
	int resultatR[5] = { -2, -2, 0, -1, 0 };
	int preuResultat[5] = { -1, -1, 400, -1, 500 };
	for (int i = 0; i < 5; i++) 
	{
		cout << "Comment :=>> Prova:" << i << " compra Entrades: Espectacle:" << espectacleR[i] << " Data" << dataR[i] << " Num entrades:" << nEntradesR[i] <<endl;
		int resultatDonat = l.compraEntrades(espectacleR[i], dataR[i], nEntradesR[i], preu);
		if (resultatDonat != resultatR[i])
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode compraEntrades" << endl;
			cout << "Comment :=> Dona " <<resultatDonat <<" hauria de donar: " << resultatR[i] << endl;
			grade -= 1;
		}
		else
		{
			cout << "Comment :=>> CORRECTE Metode compraEntrades" << endl;
			cout << "Comment :=> Dona " << resultatDonat << endl;
		}
		if ((preuResultat[i] != -1) && (preu != preuResultat[i]))
		{
			valid = false;
			cout << "Comment :=>> Error comprovant metode compraEntrades (calcul preu)" << endl;
			cout << "Comment :=> Dona PREU:" << preu <<" hauria de donar PREU:" << preuResultat[i]  <<endl;
			grade -= 1;
		}
		else
		{
			if (preuResultat[i] == -1)
				cout << "Comment :=>> CORRECTE comprovant metode compraEntrades (calcul preu). No hi ha preu assignat perque no es poden comprar entrades." << endl;
			else
			{
				cout << "Comment :=>> CORRECTE comprovant metode compraEntrades (calcul preu)" << endl;
				cout << "Comment :=> Dona PREU:" << preu << endl;
			}
		}
	}

	string espectacleG[5] = { "E4", "E2", "E1", "E3", "E2" };
	string dataG[5] = { "01/01/2017" , "01/01/2017", "01/01/2017", "01/03/2017", "01/02/2017" };
	bool resultatG[5] = { false, false, true, true, true };

	
	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;
	return 0;
}