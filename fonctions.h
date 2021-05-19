#ifndef __LSC__
#define __LSC__

typedef struct Element {
    char data;
    struct Element* suivant;
} Element;

typedef struct Pile {
    Element* premier;
} Pile;

typedef struct Noeud
{
   	char data;
   	struct Noeud* gauche;
	struct Noeud* droit;
} Noeud;


void empiler(Pile *pile, char data);

char depiler(Pile *pile);

int priorite(char char1, char char2);

int brancheLibre(Noeud *tree);


void ajouterNoeud(Noeud **arbre, char value);

Noeud *genererArbre(Pile *pile);

void afficherArbre(Noeud *arbre);

int parcoursArbre(Noeud *arbre);
#endif