#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct{
    int x;
    int y;
}position;

typedef struct{
    int *number;
    position pos;
}piece;

piece *pieces;
char jeu;

void accueil (void);

#endif
