#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


typedef struct{
    int *number;
    SDL_Rect pos;
}piece;

typedef struct{
	int victoireDom;	//nb victoires au jeu des dominos
	int scoreTri;  //meilleur score au jeu des triominos
	
}joueur;


//piece *pieces;
//char jeu;

void accueil (SDL_Surface *ecran);
void jeu (SDL_Surface *ecran);

#endif
