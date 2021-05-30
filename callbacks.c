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

void quit(Widget w, void *d) { //termine l’exécution de l’application
    exit(EXIT_SUCCESS); 
}

void waitingscreen(){ //petit dessin en attendant que l'utilisateur interagisse avec l'interface
    int size;
    int x = 0;
    int y = 0;
    size = 15;
    for(int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            if(x==y || x+y == 300){
               SetColor(RED);
            }
            else{
                SetColor(BLACK);
            }
            DrawFilledBox(x,y,size,size);
            x += size + 5;
        }
        x = 0;
        y += size + 5;
    }
}

void aleatoire(Widget w, char *string, void *data){ //population aléatoire
    int grille[M][N];
    int param[2];
    int res = str_to_param(string, param); //on va récupérer ce qui a été passé dans le widget
    if(res){ //si la fonction return exit failure -> quitte le jeu
        exit(EXIT_FAILURE);
    }
    initGrille(grille); //génération aléatoire de la population
    afficher(grille); //affichage interface
    //affichage textuel
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    //yes or no question pour utiliser la variante
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? \n(Explication : un individu nait d'une case vide a l'etape suivante \nsi elle est entouree de 3, 6, 7 ou 8 individus vivants, \nun individu vivant reste en vie a l'etape suivante \ns'il est entoure de 3, 4, 6, 7 ou 8 individus vivants)");
    if(x){ //si oui 
        if(param[1]){ //test si l'utilisateur veut faire apparaître les états intermédiaires
            InitCouleursV(grille); //initialise la grille pour les couleurs
        }
        run_variante(grille, param[0], param[1]); //appel générer les générations suivantes
    }
    else{
        if(param[1]){//test si l'utilisateur veut faire apparaître les états intermédiaires
            InitCouleurs(grille);//initialise la grille pour les couleurs
        }
        run_basique(grille, param[0], param[1]); //appel générer les générations suivantes
    }
}

void stable(Widget w, void *data){ //structure stable
    int grille[M][N];
    int param[2] = {10,0}; //nbr de générations à 10 par défaut et sans les états intermédiaires
    conversion(grille,STABLE); //convertit
    afficher(grille); //affichage interface
    //affichage textuel
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? \n(Explication : un individu nait d'une case vide a l'etape suivante \nsi elle est entouree de 3, 6, 7 ou 8 individus vivants, \nun individu vivant reste en vie a l'etape suivante \ns'il est entoure de 3, 4, 6, 7 ou 8 individus vivants)");
    if(x){
        run_variante(grille, param[0], param[1]);
    }
    else{
        run_basique(grille, param[0], param[1]);
    }
}

void vaisseau(Widget w, void *data){
    int param[2] = {60,0}; //nbr de générations à 60 par défaut et sans les états intermédiaires
    int grille[M][N];
    conversion(grille,VAISSEAU);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? \n(Explication : un individu nait d'une case vide a l'etape suivante \nsi elle est entouree de 3, 6, 7 ou 8 individus vivants, \nun individu vivant reste en vie a l'etape suivante \ns'il est entoure de 3, 4, 6, 7 ou 8 individus vivants)");
    if(x){
        run_variante(grille, param[0], param[1]);
    }
    else{
        run_basique(grille, param[0], param[1]);
    }
}

void montre(Widget w, void *data){
    int param[2] = {40,0}; //nbr de générations à 40 par défaut et sans les états intermédiaires
    int grille[M][N];
    conversion(grille,MONTRE);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? \n(Explication : un individu nait d'une case vide a l'etape suivante \nsi elle est entouree de 3, 6, 7 ou 8 individus vivants, \nun individu vivant reste en vie a l'etape suivante \ns'il est entoure de 3, 4, 6, 7 ou 8 individus vivants)");
    if(x){
        run_variante(grille, param[0], param[1]);
    }
    else{
        run_basique(grille, param[0], param[1]);
    }
}

void oscillateur(Widget w, void *data){
    int param[2] = {40,0}; //nbr de générations à 40 par défaut et sans les états intermédiaires
    int grille[M][N];
    conversion(grille,OSCILLATEUR);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? \n(Explication : un individu nait d'une case vide a l'etape suivante \nsi elle est entouree de 3, 6, 7 ou 8 individus vivants, \nun individu vivant reste en vie a l'etape suivante \ns'il est entoure de 3, 4, 6, 7 ou 8 individus vivants)");
    if(x){
        run_variante(grille, param[0], param[1]);
    }
    else{
        run_basique(grille, param[0], param[1]);
    }
}

void pentadecathlon(Widget w, void *data){
    int param[2] = {80,0}; //nbr de générations à 80 par défaut et sans les états intermédiaires
    int grille[M][N];
    conversion(grille,PENTADECATHLON);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? \n(Explication : un individu nait d'une case vide a l'etape suivante \nsi elle est entouree de 3, 6, 7 ou 8 individus vivants, \nun individu vivant reste en vie a l'etape suivante \ns'il est entoure de 3, 4, 6, 7 ou 8 individus vivants)");
    if(x){
        run_variante(grille, param[0], param[1]);
    }
    else{
        run_basique(grille, param[0], param[1]);
    }
}

void galaxie(Widget w, void *data){
    int param[2] = {40,0}; //nbr de générations à 40 par défaut et sans les états intermédiaires
    int grille[M][N];
    conversion(grille,GALAXIE);
    afficher(grille);
    printf("Génération %d : \n", 0);
    afficherGrille(grille);
    printf("\n");
    int x = GetYesNo("Voulez vous tester la variante Day and Night ? \n(Explication : un individu nait d'une case vide a l'etape suivante \nsi elle est entouree de 3, 6, 7 ou 8 individus vivants, \nun individu vivant reste en vie a l'etape suivante \ns'il est entoure de 3, 4, 6, 7 ou 8 individus vivants)");
    if(x){
        run_variante(grille, param[0], param[1]);
    }
    else{
        run_basique(grille, param[0], param[1]);
    }
}

//jaune=1;vert=2;rouge=3;bleu=4;
//jaune=vivantes et va rester en vie
//vert=va naitre
//rouge=va mourrir mais a deja vecu au moins 1 cycle
//bleu=va mourrir mais est resté en vie qu'un seul cycle

void afficher(int grille[M][N]){ //affichage interface en dessinant des carrés pour les individus
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
                SetColor(YELLOW);
            }
            else if(grille[i][j]== 2){
                SetColor(GREEN);
            }
            else if(grille[i][j]== 3){
                SetColor(RED);
            }
            else if(grille[i][j]== 4){
                SetColor(BLUE);
            }
            DrawFilledBox(x,y,size,size);
            x += size + 5;
        }
        x = 0;
        y += size + 5;
    }
}

void run_variante(int grille[M][N], int cycles, int couleur){ //affiche le nombre de generations choisi avec ou sans les états intermédiaires selon la variante
    int i = 1;
    if(couleur){ //si l'utilisateur a choisi d'afficher les états intermédiaires
        while(i<=cycles){
            delay(200);
            evolutionV(grille); 
            afficher(grille);
            printf("Génération %d : \n", i);
            afficherGrille(grille);
            printf("\n");
            i++;
        }
    }
    else{ //sans les états intermédiaires
        while(i<=cycles){
            delay(200);
            dayandnight(grille);
            afficher(grille);
            printf("Génération %d : \n", i);
            afficherGrille(grille);
            printf("\n");
            i++;
        }
    }
    
    ClearDrawArea();
}

void run_basique(int grille[M][N], int cycles, int couleur){ //affiche le nombre de generations choisi avec ou sans les états intermédiaires selon les règles de bases
    int i = 1;
    if(couleur){    //si l'utilisateur a choisi d'afficher les états intermédiaires
        while(i<=cycles){
            delay(200);
            evolution(grille);
            afficher(grille);
            printf("Génération %d : \n", i);
            afficherGrille(grille);
            printf("\n");
            i++;
        }
    }
    else{ //sans les états intermédiaires
        while(i<=cycles){
            delay(200);
            basique(grille);
            afficher(grille); 
            printf("Génération %d : \n", i);
            afficherGrille(grille);
            printf("\n");
            i++;
        }
    }
    
    ClearDrawArea();
}