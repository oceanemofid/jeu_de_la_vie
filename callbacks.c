/*
 * les callbacks de l’application
 */


#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"
#include "callbacks.h"

/*
 * Rôle : termine l’exécution de l’application
 */
void quit(Widget w, void *d) {
    exit(EXIT_SUCCESS);
}
