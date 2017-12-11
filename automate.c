#include "automate.h"

// Initialise un automate
// Paramètres : ensemble d'états, alphabet, état initial, tableau d'états finaux
// On suppose au départ que l'automate ne contient aucune transition
// Renvoie l'adresse mémoire de l'automate alloué
struct automate * creer_automate (int nbetats, char * alphabet, int etat_init, int * etats_finaux)
{
	struct automate * pautomate = malloc(sizeof(struct automate));
	pautomate->graphe_trans = creer_graphe(nbetats);
	pautomate->alphabet = alphabet;
	pautomate->etat_init = etat_init;
	pautomate->etats_finaux = etats_finaux;
	return pautomate;
}

// Libère l'espace mémoire occupé par l'automate 
void liberer_automate (struct automate * pautomate)
{
	liberer_graphe(pautomate->graphe_trans);
	free(pautomate);
	printf("Liberation de l'espace memoire de automate effectue\n");
}

// Paramètres : deux états e1 et e2 et une étiquette v
// Ajoute la transition (e1,v) = e2 
// Vérifie que e1 et e2 existent, que v appartient à l'alphabet, 
// qu'il n'y a pas déjà de transition de e1 vers e2
void ajouter_transition (struct automate * pautomate, int e1, int e2, char v)
{
	ajouter_arc(pautomate->graphe_trans, e1, e2, v);
}