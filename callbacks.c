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

void generation_grille(Widget w, int grille [M][N]){
    //int grille[M][N];
    //int GetMenuItemChecked(Widget w); -> 1 : checked
    //selon l'iten checked, aléatoire ou ouverture du fichier
    //pour fichier conversion du binaire en grille 
    initGrille(grille);
    //ouvre fenetre
    //SetCurrentWindow(Widget w);
    run_basique(w, grille);
    run_variante(w, grille);
}

void afficher(int grille[M][N], Widget w){
    int voisins;
    for(int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            voisins = nbVoisins(grille,i,j);
            if(grille[i][j]== 0 && voisins == 3){
                //Draw
            }
            else if(grille[i][j]== 1 && voisins >= 4){
                //Draw
            }
            else if(grille[i][j]== 1 && voisins <=1){
                //Draw
            }
            else if(grille[i][j]== 0){
                //Draw
            }
            else{
                //Draw
            }
        }
    }
}

void run_basique(Widget w, int grille [M][N]){
    //boucle timer
    afficher(grille,w);
    evolution(grille);
    //Redisplay
    SyncDisplay();
    
}

void run_variante(Widget w, int grille [M][N]){
    //boucle timer
    afficher(grille,w);
    dayandnight(grille);
    //Redisplay
    SyncDisplay();
    
}