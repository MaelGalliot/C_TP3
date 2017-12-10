#include <stdio.h>
#include <stdlib.h>
#include "automate.h"

// Initialise un automate
// Paramètres : ensemble d'états, alphabet, état initial, tableau d'états finaux
// On suppose au départ que l'automate ne contient aucune transition
// Renvoie l'adresse mémoire de l'automate alloué
struct automate * creer_automate (int * petats, char * palphabet, int etat_init, int * petats_finaux)
{
	struct automate *pautomate;
	pautomate = malloc(sizeof(struct automate));
	pautomate->alphabet=palphabet
	pautomate->etats_finaux = petats_finaux;

	return strucut automate * pautomate;
}

// Libère l'espace mémoire occupé par l'automate 
void liberer_automate (struct automate * pautomate)
{

}

// Paramètres : deux états e1 et e2 et une étiquette v
// Ajoute la transition (e1,v) = e2 
// Vérifie que e1 et e2 existent, que v appartient à l'alphabet, qu'il n'y a pas déjà de transition de e1 vers e2
void ajouter_transition (int e1, int e2, char v)
{
	
}