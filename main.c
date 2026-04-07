#include "moteur.h"
#include "affichage.h"


int main() {
	JeuDeLaVie jeu;
	int running = 1;
	initialiser_jeu(&jeu, 0);

	FILE* f = fopen("grille_test.txt", "r");
	txt_vers_grille(&jeu, f);

	while(running) {
		mettre_a_jour(&jeu);
		afficher_grille(jeu);
	}

	return 0;
}
