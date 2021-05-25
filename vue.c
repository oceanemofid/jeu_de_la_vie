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
    ClearDrawArea();
    BQuit = MakeButton(" Quit ", quit, NULL);
    BOne = MakeButton(" Next ", quit, NULL);
    //Menu
    //char *name = "Choix"
    //menu = MakeMenu(name);
    //MakeMenuItem(Widget menu, char *name, ButtonCB func, void *arg)
    // règles de base
    // variante day and night 
    //pour chaque struct;
    //bouton/coche grille aléatoire 
    //SetMenuItemChecked(Widget w, int state); -> func
    //BOUTON run
    //-run -> lance nv fenetre 

    //seconde = MakeWindow(char *window_name, char *display_name, int exclusive);EXCLUSIVE_WINDOW
    //Box = MakeDrawArea(500,500,evolution,NULL);

    //bouton retour
    //CloseWindow() 
    
    DrawBox(0,0,LARGEUR,HAUTEUR);

// assembler les composants graphiques
    SetWidgetPos(BQuit, PLACE_UNDER, Box, NO_CARE, NULL);
    SetWidgetPos(BOne, PLACE_UNDER, BQuit, NO_CARE, NULL);

// pour gérer les couleurs
    GetStandardColors();

// pour afficher l’interface
    ShowDisplay();
}