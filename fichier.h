#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "graphe.h"

struct automate * lire_automate(FILE * );
struct automate * ecrire_automate(FILE *, struct automate *);
void sauvegarde_automate(struct automate *, char *);
void lecture(char *, int);

#endif
