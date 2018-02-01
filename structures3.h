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
	int scoreTri;  //meilleur score au jeu des triominos*piec
	piece *pj;
	char *pseudo;
}joueur;


//piece *pieces;
//char jeu;
piece * init_dom(int type);

void accueil (SDL_Surface *ecran);
void jeu(SDL_Surface *ecran);
void nb_joueur(SDL_Surface *ecran);
void board_d(SDL_Surface *ecran);
void melange(int nbjoueur,piece *p);
void debut_domino(SDL_Surface *ecran);
char *concat(const char *s1, const char *s2);
void distribuer(SDL_Surface *ecran);

void alloc_jeu(piece** trio);
void alloc_joueurs(piece** trio);
void init_pieces( piece** trio);
void init_trioJ( piece** trio);
void init_trioP( piece** trio);
void hasard( int* melange);
void distribution(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP);
void distribution_2J(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioP);
void distribution_3_4J(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP);
void renomme_joueur(piece** jJoue, int jCommence, piece* trioJ1, piece* trioJ2, piece* trioJ3, piece* trioJ4,
					int *score, int *j1, int *j2, int *j3, int *j4);
int calc_score(piece *trio, int i);
void decalage_trio(piece** trio, int num, int pion);


void init_triomino(SDL_Surface *ecran);
void affiche_piece(SDL_Surface *ecran, piece* trioJ1, piece* trioJ2, piece* trioJ3, piece* trioJ4, int Jactuel);
void pause();
int clic_joueur(SDL_Rect posClic, SDL_Rect posJ, int Jactuel);
int clic_joueur2(int Jactuel);
void afficher_J(SDL_Surface *ecran, piece *trioJ1, int i);
void afficher_cacher(SDL_Surface *ecran, int j, int k, int m);
int affiche_jeu_trio(SDL_Surface *ecran, piece* trioJ1, piece* trioJ2, piece* trioJ3, piece* trioJ4, int Jactuel);

#endif
