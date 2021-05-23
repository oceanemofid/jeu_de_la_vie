#pragma once
#include <libsx.h>

#define M 4
#define N 4

extern void initGrille(int grille[M][N]);
extern int nbVoisins(int grille[M][N], int i, int j);
extern void evolution(int grille[M][N]);
extern void dayandnight(int grille[M][N]);
extern void afficherGrille(int *pointeur);