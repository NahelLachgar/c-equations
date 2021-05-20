#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"

char operators[] = {'*', '+', '-'};
char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

Pile *parcoursString(Pile *pile, char *equationString, int i, Pile *sortie)
{
    char sommet = pile->premier->data;

    if (equationString[i] == '\0' && sommet == '\0')
        return sortie;
    if (priorite(sommet, equationString[i]) == -1)
    {
        empiler(pile, equationString[i]);
        i++;
    }
    else
    {
        empiler(sortie, depiler(pile));
    }

    return parcoursString(pile, equationString, i, sortie);
}

int main()
{
    char equationString[100];

    Pile *pile = (Pile *)malloc(sizeof(Pile));
    Pile *sortie = (Pile *)malloc(sizeof(Pile));

    printf("Entrez une équation : \n");
    scanf("%s", equationString);

    empiler(pile, '\0');

    parcoursString(pile, equationString, 0, sortie);

    Noeud *arbre = genererArbre(sortie);
    afficherArbre(arbre);
    printf("\n");
    printf("Résultat : %d\n", parcoursArbre(arbre));

    return 0;
}

main();