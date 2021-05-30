#pragma once
#include <libsx.h>

#define M 16
#define N 16

enum {STABLE, VAISSEAU, MONTRE, OSCILLATEUR, PENTADECATHLON, GALAXIE};

extern void initGrille(int grille[M][N]);
extern int nbVoisins(int grille[M][N], int i, int j);
extern void basique(int grille[M][N]);
extern void dayandnight(int grille[M][N]);
extern void conversion(int grille[M][N], int nom); 
extern void afficherGrille(int grille[M][N]);
extern void delay(int number_of_seconds);
extern void Couleurs(int grille[M][N],int res[M][N]);
extern void InitCouleurs(int grille[M][N]);
extern void afficherT(int grille[M][N]);
extern void evolution(int grille[M][N]);
extern int str_to_int(char *string);
