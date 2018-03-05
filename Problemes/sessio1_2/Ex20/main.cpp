//
//  main.cpp
//  funcions de rep�s
//


#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <math.h>
#include "ParitatParell.h"
#include "TestFuncionsRepas.h"
#include "DiaGregoria.h"
#include "Recorreguts.h"

using namespace std;

void test_de_funcions()
{
    bool valid = true;

    float  grade = 10;

	TestFuncionsRepas tester;
	if (!tester.testBitParitatParell())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio bitParitatParell" << endl;
        grade -= 1;
    }
    if (!tester.testLlegeixDia())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio llegeixDia" << endl;
        grade -= 1;
    }
    if (!tester.testEsTraspas())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio esTraspas" << endl;
        grade -= 1;
    }
    if (!tester.testEsValid())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio esValid" << endl;
        grade -= 1;
    }
	if (!tester.testTotalDies())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio totalDies" << endl;
        grade -= 1;
    }
	if (!tester.testDiferenciaDies())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio diferenciaDies" << endl;
        grade -= 1;
    }
	if (!tester.testMesFrequent())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio mesFrequent" << endl;
        grade -= 1;
    }	if (!tester.testUneixOrdenadament())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio uneixOrdenadament" << endl;
        grade -= 1;
    }
	if (!tester.testCercaPosicio())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio cercaPosicio" << endl;
        grade -= 1;
    }
	if (!tester.testAfegeixOrdenadament())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio afegeixOrdenadament" << endl;
        grade -= 1;
    }
	if (!tester.testUneixOrdenadament2())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio uneixOrdenadament2" << endl;
        grade -= 1;
    }
	if (!tester.testEsSimetrica())
    {
        valid = false;
        cout << "Comment :=>> Error comprovant funcio esSimetrica" << endl;
        grade -= 1;
    }
	if (valid)
        cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
    cout << "Grade :=>> " << grade << endl;

}

int main(int argc, const char* argv[])
{
	test_de_funcions();
}
