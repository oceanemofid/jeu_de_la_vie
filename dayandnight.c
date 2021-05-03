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