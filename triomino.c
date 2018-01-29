#include "structures.h"


void alloc_jeu(piece** trio);
void alloc_joueurs(piece** trio);
void init_pieces( piece** trio);
void init_trioJ( piece** trio);
void hasard( int* melange);
void distribution(int nbJoueur, piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP);
void distribution_2J(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioP);
void distribution_3_4J(int nbJoueur,piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP);

int main()
{
	piece* trio = NULL;
	piece *trioJ1 = NULL, *trioJ2 = NULL, *trioJ3 = NULL, *trioJ4 = NULL, *trioP = NULL;
	int i,j;
	int grdTriple, jCommence, recupTriple;
	
	srand(time(NULL));
	
	alloc_jeu(&trio);
	init_pieces(&trio);
	alloc_joueurs(&trioJ1);
	alloc_joueurs(&trioJ2);
	alloc_joueurs(&trioJ3);
	alloc_joueurs(&trioJ4);
	alloc_joueurs(&trioP);
	
	init_trioJ(&trioJ1);
	init_trioJ(&trioJ2);
	init_trioJ(&trioJ3);
	init_trioJ(&trioJ4);
	init_trioJ(&trioP);
	
	
	distribution(3, &trio, &trioJ1,  &trioJ2,  &trioJ3,  &trioJ4, &trioP);
	
	
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("  %d	",trioJ1[i].number[j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("  %d	",trioJ2[i].number[j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<8;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("  %d	",trioJ3[i].number[j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<8;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("  %d	",trioJ4[i].number[j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0;i<40;i++)
	{
		printf("i: %d", i);
		for(j=0;j<3;j++)
		{
			printf("  %d	",trioP[i].number[j]);
		}
		printf("\n");
	}
	
	
	return 0;
		
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
		(*trio)[i].number = (int*) malloc (3*sizeof(int));
		if((*trio)[i].number == NULL)
		{
			printf("PB alloction jeu\n");
			exit(0);
		}
	}
}

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
		(*trio)[i].number = (int*) malloc (3*sizeof(int));
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
		for(j=0;j<3;j++)
		{
			if(j==0)
			{
				(*trio)[i].number[j] = a;
			}
			else if(j==1)
			{
				(*trio)[i].number[j] = b;
			}
			else
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
		for(j=0;j<3;j++)
		{
			(*trio)[i].number[j] = 8;
		}
	}
}

void distribution(int nbJoueur, piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP)
{
	if(nbJoueur==2)
	{
		distribution_2J(trio, trioJ1, trioJ2, trioP);
	}
	else
	{
		distribution_3_4J(nbJoueur, trio, trioJ1, trioJ2, trioJ3, trioJ4, trioP);
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
			(*trioJ1)[a].number[1]= (*trio)[melange[i]].number[1];
			(*trioJ1)[a].number[2]= (*trio)[melange[i]].number[2];
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

void distribution_3_4J(int nbJoueur,piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4, piece** trioP)
{
	int a=0,b=0,c=0,d=0,e=0,i=0, melange[56];
	
	hasard(melange);
	
	do
	{
		if(i%4==0)
		{
			(*trioJ1)[a].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ1)[a].number[1]= (*trio)[melange[i]].number[1];
			(*trioJ1)[a].number[2]= (*trio)[melange[i]].number[2];
			a++;
		}
		else if(i%4==1)
		{
			(*trioJ2)[b].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ2)[b].number[1]= (*trio)[melange[i]].number[1];
			(*trioJ2)[b].number[2]= (*trio)[melange[i]].number[2];
			b++;
		}
		else if(i%4==2)
		{
			(*trioJ3)[c].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ3)[c].number[1]= (*trio)[melange[i]].number[1];
			(*trioJ3)[c].number[2]= (*trio)[melange[i]].number[2];
			c++;
		}
		else if(i%4==3 && nbJoueur==4)
		{
			(*trioJ4)[d].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ4)[d].number[1]= (*trio)[melange[i]].number[1];
			(*trioJ4)[d].number[2]= (*trio)[melange[i]].number[2];
			d++;
		}
		i++;
	}while((a<7) || (b<7) || (c<7) || ( (d<7) && (nbJoueur==4)));
	if(nbJoueur==3)	{
		i=20;
	}
	for(i=i;i<56;i++)
	{
		(*trioP)[e].number[0]= (*trio)[melange[i]].number[0];
		(*trioP)[e].number[1]= (*trio)[melange[i]].number[1];
		(*trioP)[e].number[2]= (*trio)[melange[i]].number[2];
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
