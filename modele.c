/*
 * Les fonctions du modèle qui assure l'évolution de la population
 *
 * Note : module indépendant de toute interfaces utilisateurs
 */

#include <stdlib.h>
#include <stdio.h> 
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

int nbVoisins(int grille[M][N], int i, int j){ //compte le nbr de voisins vivants
    int voisins = 0;
    int debutL = i-1;
    int debutC = j-1;
    int finL = i+1;
    int finC = j+1;

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
            if(grille[l][m] == 1 || grille[l][m] == 49){
                voisins+=1;
            }
        }
    }
    if(grille[i][j] == 1){ //si la cellule est vivante elle a été comptée dans le nbr de voisins vivants
        voisins-=1; //on retire donc 1
    }
    return voisins;
}

void evolution(int grille[M][N]){ //détermination de la génération suivante
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

void dayandnight(int grille[M][N]){ //détermination de la génération suivante
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

void afficherGrille(int *pointeur){ //affiche la grille en passant par le pointeur qui pointe sur le premier élément de la grille
    for(int i = 0; i<M ; i++){
        for (int j = 0; j<N; j++){
            if(*pointeur == 1){
                printf("\033[0;35m"); //print en violet si c'est un 1
            }
            printf("%2d", *pointeur); //on affiche la valeur pointée par le pointeur
            printf("\033[0m"); //print couleur par défaut
            printf(" |"); //séparateur de cellules
            pointeur+=1; //on incrémente le pointeur, on passe donc à l'élément suivant de la grille
        }
        printf("\n"); 
    }
    
}

void conversion(int grille[M][N], int nom){
    FILE *file, *f;
    switch (nom){
    case STABLE:
        f = "stable.txt";
        break;
    case VAISSEAU:
        f = "vaisseau_simple.txt";
        break;
    case MONTRE:
        f = "montre.txt";
        break;

    }
    file = fopen(f, "r");
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
    fclose(file);
}

void delay(){
    int i;
    int msec = 0, trigger = 5000; /* 5s */
    clock_t before = clock();

    do {
    clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    i++;}   
    while ( msec < trigger );
}

