#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void empiler(Pile *pile, char data)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->data = data;
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

    return elementDepile->data;
}

Noeud *creerNoeud(char value)
{
	Noeud *noeud = (Noeud *)malloc(sizeof(Noeud));
	noeud->data = value;
	noeud->gauche = NULL;
	noeud->droit = NULL;
	return noeud;
}

int priorite(char char1, char char2)
{
    if ((char2 == '*' && char1 == '+') ||
     (char2 == '*' && char1 == '-') ||
      (isdigit(char2) || char1 == '\0'))
        return -1;
    return 1;
}

int brancheLibre(Noeud *tree)
{
	if (tree == NULL)
		return 1;
	else if (isdigit(tree->data))
		return 0;
	else
		return brancheLibre(tree->gauche) || brancheLibre(tree->droit);
}

void ajouterNoeud(Noeud **arbre, char value)
{
	Noeud *tmp_cursor;
	Noeud *pere;
	Noeud *new_element;

	new_element = creerNoeud(value);
	if (*arbre != NULL)
	{
		tmp_cursor = *arbre;
		do
		{
			pere = tmp_cursor;
			if (priorite(tmp_cursor->data, value) == -1 && brancheLibre(tmp_cursor->droit))
			{
				tmp_cursor = tmp_cursor->droit;
				if (tmp_cursor == NULL)
				{
					pere->droit = new_element;
					break;
				}
			}
			else
			{
				tmp_cursor = tmp_cursor->gauche;
				if (tmp_cursor == NULL)
				{
					pere->gauche = new_element;
					break;
				}
			}
		} while (tmp_cursor != NULL);
	}
	else
	{
		*arbre = new_element;
	}
}

Noeud *genererArbre(Pile *pile)
{
	Noeud *arbre = NULL;
	Element *tmp;

	tmp = pile->premier;
	while (tmp)
	{
		ajouterNoeud(&arbre, tmp->data);
		tmp = tmp->suivant;
	}
	return arbre;
}

void afficherArbre(Noeud *arbre)
{
	if (arbre != NULL)
	{
		afficherArbre(arbre->gauche);
		printf("%c", arbre->data);
		afficherArbre(arbre->droit);
	}
}

int parcoursArbre(Noeud *arbre)
{
	if (arbre != NULL)
	{
		if (arbre->data == '+')
			return parcoursArbre(arbre->gauche) + parcoursArbre(arbre->droit);
		else if (arbre->data == '-')
			return parcoursArbre(arbre->gauche) - parcoursArbre(arbre->droit);
		else if (arbre->data == '*')
			return parcoursArbre(arbre->gauche) * parcoursArbre(arbre->droit);
		else if (isdigit(arbre->data))
			return arbre->data - '0';
	}
	return 0;
}