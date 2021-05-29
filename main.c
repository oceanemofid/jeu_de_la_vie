#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"
//export DISPLAY=:0

int main(int argc, char *argv[]){
    
    if (OpenDisplay(argc, argv) == 0) {
        fprintf(stderr,"Can’t open display\n");
    return EXIT_FAILURE;
    }

    init_display();
    MainLoop();
    return EXIT_SUCCESS;

}

