#pragma once

const int N_FILES = 6;
const int N_COLUMNES = 7;

bool posaFitxa(int tauler[N_FILES][N_COLUMNES], int columna, int jugador);
bool quatreRatllaHoritzontal(int tauler[N_FILES][N_COLUMNES], int fila, int columna);
bool quatreRatllaDiagonal(int tauler[N_FILES][N_COLUMNES], int fila, int columna);



