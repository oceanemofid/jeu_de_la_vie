/*
 * les callbacks de l’application, appelle fonctions modele + widget vue
 */
#include <stdlib.h>
#include <stdio.h>
#include <libsx.h> 
#include "modele.h"
#include "vue.h"
#include "callbacks.h"


/*
 * Rôle : termine l’exécution de l’application
 */
void quit(Widget w, void *d) {
    exit(EXIT_SUCCESS);
}

void basique(Widget w){
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
        MakeWindow("Test", NULL, 1);
        //afficher(grille,d);
}

void variante(Widget w){ //ouvrir fenêtre
    
}

void waitingscreen(){
    SetLineWidth(2);
    SetColor(RED);
    int x;
    int width = 36;
    for(int i = 0; i<M; i++){
        x = i * width;
        SetColor(BLACK);
        DrawFilledBox(x,x,width,width);
    }
}

void aleatoire(Widget w){
    if(GetMenuItemChecked(w)){ //Coché
        SetMenuItemChecked(w,0);
    }
    else{
        SetMenuItemChecked(w,1);
    }
}

void stable(Widget w){
    if(GetMenuItemChecked(w)){ //Coché
        SetMenuItemChecked(w,0);
    }
    else{
        SetMenuItemChecked(w,1);
    }
}

void vaisseau(Widget w){
    if(GetMenuItemChecked(w)){ //Coché
        SetMenuItemChecked(w,0);
    }
    else{
        SetMenuItemChecked(w,1);
    }
}

void afficher(int grille[M][N], void *data){
    int voisins, x, y, width, height;
    int u=0;
    width = 36;
    height = 36;
         
    for(int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            voisins = nbVoisins(grille,i,j);
            x = i * width;
            y = j * height;
            if(grille[i][j]== 0){
                SetColor(BLACK);
                DrawFilledBox(x,y,width,height);
            }
            else if(grille[i][j]== 1){
                SetColor(YELLOW);
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
    evolution(grille);
    AddTimeOut(2000, afficher,data);
}

