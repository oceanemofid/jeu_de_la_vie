/*
 * Les fonctions du modèle qui assure l'évolution de la population
 *
 * Note : module indépendant de toute interfaces utilisateurs
 */

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include "modele.h"
#include <time.h>
 
void initGrille(int grille[M][N]){ //crée une grille avec des individus placés aléatoirement
    time_t t;
    srand((unsigned) time(&t)); //initialise le générateur
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            grille[i][j] = rand() %2; // return un chiffre aléatoire de 0 à 1
        }
    }
}

void InitCouleurs(int grille[M][N]){ //initialise la grille de génération 0 pour savoir le temps de vie d'un individu (règles de bases)
    int voisins;
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){

            voisins = nbVoisins(grille,i,j);
            if (grille[i][j]==1){
                if (voisins>=4 || voisins<=1){
                    grille[i][j]=4; //n'a vécu qu'un seul cycle
                }
            }

            else if(grille[i][j] == 0){
                if(voisins==3){
                    grille[i][j]=2; //va naître
                }
            }
            
        }
    }
}

void InitCouleursV(int grille[M][N]){  ////initialise la grille de génération 0 pour savoir le temps de vie d'un individu (variante)
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            int voisins=nbVoisins(grille,i,j);
            if (grille[i][j]==1){
                if (voisins==1 || voisins==2 || voisins==5){
                    grille[i][j]=4;
                }
            }
            else{
                if(voisins==3 || voisins==6 || voisins==7 || voisins==8){
                    grille[i][j]=2;
                }
            }
        }
    }
}

int nbVoisins(int grille[M][N], int i, int j){ //compte le nbr de voisins vivants
    //extrémités par défaut
    int voisins = 0;
    int debutL = i-1;
    int debutC = j-1;
    int finL = i+1;
    int finC = j+1;
    //on gère les exceptions de bords
    if(i == 0){
        debutL = i;
    }
    else if(i == M-1){
        finL = i;
    }
    if(j == 0){
        debutC = j;
    }
    else if(j == N-1){
        finC = j;
    }

    for(int l = debutL; l<=finL; l++){ //parcourt tout autour de la cellule
        for(int m = debutC; m<=finC; m++){
            if(grille[l][m] == 1){
                voisins+=1;
            }
        }
    }
    if(grille[i][j] == 1){ //si la cellule est vivante elle a été comptée dans le nbr de voisins vivants
        voisins-=1; //on retire donc 1
    }
    return voisins;
}

//jaune=1;vert=2;rouge=3;bleu=4;
//jaune=vivantes et va rester en vie
//vert=va naitre
//rouge=va mourrir mais a deja vecu au moins 1 cycle
//bleu=va mourrir mais est resté en vie qu'un seul cycle


void Couleurs(int grille[M][N],int res[M][N]){ //attribue un nombre selon son état qui correspond à une couleur (règles de bases)

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){

        int voisins=nbVoisins(res,i,j);

            if (res[i][j]==1){
                if (voisins>3||voisins<2){
                    if (grille[i][j]==2){
                        res[i][j]=4;// n'a vécu qu'un seul cycle
                    }
                    else{
                        res[i][j]=3; //a vécu plus d'un cycle
                    }
                }
            }

            else{
                if(voisins==3){
                    res[i][j]=2; //va naître
                }
            }
        }
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            grille[i][j]=res[i][j];
        }
    }
}

void CouleursV(int grille[M][N],int res[M][N]){ //attribue un nombre selon son état qui correspond à une couleur (variante)
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            int voisins=nbVoisins(res,i,j);
            if (res[i][j]==1){
                if (voisins==1 || voisins==2 || voisins==5){
                    if (grille[i][j]==2){
                        res[i][j]=4;
                    }
                    else{
                        res[i][j]=3;
                    }
                }
            }   
            else{
                if(voisins==3 || voisins==6 || voisins==7 || voisins==8){
                    res[i][j]=2;
                }
            }
        }
    }
}

void basique(int grille[M][N]){ //détermination de la génération suivante selon les règles de bases et sans états intermédiaires
    int i, j;
    int voisins;
    int res[M][N]; //grille intermédiaire

    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            res[l][m] = grille[l][m]; //res = grille
        }
    }
   
    for(i = 0; i<M; i++){
        for (j = 0; j<N; j++){
            voisins = nbVoisins(grille, i, j); //on récupère le nbr de voisins vivants
            if(voisins == 3){
                //naissance
                res[i][j] = 1;
            }
            else if(voisins < 2 || voisins >= 4){
                //mort par étouffement et par isolement
                res[i][j] = 0;
            }
        }
    }
    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            grille[l][m] = res[l][m]; //grille = res
        }
    }
}

void evolution(int grille[M][N]){ //détermination de la génération suivante selon les règles de bases et avec états intermédiaires
    int res[M][N]; //grille intermédiaire
    
    //remplissage de res
    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){

            switch (grille[l][m]) {
                case 0: res[l][m]=0;break;
                case 1: res[l][m]=1;break;
                case 2: res[l][m]=1;break;
                case 3: res[l][m]=0;break;
                case 4: res[l][m]=0;break;
            }
        }
    }
    Couleurs(grille,res);
}

void dayandnight(int grille[M][N]){ //détermination de la génération suivante selon la variante dayandnight et sans états intermédiaires
    int i, j;
    int voisins;
    int res[M][N]; //grille intermédiaire

    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            res[l][m] = grille[l][m]; //res = grille
        }
    }
   
    for(i = 0; i<M; i++){
        for (j = 0; j<N; j++){
            voisins = nbVoisins(grille, i, j); //on récupère le nbr de voisins vivants
            if(voisins <= 2 || voisins == 5){
                //mort
                res[i][j] = 0;
            }
            else{
                //naissance ou survie 
                res[i][j] = 1;
            }
        }
    }
    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            grille[l][m] = res[l][m]; //grille = res
        }
    }
}

void evolutionV(int grille[M][N]){ //détermination de la génération suivante selon la variante dayandnight et avec états intermédiaires
    int res[M][N]; //grille intermédiaire

    //remplissage de res
    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            switch (grille[l][m]) {
                case 0: res[l][m]=0;break;
                case 1: res[l][m]=1;break;
                case 2: res[l][m]=1;break;
                case 3: res[l][m]=0;break;
                case 4: res[l][m]=0;break;
            }
        }
    }
    CouleursV(grille,res);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            grille[i][j]=res[i][j];
        }
    }
}

void afficherGrille(int grille[M][N]){ //affiche la grille en mode textuel 
    for(int i = 0; i<M ; i++){
        for (int j = 0; j<N; j++){
            if(grille[i][j] == 1){
                printf("\033[0;33m"); //jaune
            }
            else if(grille[i][j] == 2){
                printf("\033[0;32m"); //vert
            }
            else if(grille[i][j] == 3){
                printf("\033[0;31m"); //rouge
            }
            else if(grille[i][j] == 4){
                printf("\033[0;34m"); //bleu 
            }
            printf("%2d", grille[i][j]); //on affiche la valeur du tableau
            printf("\033[0m"); //reset de la couleur
            printf(" |"); //séparateur de cellules 
        }
        printf("\n"); //ligne suivante
    }
    
}

void conversion(int grille[M][N], int nom){ //convertit un fichier binaire .txt en une grille correspondant à la structure
    FILE *file;
    switch (nom){ //ouvre le bon file selon le nom passé en paramètre
    case STABLE:
         file = fopen("stable.txt", "r");
        break;
    case VAISSEAU:
         file = fopen("vaisseau_simple.txt", "r");
        break;
    case MONTRE:
         file = fopen("montre.txt", "r");
        break;
    case OSCILLATEUR:
         file = fopen("oscillateur.txt", "r");
        break;
    case PENTADECATHLON:
         file = fopen("pentadecathlon.txt", "r");
        break;
    case GALAXIE:
         file = fopen("galaxie.txt", "r");
        break;
    }

    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    int x;
    int i = 0, j = 0;
    do{
        x = fgetc(file);
        grille[i][j] = x;
        j++;
        if(j==N){
            j = 0;
            i++;
            if(i==M){
                break;
            }
        }
        if(feof(file)){
            break;
        }
    } while(1);

    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            if(grille[l][m] > 2){
                grille[l][m] = grille[l][m] - 48; //les élèments sont écrits sous forme ascii suite au fgetc, on les repasse en binaire
            }
        }
    }
    fclose(file);
}

void delay(int nbr_s){ //delai
    int milli_secondes = 1000 * nbr_s;
  
    clock_t debut = clock();
  
    // looping till required time is not achieved
    while (clock() < debut + milli_secondes);
}

int str_to_param(char *string, int param[2]){ //convertit un string en entier selon une délimitation et en gérant les exceptions à la consigne
    char *nbr, *type, *test;
    const char s[2] = "-"; //delimitation

    char str[80];
    strcpy(str, string);
    if(str[0] == ' ' || str[0] == '\0'){ //si string dans string entry vide : pas de modifications aux valeurs par défaut
        return EXIT_SUCCESS;
    }

    /* get the first token */
    nbr = strtok(str, s); 
    type = strtok(NULL, s);//second token
    test = strtok(NULL, s); //possible token suivant
    if(test != NULL){ //si il y a token suivant
        printf("Données entrées incorrectes\n");
        return EXIT_FAILURE;
    }

    if(nbr[0] == ' '){ //si premier token vide
        param[0] = 80; //par défaut
    }
    else{
        param[0] = strtol(nbr, NULL, 10);
    }
    if(type[0] == ' '){ //si deuxième token vide
        param[1] = 0; //par défaut
    }
    else{
        param[1] = strtol(type, NULL, 10);
    }
    return EXIT_SUCCESS;
}