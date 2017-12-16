#ifndef LANGAGE_H
#define LANGAGE_H

#include "graphe.h"
#include "automate.h"
#include "langage.h"

int accepte(struct automate *, const char []);
void affiche_langage_taille_croissante(struct automate *, int);
void affiche_langage_alphabetique(struct automate *, int);

#endif