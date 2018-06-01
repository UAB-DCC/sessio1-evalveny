#include "AvaluadorPostfix.h"

float testAvPostFix()
{
	float punts = 0;
	const int MAXTELFS = 10;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>> Iniciant test Avaluacio PostFix  " << endl;
	cout << "Comment :=>> ---------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	AvaluadorPostfix a;

	const int MAXOPS = 10;
	string Operacions[MAXOPS] = { "5 6 + 3 - " , "4 2 + 1 5 - * " ,"10 2 * 1 3 + / " ,"3 2 * 5 8 * 3 2 + * + " ,"2 2 + 2 * 8 / " ,"4 4 * 2 - " ,"2 5 + 2 * " ,"2 2 * 2 * " ,"5 5 * 5 + " ,"9 2 - 3 * " };
	float ResOperacions[MAXOPS] = { 8,-24,5,206,1,14,14,8,30,21};
	
	for (int i = 0; i < MAXOPS; i++)
	{
		float res = a.avaluar(Operacions[i]);

		cout << "Comment :=>> Res operacio [" << Operacions[i] << "]" << ": " << res << endl;
		if (res == ResOperacions[i])
		{
			cout << "Comment :=>> OK Resultat" << endl;
			punts += 1;
		}
		else
		{
			cout << "Comment :=>> ERROR Resultat Esperat: " << ResOperacions[i]  << endl;
		}

	}

	return punts;
}

int main()
{
	float grade = 0;

	grade += testAvPostFix();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;

}