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
    Widget BQuit, BStable, BVaisseau, BMontre, BAlea;
    Widget Box, Texte;
    char *txt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nMauris mollis elit a dui tincidunt pellentesque.\nInteger tellus felis, cursus egestas pellentesque ac, interdum at metus.\nMorbi mollis vel quam vel vulputate.\nMauris ultrices et nunc at lobortis. Etiam faucibus nisl urna, vitae gravida nunc volutpat id.\nInteger placerat leo in sem tincidunt, ut aliquam mauris vulputate.\nProin porttitor scelerisque enim, quis auctor massa congue eu. ";
// créer les composants graphiques
    Texte = MakeLabel(txt);

    BAlea = MakeButton("Population aleatoire", aleatoire, NULL);
    BStable = MakeButton("Structure stable", stable, NULL);
    BVaisseau = MakeButton("Vaisseau simple", vaisseau, NULL);
    BMontre = MakeButton("Montre", montre, NULL);

    Box = MakeDrawArea(LARGEUR,HAUTEUR,waitingscreen,NULL);
    
    BQuit = MakeButton(" Quit ", quit, NULL);

// assembler les composants graphiques
    SetWidgetPos(Texte, NO_CARE, NULL, NO_CARE, NULL); 
    SetWidgetPos(BAlea, PLACE_UNDER, Texte, NO_CARE, NULL); 
    SetWidgetPos(BStable, PLACE_UNDER, BAlea, NO_CARE, NULL);
    SetWidgetPos(BVaisseau, PLACE_UNDER, BStable, NO_CARE, NULL);
    SetWidgetPos(BMontre, PLACE_UNDER, BVaisseau, NO_CARE, NULL);

    SetWidgetPos(Box, PLACE_UNDER, BMontre, NO_CARE, NULL);

    SetWidgetPos(BQuit, PLACE_UNDER, Box, NO_CARE, NULL); 
// pour gérer les couleurs
    GetStandardColors();

// pour afficher l’interface
    ShowDisplay();
}