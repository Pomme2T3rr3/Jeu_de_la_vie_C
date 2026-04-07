#include "moteur.h"
#include "affichage.h"


int main() {
	JeuDeLaVie jeu;
	initialiser_jeu(&jeu, 1);
	afficher_grille(jeu);
	return 0;
}
