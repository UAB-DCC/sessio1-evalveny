#include "Activitat.h"
#include <iostream>
using namespace std;

const int MAXUSUARIS = 10;
const int MAXIMACTIVITATS = 100;

float testClasseUsuari(Usuari usuaris[])
{
	float punts=0;
	
	string nomSoci[MAXUSUARIS] = { "Joan","Maria","Vera","Aleix","Carles","Anna","Miriam","Jordi","Marga","Olga" };
	string codiSoci[MAXUSUARIS] = { "000","001","002","003","004","005","006","007","008","009" };
	int edatSoci[MAXUSUARIS] = { 3,5,101,70,9,20,30,26,29,47 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------------" << endl;
	cout << "Comment :=>> Iniciant test construccio Usuari" << endl;
	cout << "Comment :=>> --------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	for (int i = 0; i < MAXUSUARIS; i++)
	{
		Usuari u(codiSoci[i], nomSoci[i], edatSoci[i]);
		usuaris[i].copiaValor(u);
	}

	cout << "Comment :=>> Usuari (CODI:, NOM:, EDAT:)" << endl;
	for (int i = 0; i < MAXUSUARIS; i++)
	{
		cout << "Comment :=>> TEST " << i << ": (" << usuaris[i].getCodi() << ", " << usuaris[i].getNom() << ", " << usuaris[i].getEdat()  << ")" << endl;
		if ((usuaris[i].getCodi()!=codiSoci[i])||(usuaris[i].getNom()!=nomSoci[i])||(usuaris[i].getEdat()!= edatSoci[i]))
		{
			cout << "Comment :=>> ERROR TEST " << i << "SOLUCIO: ("<< codiSoci[i] << ", " << nomSoci[i] <<", " << edatSoci[i] << ")" << endl;
		}
		else
		{
			punts += 0.2;
		}
	}
	cout << "Comment :=>> -----------------------------" << endl;
	cout << "Comment :=>> Final test construccio Usuari" << endl;
	cout << "Comment :=>> Punts: " << punts << " (sobre: 2)" << endl;
	cout << "Comment :=>> -----------------------------" << endl;
	return punts;

}

float testClasseActivitat(Usuari usuaris[])
{
	Activitat activitats[MAXIMACTIVITATS];

	const int NUMTEST = 6;
	const int NUMACTIVITATS = 5;
	float punts=0;

	//string nomSoci[MAXUSUARIS] = { "Joan","Maria","Vera","Aleix","Carles","Anna","Miriam","Jordi","Marga","Olga" };
	//string codiSoci[MAXUSUARIS] = { "000","001","002","003","004","005","006","007","008","009" };
	//int edatSoci[MAXUSUARIS] = { 3,5,101,70,9,20,30,26,29,47 };

	string nomActivitats[NUMACTIVITATS] = { "SURF","VELA","FUTBOL","BASQUET","NATACIO" };
	string dies [NUMACTIVITATS] = { "dilluns","dimarts","dimecres","dijous","divendres" };
	string hores[NUMACTIVITATS] = { "9:00","8:00","18:00","19:00","17:00"};
	int edatMinima[NUMACTIVITATS] = {8,9,4,5,4};
	int edatMaxima[NUMACTIVITATS] = {60,70,50,50,100};
	int maximParticipants[NUMACTIVITATS] = {2,2,15,11,8};


	for (int i = 0; i < NUMACTIVITATS; i++)
	{
		Activitat a(nomActivitats[i], maximParticipants[i], edatMinima[i], edatMaxima[i], dies[i], hores[i]);
		activitats[i].copiaValor(a);				
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------" << endl;
	cout << "Comment :=>> Iniciant test construccio Activitat" << endl;
	cout << "Comment :=>> -----------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Activitat: (Nom: ,DIA: ,HORA: ,EdatMin: ,EdatMax: ,MaxParticipants: ,Participants: )" << endl;
	for (int i = 0; i < NUMACTIVITATS; i++)
	{
		cout << "Comment :=>> TEST " << i << ": ("  << activitats[i].getNom() << ", " << activitats[i].getDia() << ", " << activitats[i].getHora() << ", "
			 << activitats[i].getEdatMinima() << ", " <<activitats[i].getEdatMaxima() << ", " <<activitats[i].getMaximParticipants() << ", " <<activitats[i].getParticipants() << ")"<<endl;
		if ((activitats[i].getNom() != nomActivitats[i]) || (activitats[i].getDia() != dies[i]) || (activitats[i].getHora() != hores[i])||(activitats[i].getEdatMinima()!= edatMinima[i])||
			(activitats[i].getEdatMaxima()!= edatMaxima[i])||(activitats[i].getMaximParticipants()!= maximParticipants[i])||(activitats[i].getParticipants()!=0))
		{
			cout << "Comment :=>> ERROR TEST " << i << "SOLUCIO: (" << nomActivitats[i] << ", " << dies[i] << ", " << hores[i] << ", "
				<< edatMinima[i] << ", " << edatMaxima[i] << ", " << maximParticipants[i] << ", " << "0)" << endl;
		}
		else
		{
			punts += 0.4;
		}
	}
	cout << "Comment :=>> --------------------------------" << endl;
	cout << "Comment :=>> Final test construccio Activitat" << endl;
	cout << "Comment :=>> Punts: " << punts << " (sobre: 2)" << endl;
	cout << "Comment :=>> --------------------------------" << endl;
	

	//afegir participant
	float puntsParcials = 0;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------------" << endl;
	cout << "Comment :=>> Iniciant test afegir participant" << endl;
	cout << "Comment :=>> --------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	int indexUsuari[NUMTEST] = { 0,3,3,4,8,4};
	int indexActivitat[NUMTEST] = { 0,1,1,1,1,4};
	int resultAfegir[NUMTEST] = {-1,0,-2,0,-3,0};

	cout << "Comment :=>> ACTIVITAT: (Nom: ,DIA: ,HORA: ,EdatMin: ,EdatMax: ,MaxParticipants: ,Participants: )" << endl;
	cout << "Comment :=>> PARTICIPANT (CODI:, NOM:, EDAT:)" << endl;
	cout << "Comment :=>> RESULTAT: 0 (OK), -1 (Edat no valida),-2 (No hi ha places), -3 (Ja esta inscrit)" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < NUMTEST; i++)
	{
		cout << "Comment :=>> TEST " << i << endl;
		cout << "Comment :=>> ACTIVITAT: (" << activitats[indexActivitat[i]].getNom() << ", " << activitats[indexActivitat[i]].getDia() << ", " << activitats[indexActivitat[i]].getHora() << ", "
			<< activitats[indexActivitat[i]].getEdatMinima() << ", " << activitats[indexActivitat[i]].getEdatMaxima() << ", " << activitats[indexActivitat[i]].getMaximParticipants() << ", " 
			<< activitats[indexActivitat[i]].getParticipants() << ")" << endl;
		cout << "Comment :=>> PARTICIPANT: (" << usuaris[indexUsuari[i]].getCodi() << ", " << usuaris[indexUsuari[i]].getNom() << ", " << usuaris[indexUsuari[i]].getEdat() << ")" << endl;
		int codi = activitats[indexActivitat[i]].afegeixParticipant(usuaris[indexUsuari[i]]);
		cout << "Comment :=>> RESULTAT: " << codi << endl;
		if (codi!= resultAfegir[i])
		{
			cout << "Comment :=>> ERROR TEST " << i << " RESULTAT ESPERAT: " << resultAfegir[i] << endl;
		}
		else
		{
			puntsParcials += 0.5;
		}
	}

	cout << "Comment :=>> -----------------------------" << endl;
	cout << "Comment :=>> Final test afegir participant" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 3)" << endl;
	cout << "Comment :=>> -----------------------------" << endl;
	punts += puntsParcials;
	
	//busca participant
	puntsParcials = 0;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------" << endl;
	cout << "Comment :=>> Iniciant test busca participant" << endl;
	cout << "Comment :=>> -------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	
	bool resultBuscar[NUMTEST] = { false,true,true,true,false,true };
	for (int i = 0; i < NUMTEST; i++)
	{
		cout << "Comment :=>> TEST " << i << endl;
		cout << "Comment :=>> ACTIVITAT: (" << activitats[indexActivitat[i]].getNom() << ", " << activitats[indexActivitat[i]].getDia() << ", " << activitats[indexActivitat[i]].getHora() << ", "
			<< activitats[indexActivitat[i]].getEdatMinima() << ", " << activitats[indexActivitat[i]].getEdatMaxima() << ", " << activitats[indexActivitat[i]].getMaximParticipants() << ", "
			<< activitats[indexActivitat[i]].getParticipants() << ")" << endl;
		cout << "Comment :=>> PARTICIPANT: (" << usuaris[indexUsuari[i]].getCodi() << ", " << usuaris[indexUsuari[i]].getNom() << ", " << usuaris[indexUsuari[i]].getEdat() << ")" << endl;
		string nom = usuaris[indexUsuari[i]].getNom();
		bool resultBusca = activitats[indexActivitat[i]].buscaParticipant(nom);
		if (resultBusca)
		{
			cout << "Comment :=>> RESULTAT: TRUE" << endl;
			if (resultBusca != resultBuscar[i])
			{
				cout << "Comment :=>> ERROR RESULTAT ESPERAT: FALSE" << endl;
			}
			else
			{
				puntsParcials += 0.5;
			}
		}
		else
		{
			cout << "Comment :=>> RESULTAT: FALSE" << endl;
			cout << "Comment :=>> RESULTAT: TRUE" << endl;
			if (resultBusca != resultBuscar[i])
			{
				cout << "Comment :=>> ERROR RESULTAT ESPERAT: TRUE" << endl;
			}
			else
			{
				puntsParcials += 0.5;
			}
		}
		
	}
	cout << "Comment :=>> ----------------------------" << endl;
	cout << "Comment :=>> Final test busca participant" << endl;
	cout << "Comment :=>> Punts: " << puntsParcials << " (sobre: 3)" << endl;
	cout << "Comment :=>> ----------------------------" << endl;
	punts += puntsParcials;

	return punts;
}

int main()
{
	float grade = 0;

	Usuari usuaris[MAXUSUARIS];

	grade += testClasseUsuari(usuaris);
	grade += testClasseActivitat(usuaris);
	

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;

}