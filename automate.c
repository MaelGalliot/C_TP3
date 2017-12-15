#include "automate.h"

// Initialise un automate
// Paramètres : ensemble d'états, alphabet, état initial, tableau d'états finaux
// On suppose au départ que l'automate ne contient aucune transition
// Renvoie l'adresse mémoire de l'automate alloué
struct automate * creer_automate(int nbetats, const char * alphabet, int etat_init, const int * etats_finaux_parametres, int nbetatsfinaux)
{
	struct automate * pautomate = malloc(sizeof(struct automate));
	pautomate->graphe_trans = creer_graphe(nbetats);

	pautomate->alphabet = malloc(sizeof(alphabet));
	// Ou malloc(strlen(alphabet)*sizeof(char));
	strcpy(pautomate->alphabet, alphabet);

	pautomate->etat_init = etat_init;

	pautomate->etats_finaux = calloc(nbetats+1, sizeof(int));
	pautomate->etats_finaux = pautomate->etats_finaux + 1;

	// Si état final 1
	// Si état pas final 0
	int i;

	for (i = 0; i < nbetatsfinaux; ++i)
	{
		pautomate->etats_finaux[etats_finaux_parametres[i]] = 1;
	}
	
	return pautomate;
}

// Libère l'espace mémoire occupé par l'automate 
void liberer_automate(struct automate * pautomate)
{
	liberer_graphe(pautomate->graphe_trans);
	free(pautomate->alphabet);
	free(pautomate->etats_finaux-1);
	free(pautomate);
	printf("Liberation de l'espace memoire de automate effectue\n");
}

// Renvoie 0 si l'étiquette n'appartient pas à l'alphabet
// Renvoie 1 si l'étiquette appartient à l'aplphabet
int etiquette_existe(struct automate * pautomate, char v)
{
	int x = 0;
	int i = 0;
	// On regarde si l'étiquette appartient à l'alphabet
	while((pautomate->alphabet[i] != '\0') && (x == 0))
	{
		if (v == pautomate->alphabet[i])
		{
			x = 1;
		}
		i++;
	}
	return x;
}

// Paramètres : deux états e1 et e2 et une étiquette v
// Ajoute la transition (e1,v) = e2 
// Vérifie que e1 et e2 existent, que v appartient à l'alphabet, 
// qu'il n'y a pas déjà de transition de e1 vers e2
void ajouter_transition(struct automate * pautomate, int e1, int e2, char v)
{
	if ((e1 < pautomate->graphe_trans->nbsommets) && (e2 < pautomate->graphe_trans->nbsommets) && (etiquette_existe(pautomate, v)==1))
	{
		ajouter_arc(pautomate->graphe_trans, e1, e2, v);
	}
}
