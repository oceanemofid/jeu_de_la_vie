#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"
//export DISPLAY=:0

int main(int argc, char *argv[]){
    int test[M][N];
    int *p = &test[0][0]; //pointeur sur premier élément
    int cpt = 10; //nbr de générations à afficher
    initGrille(test); //on génère mles individus
    
    if (OpenDisplay(argc, argv) == 0) {
        fprintf(stderr,"Can’t open display\n");
    return EXIT_FAILURE;
    }

    init_display();
    MainLoop();
    return EXIT_SUCCESS;

}

