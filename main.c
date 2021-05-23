#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"
//taille de la grille


//-------------------------------------------------------//



//-------------------------------------------------------//

int main(int argc, char *argv[]){
    int test[M][N];
    int *p = &test[0][0]; //pointeur sur premier élément
    int cpt = 10; //nbr de générations à afficher
    initGrille(test); //on génère mles individus
    
    if (OpenDisplay(argc, argv) == 0) {
        fprintf(stderr,"Can’t open display\n");
    return EXIT_FAILURE;
    }

    init_display(argc, argv, p);
    MainLoop();
    return EXIT_SUCCESS;

}
/*
int main(int argc, char *argv[]) {
    ValeurCourante d;
    
// intialliser la donnée partagée entre le modèle
// et l’IG
    initValeurCourante(&d);
// créer l’IG et l’afficher à l’écran
    init_display(argc, argv, &d);
    MainLoop();
    return EXIT_SUCCESS;
}*/