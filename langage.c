#include "graphe.h"
#include "automate.h"
#include "langage.h"

void trier_liste(struct larc **);
void trier_listes(struct graphe *);

// Paramètres : 1 automate et 1 mot
// Renvoie 1 si le mot est reconnu par l'automate
// Renvoie 0 si le mot n'est pas reconnu par l'automate
int accepte(struct automate * pautomate, const char * mot)
{
	// On va utiliser la fonction transiter(struct graphe * pgraphe, int etat, int symbole)
	// Qui renvoie l'état d'arrivée, ou -1 si la transition n'existe pas

	int e = pautomate->etat_init; // Mémoire de l'état
	// int i = 0; // Compteur

	// On regarde si l'étiquette appartient à l'alphabet
	// for (i = 0; (mot[i] != '\0') && (e != -1); ++i)
	for (; *mot != '\0' && e != -1; ++mot)
	{
		e = transiter(pautomate->graphe_trans, e, *mot);
	}

	// La case -1 correspond à 0
	return pautomate->etats_finaux[e];
}
