#include <iostream>
using namespace std;
#include "Titulacio.h"




int main()
{
	Titulacio t;

	Estudiant e1("joan", "1111111");
	t.afegeixEstudiant(e1);

	Estudiant e2("marta", "3333333");
	t.afegeixEstudiant(e2);

	Estudiant e3("josep", "2222222");
	t.afegeixEstudiant(e3);
	t.afegeixAssignaturaEstudiant("2222222", 02327, 6);

	t.mostraEstudiants();


	t.eliminaEstudiants();
	
	cout << endl;
	t.mostraEstudiants();

	return 0;
}
