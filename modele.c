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

void basique(int grille[M][N]){ //détermination de la génération suivante
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

void afficherGrille(int grille[M][N]){ //affiche la grille en passant par le pointeur qui pointe sur le premier élément de la grille
    for(int i = 0; i<M ; i++){
        for (int j = 0; j<N; j++){
            //bleu=1;vert=2;rouge=3;jaune=4;
            if(grille[i][j] == 1){
                printf("\033[0;34m");
            }
            else if(grille[i][j] == 2){
                printf("\033[0;32m");
            }
            else if(grille[i][j] == 3){
                printf("\033[0;31m");
            }
            else if(grille[i][j] == 4){
                printf("\033[0;33m");
            }
            printf("%2d", grille[i][j]); //on affiche la valeur pointée par le pointeur
            printf("\033[0m"); //reset
            printf(" |"); //séparateur de cellules 
        }
        printf("\n"); 
    }
    
}

void conversion(int grille[M][N], int nom){
    FILE *file;
    switch (nom){
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
                grille[l][m] = grille[l][m] - 48;
            }
        }
    }
    fclose(file);
}

void delay(int number_of_seconds){
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

//bleu=1;vert=2;rouge=3;jaune=4;
//bleu=vivantes et va rester en vie
//vert=va naitre
//rouge=va mourrir mais a deja vecu au moins 1 cycle
//jaune=va mourrir mais est resté en vie qu'un seul cycle

//règles de bases
void InitCouleurs(int grille[M][N]){
    int voisins;
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){

            voisins = nbVoisins(grille,i,j);
            printf("nbr de voisins de (%d,%d) : %d\n", i, j, voisins);
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

void afficherT(int grille[M][N]){
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        printf("%2d",grille[i][j]);
      }
      printf("\n");
    }
  }

void Couleurs(int grille[M][N],int res[M][N]){

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

void evolution(int grille[M][N]){ //détermination de la génération suivante
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

int str_to_int(char *string){
    char *first = strdup(string);
    char * ptr;
    int value;
    
    value = strtol(first, &ptr, 10); //value recoit le premier entier de la chaine
    
    printf("value = %d\n", value);
    free(first);
    return value;
}