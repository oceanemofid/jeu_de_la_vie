#pragma once
extern void quit(Widget, void *);
extern void aleatoire(Widget w, void *data);
extern void stable(Widget w, void *data);
extern void vaisseau(Widget w, void *data);
extern void montre(Widget w, void *data);
extern void oscillateur(Widget w, void *data);
extern void pentadecathlon(Widget w, void *data);
extern void galaxie(Widget w, void *data);
extern void afficher(int grille[M][N]);
extern void waitingscreen(); 
extern void run_basique(int grille[M][N], int *data);
extern void run_variante(int grille[M][N], int *data);



#define LARGEUR 621
#define HAUTEUR 621

