#ifndef MOTEUR_H
#define MOTEUR_H

#define HAUTEUR 60
#define LARGEUR 80

#include <stdint.h>
#include <stdio.h>

typedef struct {
	int grille[HAUTEUR][LARGEUR];
	int toroidale;
} JeuDeLaVie;

void initialiser_grille(JeuDeLaVie* jeu);
void initialiser_jeu(JeuDeLaVie* jeu, int toroidale);
void mettre_a_jour(JeuDeLaVie* jeu);

#endif
