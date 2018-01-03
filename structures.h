#ifndef STRUCTURES_H
#define STRUCTURES_H

#define LECRAN 1000
#define HECRAN 800

#define LBOUTON 100
#define HBOUTON 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


typedef struct{
    char **number;
    SDL_Rect pos;
}piece;

typedef struct{
	int victoireDom;	//nb victoires au jeu des dominos
	int scoreTri;  //meilleur score au jeu des triominos
	char *pseudo;
}joueur;


//piece *pieces;
//char jeu;

void accueil (SDL_Surface *ecran);
void jeu (SDL_Surface *ecran);

#endif
