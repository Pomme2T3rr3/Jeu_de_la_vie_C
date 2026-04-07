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

int nb_cases_vivantes(const JeuDeLaVie jeu, int i, int j) {
	int cpt = 0;

	for (int di = -1; di <= 1; di++) {
		for (int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0) continue;

			int ni = i + di;
			int nj = j + dj;

			if (jeu.toroidale) {
				ni = (ni + HAUTEUR) % HAUTEUR;
				nj = (nj + LARGEUR) % LARGEUR;
			}

			if (ni < 0 || ni >= HAUTEUR || nj < 0 || nj >= LARGEUR) continue;

			if (jeu.grille[ni][nj]) cpt++;
		}
	}
	return cpt;
}

void mettre_a_jour(JeuDeLaVie *jeu) {
	for (int i = 0; i < HAUTEUR; i++) {
		for (int j = 0; j < LARGEUR; j++) {
			if (nb_cases_vivantes(*jeu, i, j) == 3) jeu->grille[i][j] = 1;
			else if (nb_cases_vivantes(*jeu, i, j) == 2) continue;
			else jeu->grille[i][j] = 0;
		}
	}
}


void txt_vers_grille(JeuDeLaVie *jeu, FILE *fichier) {
	
}