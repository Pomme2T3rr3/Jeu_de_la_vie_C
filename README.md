# Jeu de la Vie en C

Implémentation du célèbre **Jeu de la Vie** de Conway en langage C.

## Description

Le Jeu de la Vie est un automate cellulaire créé par John Horton Conway en 1970. Il s'agit d'un jeu de simulation à zéro joueur dont l'évolution est déterminée par son état initial.

## Règles

1. Toute cellule vivante avec 2 ou 3 voisins survit
2. Toute cellule morte avec exactement 3 voisins devient vivante
3. Toutes les autres cellules meurent ou restent mortes

## Fonctionnalités

- Grille configurable
- Simulation pas à pas
- Affichage du plateau de jeu

## Compilation

```bash
gcc -o jeu_de_la_vie main.c
```

## Utilisation

```bash
./jeu_de_la_vie
```

## Auteur

damdamdeo