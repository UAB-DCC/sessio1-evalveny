#include "LlistatEspectacles.h"
#include <iostream>
#include <fstream>
using namespace std;

float testEspectacle()
{
	float punts = 0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------" << endl;
	cout << "Comment :=>> Iniciant test Espectacle" << endl;
	cout << "Comment :=>> ------------------------" << endl;
	cout << "Comment :=>>" << endl;

	LlistatEspectacles l(4);
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Afegint Espectacles:Nom Espectacle; Teatre; Data;        Hora;   Entrades; Preu" << endl;
	cout << "Comment :=>>                     E1                T1    01/01/2017   20:00   10        50.0" << endl;
	cout << "Comment :=>>                     E2                T2    01/02/2017   21:00   20        40.0" << endl;
	cout << "Comment :=>>                     E3                T3    01/03/2017   22:00    5        30.0" << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	l.afegeixEspectacle("E1", "T1", "01/01/2017", "20:00", 10, 50.0);
	l.afegeixEspectacle("E2", "T2", "01/02/2017", "21:00", 20, 40.0);
	l.afegeixEspectacle("E3", "T3", "01/03/2017", "22:00", 5, 30.0);

	float preu;
	string espectacleR[5] = { "E4", "E2", "E2", "E2", "E2" };
	string dataR[5] = { "01/01/2017" , "01/01/2017", "01/02/2017", "01/02/2017", "01/02/2017" };
	int nEntradesR[5] = { 10, 10, 10, 10, 10 };
	string espectador[5] = { "Espectador1", "Espectador1", "Espectador1", "Espectador2", "Espectador3" };
	int resultatR[5] = { -2, -2, 0, 0, -1 };
	int preuResultat[5] = { -1, -1, 400, 400, -1 };


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> RESERVANT ESPECTACLES                                                            " << endl;
	cout << "Comment :=>> Num Reserva, Espectacle, data        , Num Entrades, Nom Espectador, preu Esperat" << endl;
	cout << "Comment :=>> ---------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < 5; i++)
	{
		//cout << "Comment :=>> Num Reserva, Espectacle, data, Num Entrades, Nom Espectador, preu Esperat" << endl;
		cout << "Comment :=>>    " <<i <<"            " <<espectacleR[i] << "      " << dataR[i] << "       " << nEntradesR[i] << "            " << espectador[i] << "    " << preuResultat[i] << endl;
		int res = l.reservaEspectacle(espectacleR[i], dataR[i], nEntradesR[i], espectador[i], preu);
		if (res != resultatR[i])
		{
			cout << "Comment :=>> ERROR Reserva no s'ha fet correctament: Resultat Esperat: [" <<res << "]" <<" Resultat Obtingut: [" << resultatR[i] <<"]"<< endl;						
		}
		else 
		{
			cout << "Comment :=>> OK Reserva s'ha fet correctament: Resultat Esperat i Obtingut: [" << res << "]" << endl;	
			punts += 0.45;
		}
		if ((preuResultat[i] != -1) && (preu != preuResultat[i]))
		{			
			cout << "Comment :=>> ERROR Reserva preu obtingut incorrecte: Preu Esperat: [" << preuResultat[i] << "]" << " Preu Obtingut: [" << preu << "]"<< endl;			
		}
		else
		{
			cout << "Comment :=>> OK Reserva preu obtingut correcte: Preu Esperat i Preu Obtingut [" << preu << "]" << endl;
			punts += 0.45;
		}
		cout << "Comment :=>> ------------------------------------------------------------------------------" << endl;
	}
	

	string espectacleG[5] = { "E4", "E2", "E1", "E3", "E2" };
	string dataG[5] = { "01/01/2017" , "01/01/2017", "01/01/2017", "01/03/2017", "01/02/2017" };
	bool resultatG[5] = { false, false, true, true, true };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> DESANT FITXER ESPECTADORS                                                " << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < 5; i++)
	{
		
		bool resultatDesat = l.guardaEspectadors(espectacleG[i], dataG[i], "Espectadors.txt");
		cout << "Comment :=>> Num Desar, Espectacle,  Data       ,  Resultat Desar" << endl;
		cout << "Comment :=>>     " << i << "         " << espectacleG[i] << "        " <<dataG[i] <<"        ";
		if (resultatDesat)
		{
			cout << "TRUE" << endl;
		}
		else
		{
			cout << "FALSE" << endl;
		}
		
		if (resultatDesat != resultatG[i])
		{
			cout << "Comment :=>> ERROR comprovant metode guardaEspectadors:" << endl;
			
		}
		else
		{
			cout << "Comment :=>> OK comprovant metode guardaEspectadors:" << endl;
			punts += 0.75;
		}
		cout << "Comment :=>> -------------------------------------------------------------------------" << endl;

	}
	
	
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------------------------" << endl;
	cout << "Comment :=>> LLEGINT FITXER ESPECTADORS                                        " << endl;
	cout << "Comment :=>> -----------------------------------------------------------------" << endl;
	cout << "Comment :=>> Nom Espectador Esperat, Nombre Entrades Esperades" << endl;
	cout << "Comment :=>> -----------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

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

		cout << "Comment :=>> " <<nom[nEspectadors] << "                         " << nEntradesG[nEspectadors] << endl;
		if ((n != nom[nEspectadors]) || (e != nEntradesG[nEspectadors]))
		{

			cout << "Comment :=>> ERROR llegint Espectador: Nom Espectador Llegit: [" <<n <<"]" <<"Nombre Entrades Llegides: [" <<e <<"]" << endl;						
		}
		else
		{
			cout << "Comment :=>> OK llegint Espectador" << endl;
			punts += 0.5;
		}
		nEspectadors++;
		fitxer >> n >> e;
		cout << "Comment :=>> -----------------------------------------------------------------" << endl;
	}
	if (!fitxer.eof())
	{
		cout << "Comment :=>> ERROR llegint Espectador hem arribat a final de fitxer quan encara falten dades" << endl;
		
	}
	else
	{
		cout << "Comment :=>> OK llegint Espectador tenim totes les dades" << endl;
		punts += 0.75;
	}
	fitxer.close();

	return punts;
}

int main()
{
	float grade = 0;

	grade += testEspectacle();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}