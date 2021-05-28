/*
 * cette vue fabrique l’interface graphique à l’aide
 * de la bibliothèque libsx
 */

#include <stdio.h> 
#include <stdlib.h>
#include <libsx.h>
#include "modele.h"
#include "callbacks.h"



/* Rôle: création et assemblage des widgets */

void init_display(){
    Widget BQuit, Menu, Bbasique,BAlea, Bdayandnight, BStable, BVaisseau, BRun;
    Widget Box;
// créer les composants graphiques
    Bbasique = MakeButton("Version de base", basique, NULL);//ouvre fenêtre 
    Bdayandnight = MakeButton("Variante Day and Night", variante, NULL); //ouvre fenêtre

    Box = MakeDrawArea(LARGEUR,HAUTEUR,waitingscreen,NULL);

    BQuit = MakeButton(" Quit ", quit, NULL);
    BRun = MakeButton("Run", quit, NULL); 
    
    

// assembler les composants graphiques
    SetWidgetPos(Bbasique, NO_CARE, NULL, NO_CARE, NULL); 
    SetWidgetPos(Bdayandnight, PLACE_RIGHT, Bbasique, NO_CARE, NULL);

    SetWidgetPos(Box, PLACE_UNDER, Bbasique, NO_CARE, NULL);

    SetWidgetPos(BRun, PLACE_UNDER, Box, NO_CARE, NULL);
    SetWidgetPos(BQuit, PLACE_UNDER, BRun, NO_CARE, NULL); 
    //ClearDrawArea();
// pour gérer les couleurs
    GetStandardColors();

// pour afficher l’interface
    ShowDisplay();
}