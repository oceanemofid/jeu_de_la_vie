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

void basique(Widget w, void *data){
    void *d;
    int grille[M][N];
    //int x = GetYesNo("Voulez vous generer aleatoirement une grille ? ");
    /*if(x){
        initGrille(grille);
    }
    else{
        //choix structure
        //conversion(grille);
    }*/
        
        //afficher(grille,d);
}

void variante(Widget w, void *data){ //ouvrir fenêtre
    SetColor(RED);
    int x;
    int width = 36;
    for(int i = 0; i<M; i++){
        x = i * width;
        SetColor(YELLOW);
        DrawFilledBox(x,x,width,width);
    }
}

void waitingscreen(){
    SetColor(RED);
    int x;
    int width = 36;
    for(int i = 0; i<M; i++){
        x = i * width;
        SetColor(BLACK);
        DrawFilledBox(x,x,width,width);
    }
}

void aleatoire(Widget w, void *data){
    void *d;
    int grille[M][N];
    initGrille(grille);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        //dayandnight(grille);
    }
    else{
        //evolution(grille);
    }
    afficher(grille, d);
}

void stable(Widget w, void *data){
    void *d;
    int grille[M][N];
    conversion(grille,STABLE);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        //dayandnight(grille);
    }
    else{
        //evolution(grille);
    }
    afficher(grille, d);
}

void vaisseau(Widget w, void *data){
    void *d;
    XtIntervalId *id;
    int grille[M][N], i;
    int *p = &grille[0][0];
    conversion(grille,VAISSEAU);
    afficher(grille, d);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(d,id, grille);
    }
    else{
        run_basique(d, id, grille);
    }
}

void montre(Widget w, void *data){
    void *d;
    int grille[M][N];
    conversion(grille,MONTRE);
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        //dayandnight(grille);
    }
    else{
        //evolution(grille);
    }
    afficher(grille, d);
}

void afficher(int grille[M][N], void *data){
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
                DrawFilledBox(x,y,width,height);
            }
            else{
                SetColor(RED);
                DrawFilledBox(x,y,width,height);
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
    //AddTimeOut(2000, afficher,data);
}

void run_variante(void *data, XtIntervalId *id, int grille[M][N]){
    afficher(grille, data);
    dayandnight(grille);
    AddTimeOut(2000, run_basique, data);
}

void run_basique(void *data, XtIntervalId *id, int grille[M][N]){
    evolution(grille);
    afficher(grille, data);
    AddTimeOut(2000, run_basique, data);
}