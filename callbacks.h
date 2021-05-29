#pragma once
extern void quit(Widget, void *);
extern void aleatoire(Widget w, void *data);
extern void stable(Widget w, void *data);
extern void vaisseau(Widget w, void *data);
extern void montre(Widget w, void *data);
extern void afficher(int grille[M][N], void *data);
extern void waitingscreen(); 
extern void run_basique(void *data, XtIntervalId *id, int grille[M][N]);
extern void run_variante(void *data, XtIntervalId *id, int grille[M][N]);



#define LARGEUR 576
#define HAUTEUR 576

