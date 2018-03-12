#pragma once
#include "HistogramaNotes.h"
#include "Estudiant.h"

const int MAXESTUDIANTS = 20;
class Assignatura
{
public:
	Assignatura() { m_nEstudiants = 0; }
	void afegeixEstudiant(const Estudiant &e);
	void calculaHistograma();
	int notaMesRepetida() const;
private:
	Estudiant m_estudiants[MAXESTUDIANTS];
	HistogramaNotes m_histograma;
	int m_nEstudiants;
};

