#ifndef MOTEUR_H
#define MOTEUR_H

#define HAUTEUR 60
#define LARGEUR 80

#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int grille[HAUTEUR][LARGEUR];
	int toroidale;
} JeuDeLaVie;

void initialiser_grille(JeuDeLaVie* jeu);
void initialiser_jeu(JeuDeLaVie* jeu, int toroidale);
int nb_cases_vivantes(const JeuDeLaVie jeu, int i, int j);
void mettre_a_jour_Conway(JeuDeLaVie* jeu);
void txt_vers_grille(JeuDeLaVie* jeu, FILE* fichier);

#endif
