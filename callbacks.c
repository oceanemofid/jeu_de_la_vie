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
    //logo ? joli dessin
}

void aleatoire(Widget w, char *string, void *data){
    int nbr_cycles = 80;
    int grille[M][N];
    if(string != '\0'){ //si strentry non nulle
        nbr_cycles = str_to_int(string);
    }
    initGrille(grille);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, nbr_cycles);
    }
    else{
        run_basique(grille, nbr_cycles);
    }
}

void stable(Widget w, void *data){
    int nbr_cycles = 10;
    int grille[M][N];
    conversion(grille,STABLE);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, nbr_cycles);
    }
    else{
        run_basique(grille, nbr_cycles);
    }
}

void vaisseau(Widget w, void *data){
    int nbr_cycles = 60;
    int grille[M][N];
    conversion(grille,VAISSEAU);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, nbr_cycles);
    }
    else{
        run_basique(grille, nbr_cycles);
    }
}

void montre(Widget w, void *data){
    int nbr_cycles = 40;
    int grille[M][N];
    conversion(grille,MONTRE);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, nbr_cycles);
    }
    else{
        run_basique(grille, nbr_cycles);
    }
}

void oscillateur(Widget w, void *data){
    int nbr_cycles = 40;
    int grille[M][N];
    conversion(grille,OSCILLATEUR);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, nbr_cycles);
    }
    else{
        run_basique(grille, nbr_cycles);
    }
}

void pentadecathlon(Widget w, void *data){
    int nbr_cycles = 80;
    int grille[M][N];
    conversion(grille,PENTADECATHLON);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, nbr_cycles);
    }
    else{
        run_basique(grille, nbr_cycles);
    }
}

void galaxie(Widget w, void *data){
    int nbr_cycles = 40;
    int grille[M][N];
    conversion(grille,GALAXIE);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    if(x){
        run_variante(grille, nbr_cycles);
    }
    else{
        run_basique(grille, nbr_cycles);
    }
}

//bleu=1;vert=2;rouge=3;jaune=4;
//bleu=vivantes et va rester en vie
//vert=va naitre
//rouge=va mourrir mais a deja vecu au moins 1 cycle
//jaune=va mourrir mais est resté en vie qu'un seul cycle

void afficher(int grille[M][N]){
    int size;
    int x = 0;
    int y = 0;
    size = 15;
    for(int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            if(grille[i][j]== 0){
                SetColor(BLACK);
            }
            else if(grille[i][j]== 1){
                SetColor(BLUE);
            }
            else if(grille[i][j]== 2){
                SetColor(GREEN);
            }
            else if(grille[i][j]== 3){
                SetColor(RED);
            }
            else if(grille[i][j]== 4){
                SetColor(YELLOW);
            }
            DrawFilledBox(x,y,size,size);
            x += size + 5;
        }
        x = 0;
        y += size + 5;
    }
}

void run_variante(int grille[M][N], int cycles){
    int i = 1;
    while(i<=cycles){
        delay(200);
        dayandnight(grille);
        afficher(grille);
        printf("Génération %d : \n", i);
        afficherGrille(grille);
        printf("\n");
        i++;
    }
    ClearDrawArea();
}

void run_basique(int grille[M][N], int cycles){
    int i = 1;
    while(i<=cycles){
        delay(200);
        basique(grille);
        afficher(grille);
        printf("Génération %d : \n", i);
        afficherGrille(grille);
        printf("\n");
        i++;
    }
    ClearDrawArea();

}