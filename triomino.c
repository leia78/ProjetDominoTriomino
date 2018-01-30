#include "structures.h"
extern int nbjoueur;

void init_triomino()
{
	piece* trio = NULL;
	piece *trioJ1 = NULL, *trioJ2 = NULL, *trioJ3 = NULL, *trioJ4 = NULL, *trioP = NULL;
	piece *jJoue;
	int i,j, score=0;
	int jCommence, somme, resultat=0;
	int j1=0, j2=0, j3=0, j4=0;
	
	srand(time(NULL));
	
	alloc_jeu(&trio);
	init_pieces(&trio);
	alloc_joueurs(&trioJ1);
	alloc_joueurs(&trioJ2);
	alloc_joueurs(&trioJ3);
	alloc_joueurs(&trioJ4);
	alloc_joueurs(&trioP);
	alloc_joueurs(&jJoue);
	
	init_trioJ(&trioJ1); 
	init_trioJ(&trioJ2);
	init_trioJ(&trioJ3);
	init_trioJ(&trioJ4);
	init_trioJ(&trioP);
	
	distribution(&trio, &trioJ1,  &trioJ2,  &trioJ3,  &trioJ4, &trioP);
	
	//qui commence
	for(i=0;i<nbjoueur;i++)
	{
		somme = calc_score(trioP, i);
		if( resultat<somme)
		{
			resultat = somme;
			jCommence = i+1;
		}
	}
	
	renomme_joueur(&jJoue, jCommence, trioJ1, trioJ2, trioJ3, trioJ4, &score, &j1, &j2, &j3, &j4);
	
	//debut du jeu 
	//joueur 1 pose un pion
	//		   marque son score
	
	//joueur 2  choisit un pion  
	//	        veriff bon si peut pas pioche jusq'a trois fois et il perd 5pt
	// 			pose pion + marque le score ou perte 10pts
	
	// faire ca tant que les joueurs ont des pions ou que la pioche soit vide 
	// et que les joueurs ne puisse plus jouer.	
}

void alloc_jeu(piece** trio)
{
	int i;
	*trio = (piece*) malloc (56*sizeof(piece));
	if(trio == NULL)
	{
		printf("PB alloction jeu\n");
		exit(0);
	}	
	for(i=0;i<56;i++)
	{
		(*trio)[i].number = (int*) malloc (4*sizeof(int));
		if((*trio)[i].number == NULL)
		{
			printf("PB alloction jeu\n");
			exit(0);
		}
	}
}

//ordre des cases h1 h2 b1 b2
void alloc_joueurs(piece** trio)
{
	int i;
	
	*trio = (piece*) malloc (40*sizeof(piece));	
	if(trio == NULL)
	{
		printf("PB alloction joueur\n");
		exit(0);
	}
	for(i=0;i<40;i++)
	{
		(*trio)[i].number = (int*) malloc (4*sizeof(int));
		if((*trio)[i].number == NULL)
		{
			printf("PB alloction joueur\n");
			exit(0);
		}
	}
}

void init_pieces( piece** trio)
{
	int a=0, b=0,c=0, i,j;

	for(i=0;i<56;i++)
	{
		for(j=0;j<4;j++)
		{
			if(j==0)
			{
				(*trio)[i].number[j] = a;
			}
			else if(j==2)
			{
				(*trio)[i].number[j] = b;
			}
			else if(j==3)
			{
				(*trio)[i].number[j] = c;
			}
		}
		
		if(c==5)
		{
			a++; b=a; c=a;
		}
		else if(b==c)
		{
			b++; c=a;
		}
		else
		{
			c++;
		}
	}
}

void init_trioJ( piece** trio)
{ 
	int i,j;
	
	for(i=0;i<40;i++)
	{
		for(j=0;j<4;j++)
		{
			(*trio)[i].number[j] = 8;
		}
	}
}

void distribution(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP)
{
	if(nbjoueur==2)
	{
		distribution_2J(trio, trioJ1, trioJ2, trioP);
	}
	else
	{
		distribution_3_4J(trio, trioJ1, trioJ2, trioJ3, trioJ4, trioP);
	}
}

//9 si 2 joueur 7 si plus 
void distribution_2J(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioP)
{
	int a=0,i,b=0, melange[56];
	hasard(melange);
	i=0;
	do
	{
		if(i%2==0)
		{
			(*trioJ1)[a].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ1)[a].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ1)[a].number[3]= (*trio)[melange[i]].number[3];
			a++;
		}
		else if(i%2==1)
		{
			(*trioJ2)[b].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ2)[b].number[1]= (*trio)[melange[i]].number[1];
			(*trioJ2)[b].number[2]= (*trio)[melange[i]].number[2];
			b++;
		}
		i++;
	} while((a<9)||(b<9));
	
}

void distribution_3_4J(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP)
{
	int a=0,b=0,c=0,d=0,e=0,i=0, melange[56];
	
	hasard(melange);
	
	do
	{
		if(i%4==0)
		{
			(*trioJ1)[a].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ1)[a].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ1)[a].number[3]= (*trio)[melange[i]].number[3];
			a++;
		}
		else if(i%4==1)
		{
			(*trioJ2)[b].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ2)[b].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ2)[b].number[3]= (*trio)[melange[i]].number[3];
			b++;
		}
		else if(i%4==2)
		{
			(*trioJ3)[c].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ3)[c].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ3)[c].number[3]= (*trio)[melange[i]].number[3];
			c++;
		}
		else if(i%4==3 && nbjoueur==4)
		{
			(*trioJ4)[d].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ4)[d].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ4)[d].number[3]= (*trio)[melange[i]].number[3];
			d++;
		}
		i++;
	}while((a<7) || (b<7) || (c<7) || ( (d<7) && (nbjoueur==4)));
	if(nbjoueur==3)	{
		i=20;
	}
	for(i=i;i<56;i++)
	{
		(*trioP)[e].number[0]= (*trio)[melange[i]].number[0];
		(*trioP)[e].number[2]= (*trio)[melange[i]].number[2];
		(*trioP)[e].number[3]= (*trio)[melange[i]].number[3];
		e++;
	}
}

void hasard( int* melange)
{
	int a,b,i;
	for(i=0;i<56;i++)
	{
		melange[i]=i;
	}

	for(i=0;i<56;i++)
	{
		b =rand()%56;
		a = melange[i];
		melange[i] = melange[b];
		melange[b] = a;
	}
}

void renomme_joueur(piece** jJoue, int jCommence, piece* trioJ1, piece* trioJ2, piece* trioJ3, piece* trioJ4,
					int *score, int *j1, int *j2, int *j3, int *j4)
{
	if(nbjoueur==2 && jCommence==1 )
	{ 
		*jJoue=trioJ1;
		*j2=*score;
		*score=*j1;
	}
	else if(nbjoueur==2 && jCommence==2 )
	{ 
		*jJoue=trioJ2;
		*j1=*score;
		*score=*j2;
	}
	else if(nbjoueur==3 && jCommence==1 )
	{ 
		*jJoue=trioJ1;
		*j3=*score;
		*score=*j1;
	}
	else if(nbjoueur==3 && jCommence==2 )
	{ 
		*jJoue=trioJ2;
		*j1=*score;
		*score=*j2;
	}
	else if(nbjoueur==3 && jCommence==3 )
	{ 
		*jJoue=trioJ3;
		j2=score;
		score=j3;
	}
	else if(nbjoueur==4 && jCommence==1 )
	{ 
		*jJoue=trioJ1;
		j4=score;
		*score=*j1;
	}
	else if(nbjoueur==4 && jCommence==2 )
	{ 
		*jJoue=trioJ2;
		*j1=*score;
		*score=*j2;
	}
	else if(nbjoueur==4 && jCommence==3 )
	{ 
		*jJoue=trioJ3;
		*j2=*score;
		*score=*j3;
	}
	else if(nbjoueur==4 && jCommence==4 )
	{ 
		*jJoue=trioJ4;
		*j3=*score;
		*score=*j4;
	}
}

int calc_score(piece *trio, int i)
{
	int score;
	if(trio[i].number[0] == 8)
	{
		score = trio[i].number[1]+trio[i].number[2]+trio[i].number[3];
	}
	else if(trio[i].number[1] == 8)
	{
		score = trio[i].number[0]+trio[i].number[2]+trio[i].number[3];
	}
	else if(trio[i].number[2] == 8)
	{
		score = trio[i].number[0]+trio[i].number[1]+trio[i].number[3];
	}
	else if(trio[i].number[3] == 8)
	{
		score = trio[i].number[0]+trio[i].number[1]+trio[i].number[2];
	}
	return score;
}
