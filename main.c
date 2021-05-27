#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"


int main(){
    int test[M][N];
    int *p = &test[0][0]; //pointeur sur premier élément
    int cpt = 10; //nbr de générations à afficher
    initGrille(test); //on génère mles individus

    init_display();
    MainLoop();
    return EXIT_SUCCESS;

}

