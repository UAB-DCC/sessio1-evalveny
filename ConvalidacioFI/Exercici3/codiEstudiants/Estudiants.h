#pragma once

const int EDAT_MINIMA = 18;
const int EDAT_MAXIMA = 30;

void estadisticaEdats(int edatsEstudiants[], int nEstudiants, int frequenciaEdats[]);
void minimMaximEdat(int edatsEstudiants[], int &edatMinim, int &edatMaxim, int &nEstMinim, int &nEstMaxim);
