#include "automate.h"

// Paramètres : 1 automate et 1 mot
// Renvoie 1 si le mot est reconnu par l'automate
// Renvoie 0 si le mot n'est pas reconnu par l'automate
int accepte(struct automate * pautomate, char * mot)
{
	// On va utiliser la fonction transiter(struct graphe * pgraphe, int etat, int symbole)
	// Qui renvoie l'état d'arrivée, ou -1 si la transition n'existe pas

	int a = 0;

	int x = transiter(pautomate->graphe_trans, pautomate->etat_init, mot[0]);

	int i=0;
	
	while((mot[i]!='/o') && (x != -1))
	{
		x = transiter(pautomate->graphe_trans, x, mot[i]);
		i++;
	}

	// Il faut que l'on soit dans un état final pour que le mot soit reconnu par l'AFD
	int j = 0;
	while((j<(int)(sizeof(pautomate->etats_finaux)/ sizeof(int))) && (a == 0))
	{
		if (x == etats_finaux[j])
		{
			a = 1;
		}
		j++;
	}

	return a;
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