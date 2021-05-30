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
    Widget BQuit, StrSize;
    Widget Box, Texte, Texte_2, Texte_3;
    Widget BStructure[6];
    char *txt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nMauris mollis elit a dui tincidunt pellentesque.\nInteger tellus felis, cursus egestas pellentesque ac, interdum at metus.\nMorbi mollis vel quam vel vulputate.\nMauris ultrices et nunc at lobortis. Etiam faucibus nisl urna, vitae gravida nunc volutpat id.\nInteger placerat leo in sem tincidunt, ut aliquam mauris vulputate.\nProin porttitor scelerisque enim, quis auctor massa congue eu. ";
    char *txt_2 = "   ou   ";
    char *txt_3 = "Observez maintenant la population evoluee : ";
    // créer les composants graphiques
    Texte = MakeLabel(txt);
    Texte_2 = MakeLabel(txt_2);
    Texte_3 = MakeLabel(txt_3);

    //BAlea = MakeButton("Population aleatoire", aleatoire, NULL);
    StrSize = MakeStringEntry(NULL, 200, aleatoire, NULL);
    BStructure[0] = MakeButton("Structure stable", stable, NULL);
    BStructure[1] = MakeButton("Vaisseau simple", vaisseau, NULL);
    BStructure[2] = MakeButton("Montre", montre, NULL);
    BStructure[3] = MakeButton("Oscillateur", oscillateur, NULL);
    BStructure[4] = MakeButton("Penthadecathlon", pentadecathlon, NULL);
    BStructure[5] = MakeButton("Galaxie de Kok", galaxie, NULL);

    Box = MakeDrawArea(M*15+(M-1)*5,M*15+(M-1)*5,waitingscreen,NULL);
    
    BQuit = MakeButton(" Quit ", quit, NULL);

// assembler les composants graphiques
    SetWidgetPos(Texte, NO_CARE, NULL, NO_CARE, NULL); 
    SetWidgetPos(StrSize, PLACE_UNDER, Texte, NO_CARE, NULL); 
    SetWidgetPos(Texte_2, PLACE_UNDER, StrSize, NO_CARE, NULL);
    SetWidgetPos(BStructure[0], PLACE_UNDER, Texte_2, PLACE_UNDER, Texte_2);
    SetWidgetPos(BStructure[1], PLACE_UNDER, Texte_2, PLACE_RIGHT, BStructure[0]);
    SetWidgetPos(BStructure[2], PLACE_UNDER, Texte_2, PLACE_RIGHT, BStructure[1]);
    SetWidgetPos(BStructure[3], PLACE_UNDER, Texte_2, PLACE_RIGHT, BStructure[2]);
    SetWidgetPos(BStructure[4], PLACE_UNDER, Texte_2, PLACE_RIGHT, BStructure[3]);
    SetWidgetPos(BStructure[5], PLACE_UNDER, Texte_2, PLACE_RIGHT, BStructure[4]);
    SetWidgetPos(Texte_3, PLACE_UNDER, BStructure[5], NO_CARE, NULL);

    SetWidgetPos(Box, PLACE_UNDER, Texte_3, NO_CARE, NULL);

    SetWidgetPos(BQuit, PLACE_UNDER, Box, NO_CARE, NULL); 
// pour gérer les couleurs
    GetStandardColors();

// pour afficher l’interface
    ShowDisplay();
}
