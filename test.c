#include <stdlib.h>
#include <stdio.h> 

#define M 16
#define N 16

enum {STABLE, VAISSEAU, MONTRE};

void afficher(int grille[M][N], void *data){
    int voisins, x, y, width, height;
    int u=0;
    width = 36;
    height = 36;
    //ClearDrawArea();
    for(int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            //voisins = nbVoisins(grille,i,j);
            x = i * width;
            y = j * height;
            if(grille[i][j]== 0 || grille[i][j]== 48){
                //SetColor(BLUE);
                //DrawFilledBox(x,y,width,height);
                printf("%c", grille[i][j]);
            }
            else if(grille[i][j]== 1|| grille[i][j]== 49){
                //SetColor(YELLOW);
                //DrawFilledBox(x,y,width,height);
                printf("%c", grille[i][j]);
            }
            else{
                //SetColor(RED);
                //DrawFilledBox(x,y,width,height);
                //printf("%c", grille[i][j]);
            }
        }
        printf("\n");
    }
    /*SetLineWidth(2);
    for(int i = 0; i<M; i++){
        u += width;
        SetColor(WHITE);
        DrawLine(u,0,u,LARGEUR);
        DrawLine(0,u,HAUTEUR,u);
    }*/
    //AddTimeOut(2000, afficher,data);
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

void vaisseau(){
    void *d;
    int grille[M][N];
    int *p = &grille[0][0];
    conversion(grille,VAISSEAU);
    //int x = GetYesNo("Voulez vous tester la variante Day and Night ? ");
    /*if(x){
        dayandnight(grille);
    }
    else{
        evolution(grille);
    }*/
    afficher(grille,p);
}

int main(){
    vaisseau();
    return EXIT_SUCCESS;

}