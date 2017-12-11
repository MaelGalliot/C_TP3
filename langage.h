#ifndef LANGAGE_H
#define LANGAGE_H

#include "langage.h"

int accepte(struct automate *, char *, int);
void affiche_langage_taille_croissante(struct automate *, int);
void trier_liste(struct larc **);
void trier_listes(struct graphe *);
void affiche_langage_alphabetique(struct automate *, int);

#endif