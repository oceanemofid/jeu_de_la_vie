#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>

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

int *evolution(int grille[M][N]){
    int i, j;
    int voisins;
    int res[M][N];
    int (*p)[N];
    p = &res;

    for(int l = 0; l<M; l++){
        for (int m = 0; m<N; m++){
            res[l][m] = grille[l][m];
        }
    }
   
    for(i = 0; i<M; i++){
        for (j = 0; j<N; j++){
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

            /*if(voisins == 2 || voisins == 3){
                //survie
            }*/

            if(voisins == 3){
                //naissance
                res[i][j] = 1;
            }
            else if(voisins >= 4){
                //mort par étouffement
                res[i][j] = 0;
            }
            else if (voisins == 0 || voisins == 1){
                //mort par isolement
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
    int *p = evolution(test);
    for(int i = 0; i<M ; i++){
        for (int j = 0; j<N; j++){
            printf("%2d | ", *(p++));
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}