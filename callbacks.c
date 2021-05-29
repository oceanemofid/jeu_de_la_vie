/*
 * les callbacks de l’application, appelle fonctions modele + widget vue
 */
#include <stdlib.h>
#include <stdio.h>
#include <libsx.h> 
#include <time.h>
#include "modele.h"
#include "vue.h"
#include "callbacks.h"

/*
 * Rôle : termine l’exécution de l’application
 */
void quit(Widget w, void *d) {
    exit(EXIT_SUCCESS); 
}

void waitingscreen(){
    
}

void aleatoire(Widget w, void *data){
    void *d;
    int grille[M][N];
    initGrille(grille);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,d);
    }
}

void stable(Widget w, void *data){
    void *d;
    int grille[M][N];
    conversion(grille,STABLE);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,d);
    }
}

void vaisseau(Widget w, void *data){
    int grille[M][N];
    void *d;
    conversion(grille,VAISSEAU);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,d);
    }
}

void montre(Widget w, void *data){
    void *d;
    int grille[M][N];
    conversion(grille,MONTRE);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,d);
    }
}

void oscillateur(Widget w, void *data){
    void *d;
    int grille[M][N];
    conversion(grille,OSCILLATEUR);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,d);
    }
}

void pentadecathlon(Widget w, void *data){
    void *d;
    int grille[M][N];
    conversion(grille,PENTADECATHLON);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,d);
    }
}

void galaxie(Widget w, void *data){
    void *d;
    int grille[M][N];
    conversion(grille,galaxie);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,d);
    }
}

void afficher(int grille[M][N]){
    int voisins, width, height;
    int x = 0;
    int y = 0;
    int u=0;
    width = 36;
    height = 36;
    //ClearDrawArea();
    for(int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            voisins = nbVoisins(grille,i,j);
            if(grille[i][j]== 0 || grille[i][j]== 48){
                SetColor(BLUE);
                DrawFilledBox(x,y,width,height);
            }
            else if(grille[i][j]== 1|| grille[i][j]== 49){
                SetColor(YELLOW);
                DrawFilledBox(x,y,width,height);
            }
            x += width + 3;
        }
        x = 0;
        y += height + 3;
    }
}

void run_variante(int grille[M][N], int *data){
    int i = 0;
    while(i<100){
        delay(200);
        dayandnight(grille);
        afficher(grille);
        i++;
    }
    ClearDrawArea();
}

void run_basique(int grille[M][N], int *data){
    int i = 0;
    while(i<100){
        delay(200);
        evolution(grille);
        afficher(grille);
        i++;
    }
    ClearDrawArea();
}