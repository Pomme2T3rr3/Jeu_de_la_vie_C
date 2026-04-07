#include "moteur.h"
#include "affichage.h"
#include <unistd.h>


int main() {
	JeuDeLaVie jeu;
	int running = 1;
	initialiser_jeu(&jeu, 0);   // toujours initialiser

	FILE* f = fopen("grille_test.txt", "r");
	if (!f) { perror("Erreur ouverture fichier"); return 1; }
	txt_vers_grille(&jeu, f);
	fclose(f);

	while(running) {
		mettre_a_jour_Conway(&jeu);
		afficher_grille(jeu);
		usleep(50000);
	}
	return 0;
}
