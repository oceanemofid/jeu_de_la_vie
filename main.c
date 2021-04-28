#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include <time.h>

#define M 5
#define N 5

//-------------------------------------------------------//
/*
    0|0|0|0|0
    0|1|0|0|0
    0|1|1|1|0
    0|0|0|1|0
    0|0|0|0|0

*/
//-------------------------------------------------------//

int *initGrille(int largeur, int longueur){
    int grille[longueur][largeur];
    int *p = &grille[0][0];
    for(int i = 0; i<longueur; i++){
        for(int j = 0; j<largeur; j++){
            grille[i][j] = rand() &1; 
        }
    }
    return p;
}

int nbVoisins(int grille[M][N], int i, int j){
    int voisins = 0;

    if(i == 0 && j!= 0){
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
    else if(j == 0 && i != 0){
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
    else if(i == 0 && j == 0){
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
    else {
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

int *evolution(int grille[M][N]){
    int i, j;
    int voisins;
    int res[M][N];
    int *p = &res[0][0];

    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            res[l][m] = grille[l][m];
        }
    }
   
    for(i = 0; i<M; i++){
        for (j = 0; j<N; j++){
            voisins = nbVoisins(grille, i, j);
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
    return p;
}


/*void afficherGrille(int *pointeur){
    for(int i = 0; i<M ; i++){
        for (int j = 0; j<N; j++){
            printf("%2d | ", *pointeur);
            pointeur+=1;
        }
        printf("\n");
    }
}*/

/*
    0|0|0|0|0       0|0|0|0|0
    0|1|0|0|0       0|1|0|0|0
    0|1|1|1|0  ==>  1|1|0|1|0
    0|1|0|1|0       0|1|0|1|0
    0|0|0|0|0       0|0|0|0|0

*/

int main(){
    
    int test[M][N]={{1,1,0,0,0},
                    {0,1,0,0,0},
                    {0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,0,0,0,0}};
    
    //afficherGrille(evolution(test));
    int *p;
    p = evolution(test);
    for(int i = 0; i<M ; i++){
        for (int j = 0; j<N; j++){
            printf("%d | ", *(p++));
        }
        printf("\n");
    }
    //while
    return EXIT_SUCCESS;
}