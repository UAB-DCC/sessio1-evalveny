#include "ubicacions.h"
#include <iostream>
#include <math.h>

using namespace std;

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}


float testOmplePosicio()
{
	const int N_PROVES = 8;
	int graus[N_PROVES] = { 45, 45, 180, 45, 200, 45, 45, -30 };
	int minuts[N_PROVES] = { 45, 45, 45, 60, 45, 80, 45, 120 };
	int segons[N_PROVES] = { 45, 0, 45, 45, 45, 45, -45, 200 };
	char referencia[N_PROVES] = { 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E' };

	bool resultat[N_PROVES] = { true, true, true, true, false, false, false, false };

	float reduccio = 0.0;
	bool resultatObtingut;
	Posicio pos;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de omplir posicions" << endl;
	cout << "Comment :=>> =================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i+1 << endl;
		cout << "Comment :=>> Valors de la posicio a omplir. Graus: " << graus[i] << ", minuts: " << minuts[i] << ", segons: " << segons[i] << endl;

		resultatObtingut = omplePosicio(pos, graus[i], minuts[i], segons[i], referencia[i]);
		
		cout << "Comment :=>> Resultat obtingut: ";
		mostraBool(resultatObtingut);
		cout << endl;
		
		if (resultat[i] != resultatObtingut)
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava Resultat: ";
			mostraBool(resultat[i]);
			cout << endl;
			reduccio += 2.0;
		}
		else
			if (resultatObtingut)
			{
				cout << "Comment :=>> Posicio Obtinguda. Graus: " << pos.graus << ", minuts: " << pos.minuts << ", segons: " << pos.segons << endl;
				if ((pos.graus == graus[i]) && (pos.minuts == minuts[i]) && (pos.segons == segons[i]))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					cout << "Comment :=>> Valors de la posicio no correctes" << endl;
					reduccio += 2.0;
				}
			}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 5)
		reduccio = 5.0;
	return reduccio;
}


float testOmpleUbicacio()
{
	const int N_PROVES = 6;
	char referenciaLongitud[N_PROVES] = { 'E', 'O', 'N', 'E', 'Z', 'O' };
	char referenciaLatitud[N_PROVES] = { 'N', 'S', 'N', 'E', 'N', 'A' };

	bool resultat[N_PROVES] = { true, true, false, false, false, false };

	float reduccio = 0.0;
	bool resultatObtingut;
	
	Posicio longitud;
	Posicio latitud;
	longitud.graus = 45;
	longitud.minuts = 45;
	longitud.segons = 45;
	latitud.graus = 45;
	latitud.minuts = 45;
	latitud.segons = 45;
	
	string descripcio = "AAAAA";

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de omplir ubicacions" << endl;
	cout << "Comment :=>> ==================================" << endl;

	Ubicacio ub;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Valors de la ubicacio a omplir" << endl;
		cout << "Comment :=>> Descripcio: " << descripcio << endl;
		longitud.referencia = referenciaLongitud[i];
		latitud.referencia = referenciaLatitud[i];
		cout << "Comment :=>> Longitud. Graus: " << longitud.graus << ", minuts: " << longitud.minuts << ", segons: " << longitud.segons << ", referencia: " << longitud.referencia << endl;
		cout << "Comment :=>> Latitud. Graus: " << latitud.graus << ", minuts: " << latitud.minuts << ", segons: " << latitud.segons << ", referencia: " << latitud.referencia << endl;

		resultatObtingut = ompleUbicacio(ub, descripcio, longitud, latitud);

		cout << "Comment :=>> Resultat obtingut: ";
		mostraBool(resultatObtingut);
		cout << endl;

		if (resultat[i] != resultatObtingut)
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava Resultat: ";
			mostraBool(resultat[i]);
			cout << endl;
			reduccio += 2.0;
		}
		else
			if (resultatObtingut)
			{
				cout << "Comment :=>> Descripcio obtinguda: " << ub.descripcio << endl;
				cout << "Comment :=>> Longitud obtinguda. Graus: " << ub.longitud.graus << ", minuts: " << ub.longitud.minuts << ", segons: " << ub.longitud.segons << ", referencia: " << ub.longitud.referencia << endl;
				cout << "Comment :=>> Latitud obtinguda. Graus: " << ub.latitud.graus << ", minuts: " << ub.latitud.minuts << ", segons: " << ub.latitud.segons << ", referencia: " << ub.latitud.referencia << endl;
				if ((ub.longitud.referencia == referenciaLongitud[i]) && (ub.latitud.referencia == referenciaLatitud[i]))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					cout << "Comment :=>> Valors de la ubicacio no correctes" << endl;
					reduccio += 2.0;
				}
			}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 5)
		reduccio = 5.0;
	return reduccio;
}

float testCalculdistancia()
{
	const int N_PROVES = 8;
	const int MAX_LLISTA = 8;
	
	string descripcio[MAX_LLISTA] = { "P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8"};
	int grausLongitud[MAX_LLISTA] = { 45, 45, 45, 45, 30, 60, 30, 60 };
	int grausLatitud[MAX_LLISTA] = { 30, 60, 30, 60, 45, 45, 45, 45 };
	int minutsLongitud[MAX_LLISTA] = { 30, 30, 30, 30, 15, 45, 15, 45 };
	int minutsLatitud[MAX_LLISTA] = { 15, 45, 15, 45, 30, 30, 30, 30 };
	int segonsLongitud[MAX_LLISTA] = { 30, 30, 30, 30, 15, 45, 15, 45 };
	int segonsLatitud[MAX_LLISTA] = { 15, 45, 15, 45, 30, 30, 30, 30 };
	char referenciaLongitud[MAX_LLISTA] = { 'E', 'E', 'E', 'E', 'E', 'E', 'O', 'O' };
	char referenciaLatitud[MAX_LLISTA] = { 'N', 'N', 'S', 'S', 'N', 'N', 'N', 'N' };

	string descripcioOrigen[N_PROVES] = { "P0", "P1", "P1", "P3", "P1", "P6", "P8", "P7" };
	string descripcioFinal[N_PROVES] = { "P1", "P0", "P2", "P4", "P3", "P5", "P7", "P5" };
	float distanciaResultat[N_PROVES] = { -1, -1, 3396.17, 3396.17, 6735.76, 2365.57, 2365.57, 4603.4 };

	float reduccio = 0.0;
	float distanciaObtinguda;

	Ubicacio llistaUbicacions[MAX_LLISTA];
	Posicio longitud;
	Posicio latitud;
	for (int i = 0; i < MAX_LLISTA; i++)
	{
		omplePosicio(longitud, grausLongitud[i], minutsLongitud[i], segonsLongitud[i], referenciaLongitud[i]);
		omplePosicio(latitud, grausLatitud[i], minutsLatitud[i], segonsLatitud[i], referenciaLatitud[i]);
		ompleUbicacio(llistaUbicacions[i], descripcio[i], longitud, latitud);
	}

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de calcular distancies" << endl;
	cout << "Comment :=>> ====================================" << endl;

	cout << endl;
	cout << "Comment :=>> Contingut de la llista d'ubicacions" << endl;
	for (int i = 0; i < MAX_LLISTA; i++)
	{
		cout << "Comment :=>> Posicio " << i << endl;
		cout << "Comment :=>> Descripcio: " << llistaUbicacions[i].descripcio << endl;
		cout << "Comment :=>> Longitud. Graus: " << llistaUbicacions[i].longitud.graus << ", minuts: " << llistaUbicacions[i].longitud.minuts << ", segons: " << llistaUbicacions[i].longitud.segons << ", referencia: " << llistaUbicacions[i].longitud.referencia << endl;
		cout << "Comment :=>> Latitud. Graus: " << llistaUbicacions[i].latitud.graus << ", minuts: " << llistaUbicacions[i].latitud.minuts << ", segons: " << llistaUbicacions[i].latitud.segons << ", referencia: " << llistaUbicacions[i].latitud.referencia << endl;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Descripcio origen: " << descripcioOrigen[i] << ". Descripcio final: " << descripcioFinal[i] << endl;

		distanciaObtinguda = distancia(llistaUbicacions, MAX_LLISTA, descripcioOrigen[i], descripcioFinal[i]);

		cout << "Comment :=>> Distancia obtinguda: " << distanciaObtinguda << endl;;

		if (fabs(distanciaObtinguda - distanciaResultat[i]) < 0.1)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			cout << "Comment :=>> S'esperava: " << distanciaResultat[i] << endl;;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 5)
		reduccio = 5.0;
	return reduccio;
}


int main()
{
	float grade = 10.0;

	grade -= testOmplePosicio();
	grade -= testOmpleUbicacio();
	grade -= testCalculdistancia();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}