/*
 * cette vue fabrique l’interface graphique à l’aide
 * de la bibliothèque libsx
 */

#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "modele.h"
#include "callbacks.h"


#define LARGEUR 500
#define HAUTEUR 500
/* Rôle: création et assemblage des widgets */

void init_display(){
    Widget BQuit, Box, BOne;
// créer les composants graphiques
    BQuit = MakeButton(" Quit ", quit, NULL);
    BOne = MakeButton(" Next ", quit, NULL);
    Box = MakeDrawArea(500,500,evolution,NULL);
    DrawBox(0,0,LARGEUR,HAUTEUR);
// assembler les composants graphiques
    SetWidgetPos(BQuit, PLACE_UNDER, Box, NO_CARE, NULL);
    SetWidgetPos(BOne, PLACE_UNDER, BQuit, NO_CARE, NULL);

// pour gérer les couleurs
    GetStandardColors();

// pour afficher l’interface
    ShowDisplay();
}