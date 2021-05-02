#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include <time.h>
//taille de la grille
#define M 5
#define N 5

//-------------------------------------------------------//

void initGrille(int grille[M][N]){ //crée une grille avec des individus placés aléatoirement
    time_t t;
    srand((unsigned) time(&t)); //initialise le générateur
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            grille[i][j] = rand() %2; // return un chiffre aléatoire de 0 à 1
        }
    }
}

int nbVoisins(int grille[M][N], int i, int j){ //compte le nombre de voisins vivants de la case
    int voisins = 0;

    if((i == 0 || i == M-1) && (j == 0 || j == N-1)){ //4 coins de la grille -> seulement 3 voisins
        if(i == 0 && j == 0){ //coin supérieur gauche
            if(grille[i][j+1] == 1){
                voisins+=1;
            }
            if(grille[i+1][j] == 1){
                voisins+=1;
            }
            if(grille[i+1][j+1] == 1){
                voisins+=1;
            }
        }
        else if(i == 0 && j == N-1){ //coin supérieur droit
            if(grille[i][j-1] == 1){
                voisins+=1;
            }
            if(grille[i+1][j] == 1){
                voisins+=1;
            }
            if(grille[i+1][j-1] == 1){
                voisins+=1;
            }
        }
        else if(i == M-1 && j == 0){ //coin inférieur gauche
            if(grille[i][j+1] == 1){
                voisins+=1;
            }
            if(grille[i-1][j] == 1){
                voisins+=1;
            }
            if(grille[i-1][j+1] == 1){
                voisins+=1;
            }
        }
        else{ //coin inférieur droit
            if(grille[i][j-1] == 1){
                voisins+=1;
            }
            if(grille[i-1][j] == 1){
                voisins+=1;
            }
            if(grille[i-1][j-1] == 1){
                voisins+=1;
            }
        }
    }
    else if((i == 0 || i == M-1) && (j!= 0 || j != N-1)){ //cas à 5 voisins
        if(i == 0){ //ligne supérieure du tableau sans les 2 coins
            if(grille[i][j-1] == 1){
                voisins+=1;
            }
            if(grille[i][j+1] == 1){
                voisins+=1;
            }
            if(grille[i+1][j-1] == 1){
                voisins+=1;
            }
            if(grille[i+1][j] == 1){
                voisins+=1;
            }
            if(grille[i+1][j+1] == 1){
                voisins+=1;
            }
        }

        else{ //ligne inférieure de la grille sans les 2 coins
            if(grille[i][j-1] == 1){
                voisins+=1;
            }
            if(grille[i][j+1] == 1){
                voisins+=1;
            }
            if(grille[i-1][j-1] == 1){
                voisins+=1;
            }
            if(grille[i-1][j] == 1){
                voisins+=1;
            }
            if(grille[i-1][j+1] == 1){
                voisins+=1;
            }
        }
    }
    else if((i != 0 || i != M-1) && (j == 0 || j == N-1)){ //autre cas à 5 voisins
        if(j == 0){ //ligne à gauche sans les 2 coins 
            if(grille[i-1][j] == 1){
                voisins+=1;
            }
            if(grille[i-1][j+1] == 1){
                voisins+=1;
            }
            if(grille[i][j+1] == 1){
                voisins+=1;
            }
            if(grille[i+1][j] == 1){
                voisins+=1;
            }
            if(grille[i+1][j+1] == 1){
                voisins+=1;
            }
        }
        else{ //ligne à droite sans les 2 coins
            if(grille[i-1][j] == 1){
                voisins+=1;
            }
            if(grille[i-1][j-1] == 1){
                voisins+=1;
            }
            if(grille[i][j-1] == 1){
                voisins+=1;
            }
            if(grille[i+1][j] == 1){
                voisins+=1;
            }
            if(grille[i+1][j-1] == 1){
                voisins+=1;
            }
        }

    } 
    else { //cas général avec 8 voisins
        if(grille[i-1][j-1] == 1){
            voisins+=1;
        }
        if(grille[i-1][j] == 1){
            voisins+=1;
        }
        if(grille[i-1][j+1] == 1){
            voisins+=1;
        }
        if(grille[i][j-1] == 1){
            voisins+=1;
        }
        if(grille[i][j+1] == 1){
            voisins+=1;
        }
        if(grille[i+1][j-1] == 1){
            voisins+=1;
        }
        if(grille[i+1][j] == 1){
            voisins+=1;
        }
        if(grille[i+1][j+1] == 1){
            voisins+=1;
        }
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

//-------------------------------------------------------//

int main(){
    int test[M][N]= {{1,1,0,0,1},
                    {0,1,1,1,1},
                    {0,1,0,1,0},
                    {0,1,0,1,1},
                    {0,1,1,0,0}};

    int *p = &test[0][0]; //pointeur sur premier élément
    int cpt = 1; //nbr de générations à afficher
    //initGrille(test); //on génère mles individus
    
    for(int i=0; i<=cpt; i++){
        printf("Génération %d\n", i);
        afficherGrille(p);
        evolution(test);
    }
    return EXIT_SUCCESS;
}