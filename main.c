#include "graphe.h"
#include "automate.h"
#include "langage.h"

int main(void)
{
	int nbetats = 4;
	char alphabet[] = {'a','b', '\0'};
	int etat_init = 0;
	int etats_finaux_parametres[] = {3};
	int nbetatsfinaux = 1;
	struct automate * pautomate = creer_automate(nbetats, alphabet, etat_init, etats_finaux_parametres, nbetatsfinaux);
	
	ajouter_transition(pautomate, 0, 0, 'b');
	ajouter_transition(pautomate, 0, 1, 'a');
	ajouter_transition(pautomate, 1, 1, 'a');
	ajouter_transition(pautomate, 1, 2, 'b');
	ajouter_transition(pautomate, 2, 1, 'a');
	ajouter_transition(pautomate, 2, 3, 'b');
	ajouter_transition(pautomate, 3, 1, 'a');
	ajouter_transition(pautomate, 3, 0, 'b');

	afficher(pautomate->graphe_trans);

	const char mot[] = "abb";

	// Renvoie 1 si le mot est reconnu par l'automate
	// Renvoie 0 si le mot n'est pas reconnu par l'automate
	int x = accepte(pautomate, mot);
	if(x == 0)
	{
		printf("Le mot %s n'est pas reconnu par l'automate.\n", mot);
	}
	if(x == 1)
	{
		printf("Le mot %s est reconnu par l'automate.\n", mot);
	}

	return 0;
}
