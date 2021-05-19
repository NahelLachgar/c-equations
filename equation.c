#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

char operators[] = {'*', '+', '-'};
char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int isNumber(char character)
{
    for (int i = 0; i < 10; i++)
    {
        if (character == numbers[i])
            return 1;
    }
    return 0;
}

int priorite(char char1, char char2)
{
    if (char2 == '*' && char1 != '*')
        return -1;
    if (char1 == '\0')
        return -1;
    if (isNumber(char2) == 1)
        return -1;

    return 1;
}

Pile creationArbre(Pile *pile, char *equationString)
{
    Pile *sortie = NULL;

    sortie->premier->character = '\0';

    empiler(pile, '\0');

    for (int i = 0; i < strlen(equationString) - 2; i++)
    {
        Element sommet = afficherSommetPile(pile);
        if (equationString[i] == '\0' && sommet.character == '\0')
            return *sortie;
        if (priorite(sommet.character, equationString[i]) == -1)
        {
            empiler(pile, equationString[i]);
        }
        else
        {
            char depile = depiler(pile);
            do
            {
                depile = depiler(pile);
                empiler(sortie, depile);
            } while (priorite(afficherSommetPile(pile).character, depile) == -1);
        }
    }

    return *sortie;
}

int operation(int nb1, int nb2, char operator)
{
    switch (operator)
    {
    case '*':
        return nb1 * nb2;
        break;
    case '+':
        return nb1 + nb2;
        break;
    case '-':
        return nb1 - nb2;
        break;
    default:
        exit(EXIT_FAILURE);
    }
}

int isOperator(char character)
{
    for (int i = 0; i < 3; i++)
    {
        if (character == operators[i])
            return 1;
    }
    return 0;
}

int main()
{
    char equationString[100] = "5*3+2-1";
    Pile *pile = NULL;

    pile->premier->character = '\0';

    /* printf("Entrez une équation : \n");
    scanf("%s", equationString); */

    creationArbre(pile, equationString);

    return 0;
}

main();