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
		e = transiter(pautomate->graphe_trans, e, mot[i]);
	}

	// La case -1 correspond à 0
	return pautomate->etats_finaux[e];
}

// Affiche les mots reconnus par l'automate 
// Par ordre de longueur jusque maxlongueur (passé en paramètre)
void affiche_langage_taille_croissante(struct automate * pautomate, int maxlongueur)
{
	
}

// Trie alphabétiquement la liste d'adjacence en fonction des étiquettes
void trier_liste(struct larc ** lsite_adjs)
{

}

// Trie alphabétiquement toutes les listes d'adjacence d'un graphe
void trier_listes(struct graphe * pgraphe)
{

}

// Affiche les mots reconnus par l'automate
// Par ordre alphabétique jusque maxlongueur
void affiche_langage_alphabetique(struct automate * pautomate, int maxlongueur)
{

}