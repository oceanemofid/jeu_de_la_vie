#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "fct.h"
#include "Variables.h"
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
            if(grille[l][m] == 1 || grille[l][m] == 49){
                voisins+=1;
            }
        }
    }
    if(grille[i][j] == 1 || grille[i][j] == 49){ //si la cellule est vivante elle a été comptée dans le nbr de voisins vivants
        voisins-=1; //on retire donc 1
    }
    return voisins;
}

//bleu=1;vert=2;rouge=3;jaune=4;
//bleu=vivantes et va rester en vie
//vert=va naitre
//rouge=va mourrir mais a deja vecu au moins 1 cycle
//jaune=va mourrir mais est resté en vie qu'un seul cycle

//règles de bases
void InitCouleurs(int grille[M][N]){
  for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
      int voisins=nbVoisins(grille,i,j);
      if (grille[i][j]==1){
        if (voisins>3 || voisins<2){
          grille[i][j]=4;
        }
      }
      else{
        if(voisins==3){
          grille[i][j]=2;
        }
      }
    }
  }
}

void Couleurs(int grille[M][N],int res[M][N]){
  for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
      int voisins=nbVoisins(res,i,j);
      if (res[i][j]==1){
        if (voisins>3||voisins<2){
          if (grille[i][j]==2){
            res[i][j]=4;
          }
          else{
            res[i][j]=3;
          }
        }
      }
      else{
        if(voisins==3){
          res[i][j]=2;
        }
      }
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
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        grille[i][j]=res[i][j];
      }
    }
  }

void afficher(int grille[M][N]){
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        printf("%d",grille[i][j]);
      }
      printf("\n");
    }
  }

//dayandnight

void InitCouleurs2(int grille[M][N]){
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

void Couleurs2(int grille[M][N],int res[M][N]){
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

