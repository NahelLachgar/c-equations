#ifndef __LSC__
#define __LSC__

typedef struct Element {
    char character;
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


void empiler(Pile *pile, char character);

char depiler(Pile *pile);

void afficherPile(Pile *pile);

Element afficherSommetPile(Pile *pile);

int est_vide(Pile *pile);

#endif