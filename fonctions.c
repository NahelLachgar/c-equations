#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>

void empiler(Pile *pile, char character)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->character = character;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

char depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return elementDepile->character;;
}

void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->character);
        actuel = actuel->suivant;
    }

    printf("\n");
}

Element afficherSommetPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        actuel = actuel->suivant;
    }
    return *actuel;
}

int est_vide(Pile *pile)
{
    return pile == NULL || pile->premier == NULL;
}