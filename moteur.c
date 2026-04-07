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

int est_vivante(const JeuDeLaVie jeu, int i, int j) {
	return jeu.grille[i][j];
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

void mettre_a_jour_Conway(JeuDeLaVie *jeu) {
    int tmp[HAUTEUR][LARGEUR];

    for (int i = 0; i < HAUTEUR; i++)
        for (int j = 0; j < LARGEUR; j++) {
            int n = nb_cases_vivantes(*jeu, i, j);

            if (n == 3) tmp[i][j] = 1;
            else if (n == 2) tmp[i][j] = jeu->grille[i][j];
            else tmp[i][j] = 0;
        }
    memcpy(jeu->grille, tmp, sizeof(tmp));
}


void mettre_a_jour_Majorite(JeuDeLaVie *jeu) {
    int tmp[HAUTEUR][LARGEUR];	// tableau temp -> stocker nouvelles valeurs

    for (int i = 0; i < HAUTEUR; i++)
        for (int j = 0; j < LARGEUR; j++) {
            int n = nb_cases_vivantes(*jeu, i, j);

            if ((n > 4) && (est_vivante(*jeu, i, j)))
                tmp[i][j] = 1;
            else
                tmp[i][j] = 0;
        }
    memcpy(jeu->grille, tmp, sizeof(tmp));
}


void mettre_a_jour_Langton(JeuDeLaVie *jeu) {
    int tmp[HAUTEUR][LARGEUR];	// tableau temp -> stocker nouvelles valeurs

    for (int i = 0; i < HAUTEUR; i++)
        for (int j = 0; j < LARGEUR; j++) {
            int n = nb_cases_vivantes(*jeu, i, j);

            if ((n > 4) && (est_vivante(*jeu, i, j)))
                tmp[i][j] = 1;
            else
                tmp[i][j] = 0;
        }
    memcpy(jeu->grille, tmp, sizeof(tmp));
}


void txt_vers_grille(JeuDeLaVie *jeu, FILE *fichier) {
	int i = 0, j = 0;
	int val;

	int c;
	while ((c = fgetc(fichier)) != EOF) {
	    if (c == '0' || c == '1') {
	        jeu->grille[i][j] = c - '0';
	        if (++j >= LARGEUR) { j = 0; i++; }
	    }
	    // ignore '\n' et autres caractères
	}

}
