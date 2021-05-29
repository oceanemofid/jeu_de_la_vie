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
    int *p = &grille[0][0];
    conversion(grille,VAISSEAU);
    afficher(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, d);
    }
    else{
        run_basique(grille,p);
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

void afficher(int grille[M][N]){
    int voisins, x, y, width, height;
    int u=0;
    width = 36;
    height = 36;
    ClearDrawArea();
    for(int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            voisins = nbVoisins(grille,i,j);
            x = j * width;
            y = i * height;
            if(grille[i][j]== 0 || grille[i][j]== 48){
                SetColor(BLUE);
                DrawFilledBox(x,y,width,height);
            }
            else if(grille[i][j]== 1|| grille[i][j]== 49){
                SetColor(YELLOW);
                DrawFilledBox(0,0,width,height);
            }
        }
    }
    SetLineWidth(2);
    for(int i = 0; i<M; i++){
        u += width;
        SetColor(WHITE);
        DrawLine(u,0,u,LARGEUR);
        DrawLine(0,u,HAUTEUR,u);
    }
}

void run_variante(int grille[M][N], void *data){
    //while(delay(3)){
        dayandnight(grille);
        afficher(grille);
    //}
}

void run_basique(int grille[M][N], int *data){
    evolution(grille);
    delay(3);
    afficher(grille);
    evolution(grille);
    delay(3);
    afficher(grille);
    evolution(grille);
    afficher(grille);
    evolution(grille);
    afficher(grille);
    evolution(grille);
    afficher(grille);
    evolution(grille);
}