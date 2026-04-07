#include "affichage.h"
#include "moteur.h"
#include <stdio.h>

void afficher_grille(const JeuDeLaVie jeu) {
	for (int i = 0; i < HAUTEUR; i++) {
		for (int j = 0; j < LARGEUR; j++) {
			printf("%d", jeu.grille[i][j]);
		}
		printf("\n");
	}
}
