#include "moteur.h"
#include "affichage.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int    id_regle  = -1;
    int    graine    = -1;
    int    toroidale = 0;
    int    largeur   = 80;
    int    hauteur   = 60;
    int    delai_ms  = 200;
    int    nb_pas    = -1;    // -1 = infini
    int    opt;

    while ((opt = getopt(argc, argv, "r:s:tS:d:c:")) != -1) {
        switch (opt) {
        case 's':
            graine = atoi(optarg);
            break;

        case 't':
            toroidale = 1;
            break;

        case 'S': {
        	// largeur,hauteur
            char *virgule = strchr(optarg, ',');
            if (!virgule) {
                fprintf(stderr, "Erreur : -S attend <largeur>,<hauteur>\n");
                return 1;
            }
            *virgule = '\0';
            largeur = atoi(optarg);
            hauteur = atoi(virgule + 1);
            if (largeur <= 0 || hauteur <= 0) {
                fprintf(stderr, "Erreur : dimensions invalides\n");
                return 1;
            }
            break;
        }

        case 'd':
            delai_ms = atoi(optarg);
            if (delai_ms < 0) {
                fprintf(stderr, "Erreur : durée invalide\n");
                return 1;
            }
            break;

        case 'c':
            nb_pas = atoi(optarg);
            if (nb_pas <= 0) {
                fprintf(stderr, "Erreur : nombre de pas invalide\n");
                return 1;
            }
            break;

        default:
            fprintf(stderr,
                "Usage: %s -r <id> [-s <graine>] [-t] [-S <l>,<h>]"
                " [-d <ms>] [-c <pas>]\n", argv[0]);
            return 1;
        }
    }

    // selection mode de jeu



    // Initialisation
    JeuDeLaVie jeu;
    initialiser_jeu(&jeu, toroidale);

    /* Chargement fichier OU aléatoire */
    if (graine >= 0) {
        srand((unsigned)graine);
        for (int i = 0; i < HAUTEUR; i++)
            for (int j = 0; j < LARGEUR; j++)
                jeu.grille[i][j] = rand() % 2;
    } else {
        FILE *f = fopen("grille_test.txt", "r");
        if (!f) {
            fprintf(stderr, "Erreur : fichier grille_test.txt introuvable\n");
            return 1;
        }
        txt_vers_grille(&jeu, f);
        fclose(f);
    }

    // boucle principale
    int pas = 0;
    while (nb_pas < 0 || pas < nb_pas) {
        afficher_grille(jeu);
        mettre_a_jour_Conway(&jeu);
        usleep((unsigned)(delai_ms * 1000));
        pas++;
    }

    return 0;
}
