#pragma once
#include <libsx.h>

#define M 16
#define N 16

enum {STABLE, VAISSEAU, MONTRE, OSCILLATEUR, PENTADECATHLON, GALAXIE};

extern void initGrille(int grille[M][N]);
extern int nbVoisins(int grille[M][N], int i, int j);
extern void evolution(int grille[M][N]);
extern void dayandnight(int grille[M][N]);
extern void conversion(int grille[M][N], int nom); 
extern void afficherGrille(int *pointeur);
extern void delay(int number_of_seconds);
