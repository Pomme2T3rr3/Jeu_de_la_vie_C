#include "moteur.h"


void initialiser_grille(JeuDeLaVie* jeu) {
	for (int i = 0; i < HAUTEUR; i++) {
		for (int j = 0; j < LARGEUR; j++) {
			jeu->grille[i][j] = 0;
		}
	}
}

void initialiser_jeu(JeuDeLaVie* jeu, int toroidale) {
	jeu->toroidale = toroidale;
	initialiser_grille(jeu);
}
