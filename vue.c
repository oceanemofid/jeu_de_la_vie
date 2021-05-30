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
    Widget Box, LTitre, LConsigne, Texte_2, Texte_3, LAlea, LCouleurs;
    Widget BStructure[6];
    char *titre = "                         Jeu de la vie                         ";
    char *consigne = "L'objectif de ce projet est de programmer le jeu de la vie de J. Conway. \nCe jeu simule l'evolution d'organismes en societe. \nAu depart, une population d'individus est repartie sur une grille (theoriquement infinie). \nLa population se transforme, etape par etape, selon des regles d'evolution. \nA chaque etape, les individus apparaissent et/ou disparaissent sur la grille, \nformant une nouvelle generation d'individus, selon les regles suivantes : \n\n -tout individu voisin de deux ou \nrois individus survivra \n\n -toute case vide voisine de trois individus exactement \ndonnera naissance a un individu \n\n -mort par etouffement : tout individu voisin de quatre \nautres individus ou plus disparaitra \n\n -mort par isolement : tout individu isole \nou voisin d'un seul individu disparaitra";
    char *alea = "Vous avez egalement le choix de la population, vous pouvez cliquer sur l'un des boutons ci-dessous \net cela generera une population selon une structure classique du jeu \nou vous pouvez generer une population aleatoire. \nPour ce faire, vous devez utiliser la zone de saisie ci-dessous. \nPour une population aleatoire, nous vous laissons choisir le nombre de generations que vous voulez voir apparaitre \nainsi que le mode d'affichage : avec ou sans etats intermediaires. \n\nVeuillez rentrer d'abord le nombre de generations que vous voulez \npuis ensuite, separe d'un tiret '-', soit un 0 (sans etats intermediaires) soit un 1 (avec etats intermediaires). \nSi vous ne rentrez rien, par defaut, 80 generations seront generes sans etats intermediaires.";
    char *couleurs = "Les couleurs correspondent aux etats suivants : \njaune, l'individu est vivante et va rester en vie; \nvert, l'individu va naitre; \nrouge, l'individu va mourrir mais a deja vecu au moins un cycle; \nbleu, l'individu va mourrir mais est reste en vie qu'un seul cycle.";
    char *txt_2 = "   ou   ";
    char *txt_3 = "Observez maintenant la population evoluee : ";
    // créer les composants graphiques
    LTitre = MakeLabel(titre);
    LConsigne = MakeLabel(consigne);
    LAlea = MakeLabel(alea);
    LCouleurs = MakeLabel(couleurs);
    Texte_2 = MakeLabel(txt_2);
    Texte_3 = MakeLabel(txt_3);

    StrSize = MakeStringEntry(NULL, 200, aleatoire, NULL);
    BStructure[0] = MakeButton(" Structure stable ", stable, NULL);
    BStructure[1] = MakeButton(" Vaisseau simple ", vaisseau, NULL);
    BStructure[2] = MakeButton(" Montre ", montre, NULL);
    BStructure[3] = MakeButton(" Oscillateur ", oscillateur, NULL);
    BStructure[4] = MakeButton(" Penthadecathlon ", pentadecathlon, NULL);
    BStructure[5] = MakeButton(" Galaxie de Kok ", galaxie, NULL);

    Box = MakeDrawArea(315,315,waitingscreen,NULL);
    
    BQuit = MakeButton("         Quit         ", quit, NULL);

    // assembler les composants graphiques
    SetWidgetPos(LTitre, NO_CARE, NULL, NO_CARE, NULL); 
    SetWidgetPos(LConsigne, PLACE_UNDER, LTitre, NO_CARE, NULL);
    SetWidgetPos(LAlea, PLACE_UNDER, LConsigne, NO_CARE, NULL);
    SetWidgetPos(LCouleurs, PLACE_UNDER, LAlea, NO_CARE, NULL);
    SetWidgetPos(StrSize, PLACE_UNDER, LCouleurs, NO_CARE, NULL); 
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
