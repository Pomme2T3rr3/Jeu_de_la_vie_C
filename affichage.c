#include "affichage.h"
#include "moteur.h"
#include <stdio.h>

void afficher_grille(const JeuDeLaVie jeu) {
    printf("\033[H\033[2J");  // efface l'écran (séquence ANSI)
    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++)
            printf("%c", jeu.grille[i][j] ? 'X' : ' ');
        printf("\n");
    }
}
