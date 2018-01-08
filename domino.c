#include "structures.h"

void alloc_jeu(piece** domino);
void alloc_joueurs(piece** domino);
void desalloc_jeu(piece** domino);
void desalloc_joueurs(piece** domino);
void init_pieces(piece** domino);
void init_domJ(piece** domino);
void hasard( int* melange);
void distribution_carte(int nbJoueur, piece** domino, piece** domJ1, piece** domJ2, piece** domJ3, piece** domJ4);
void distribution_2J(piece** domino, piece** domJ1, piece** domJ2);
void distribution_3_4J(int nbJoueur,piece** domino, piece** domJ1, piece** domJ2, piece** domJ3, piece** domJ4);
void ordre_joueur(int jCommence, int nbJoueur, piece* domJ1, piece* domJ2, piece* domJ3, piece* domJ4,
				  piece** joueur1, piece** joueur2, piece** joueur3, piece** joueur4);

int main()
{
	piece* domino = NULL;
	piece *domJ1 = NULL, *domJ2 = NULL, *domJ3 = NULL, *domJ4 = NULL;
	piece *joueur1 = NULL, *joueur2 = NULL, *joueur3 = NULL, *joueur4 = NULL;
	//~ a recuperer du code d'helo
	int nbJoueur = 3, grdDouble = 6, jCommence = 2;
	int i, j, resultat;
	
	srand(time(NULL));
	
	alloc_jeu(&domino);
	alloc_joueurs(&domJ1);
	alloc_joueurs(&domJ2);
	alloc_joueurs(&domJ3);
	alloc_joueurs(&domJ4);
	alloc_joueurs(&joueur1);
	alloc_joueurs(&joueur2);
	alloc_joueurs(&joueur3);
	alloc_joueurs(&joueur4);
	
	init_pieces(&domino);
	init_domJ(&domJ1);
	init_domJ(&domJ2);
	init_domJ(&domJ3);
	init_domJ(&domJ4);
	init_domJ(&joueur1);
	init_domJ(&joueur2);
	init_domJ(&joueur3);
	init_domJ(&joueur4);
	
	distribution_carte(nbJoueur, &domino, &domJ1, &domJ2, &domJ3, &domJ4);

	//~ Verifiction jCommence
	
	ordre_joueur(jCommence, nbJoueur, domJ1, domJ2, domJ3, domJ4, &joueur1, &joueur2, &joueur3, &joueur4);
	

	
	
	desalloc_jeu(&domino);
	desalloc_joueurs(&domJ1);
	desalloc_joueurs(&domJ2);
	desalloc_joueurs(&domJ3);
	desalloc_joueurs(&domJ4);

	return 0;
}

void alloc_jeu(piece** domino)
{
	int i;
	*domino = (piece*) malloc (28*sizeof(piece));
	if(domino == NULL)
	{
		printf("PB alloction jeu\n");
		exit(0);
	}	
	for(i=0;i<28;i++)
	{
		(*domino)[i].number = (int*) malloc (2*sizeof(int));
		if((*domino)[i].number == NULL)
		{
			printf("PB alloction jeu\n");
			exit(0);
		}
	}
	
}

void init_pieces( piece** domino)
{
	int a=0, b=0, i,j;

	for(i=0;i<28;i++)
	{
		for(j=0;j<2;j++)
		{
			if(j==0)
			{
				(*domino)[i].number[j] = a;
			}
			else
			{
				(*domino)[i].number[j] = b;
				b++;
			}
			if(b==7)
			{
				a++;
				b=a;
			}
		}	
	}
}

void alloc_joueurs(piece** domino)
{
	int i;
	
	*domino = (piece*) malloc (7*sizeof(piece));	
	if(domino == NULL)
	{
		printf("PB alloction joueur\n");
		exit(0);
	}
	for(i=0;i<7;i++)
	{
		(*domino)[i].number = (int*) malloc (2*sizeof(int));
		if((*domino)[i].number == NULL)
		{
			printf("PB alloction joueur\n");
			exit(0);
		}
	}
	
}

void desalloc_jeu(piece** domino)
{ 
	int i;
	for(i=0;i<28;i++)
	{
		free((*domino)[i].number);
	}
	free(*domino);
	
}

void desalloc_joueurs(piece** domino)
{ 
	int i;
	for(i=0;i<7;i++)
	{
		free((*domino)[i].number);
	}
	free(*domino);
	
}

void init_domJ( piece** domino)
{ 
	int i,j;
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<2;j++)
		{
			(*domino)[i].number[j] = 8;
		}
	}
}

void distribution_carte(int nbJoueur, piece** domino, piece** domJ1, piece** domJ2, piece** domJ3, piece** domJ4)
{
	if(nbJoueur==2)
	{
		distribution_2J(domino, domJ1, domJ2);
	}
	else
	{
		distribution_3_4J(nbJoueur, domino, domJ1, domJ2, domJ3, domJ4);
	}
}

void distribution_2J(piece** domino, piece** domJ1, piece** domJ2)
{
	int a=0,i,b=0, melange[28];
	hasard(melange);
	i=0;
	do
	{
		if(i%2==0)
		{
			(*domJ1)[a].number[0]= (*domino)[melange[i]].number[0];
			(*domJ1)[a].number[1]= (*domino)[melange[i]].number[1];
			a++;
		}
		else if(i%2==1)
		{
			(*domJ2)[b].number[0]= (*domino)[melange[i]].number[0];
			(*domJ2)[b].number[1]= (*domino)[melange[i]].number[1];
			b++;
		}
		i++;
	} while((a<7)||(b<7));
	
}

void distribution_3_4J(int nbJoueur,piece** domino, piece** domJ1, piece** domJ2, piece** domJ3, piece** domJ4)
{
	int a=0,i,b=0,c=0,d=0, melange[28];
	hasard(melange);
	i=0;
	do
	{
		if(i%4==0)
		{
			(*domJ1)[a].number[0]= (*domino)[melange[i]].number[0];
			(*domJ1)[a].number[1]= (*domino)[melange[i]].number[1];
			a++;
		}
		else if(i%4==1)
		{
			(*domJ2)[b].number[0]= (*domino)[melange[i]].number[0];
			(*domJ2)[b].number[1]= (*domino)[melange[i]].number[1];
			b++;
		}
		else if(i%4==2)
		{
			(*domJ3)[c].number[0]= (*domino)[melange[i]].number[0];
			(*domJ3)[c].number[1]= (*domino)[melange[i]].number[1];
			c++;
		}
		else if(i%4==3 && nbJoueur==4)
		{
			(*domJ4)[d].number[0]= (*domino)[melange[i]].number[0];
			(*domJ4)[d].number[1]= (*domino)[melange[i]].number[1];
			d++;
		}
		i++;
	} while((a<6) || (b<6) || (c<6) || ( (d<6) && (nbJoueur==4)) );
	
}

void hasard( int* melange)
{
	int a,b,i;
	for(i=0;i<28;i++)
	{
		melange[i]=i;
	}

	for(i=0;i<28;i++)
	{
		b =rand()%28;
		a = melange[i];
		melange[i] = melange[b];
		melange[b] = a;
	}
}

void ordre_joueur(int jCommence, int nbJoueur, piece* domJ1, piece* domJ2, piece* domJ3, piece* domJ4,
				  piece** joueur1, piece** joueur2, piece** joueur3, piece** joueur4)
{	
	if(nbJoueur==2)
	{
		if(jCommence==1)
		{
			*joueur1=domJ1;
			*joueur2=domJ2;
		}
		else if(jCommence==2)
		{
			*joueur1=domJ2;
			*joueur2=domJ1;
		}	
	}
	else if(nbJoueur==3)
	{
		if(jCommence==1)
		{
			*joueur1=domJ1;
			*joueur2=domJ2;
			*joueur3=domJ3;
		}
		else if(jCommence==2)
		{
			*joueur1=domJ2;
			*joueur2=domJ3;
			*joueur3=domJ1;
		}	
		else if(jCommence==3)
		{
			*joueur1=domJ3;
			*joueur3=domJ1;
			*joueur4=domJ2;
		}	
	}
	else 
	{
		if(jCommence==1)
		{
			*joueur1=domJ1;
			*joueur2=domJ2;
			*joueur3=domJ3;
			*joueur4=domJ4;
		}
		else if(jCommence==2)
		{
			*joueur1=domJ2;
			*joueur2=domJ3;
			*joueur3=domJ4;
			*joueur4=domJ1;
		}	
		else if(jCommence==3)
		{
			*joueur1=domJ3;
			*joueur2=domJ4;
			*joueur3=domJ1;
			*joueur4=domJ2;
		}	
		else if(jCommence==2)
		{
			*joueur1=domJ4;
			*joueur2=domJ1;
			*joueur3=domJ2;
			*joueur4=domJ3;
		}
	}
}
