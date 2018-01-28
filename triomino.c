#include "structures.h"


void alloc_jeu(piece** trio);
void alloc_joueurs(piece** trio);
void init_pieces( piece** trio);
void distribution_3_4J(int nbJoueur,piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4);
void hasard( int* melange);
void init_trioJ( piece** trio);

int main()
{
	piece* trio = NULL;
	piece *trioJ1 = NULL, *trioJ2 = NULL, *trioJ3 = NULL, *trioJ4 = NULL;
	int i,j;
	srand(2);
	
	alloc_jeu(&trio);
	init_pieces(&trio);
	alloc_joueurs(&trioJ1);
	alloc_joueurs(&trioJ2);
	alloc_joueurs(&trioJ3);
	alloc_joueurs(&trioJ4);
	
	init_trioJ(&trioJ1);
	init_trioJ(&trioJ2);
	init_trioJ(&trioJ3);
	init_trioJ(&trioJ4);
	
	
	distribution_3_4J(4, &trio, &trioJ1,  &trioJ2,  &trioJ3,  &trioJ4);
	
	
	
	
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
	
	*trio = (piece*) malloc (7*sizeof(piece));	
	if(trio == NULL)
	{
		printf("PB alloction joueur\n");
		exit(0);
	}
	for(i=0;i<7;i++)
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
			a++;
			b=a;
			c=a;
		}
		else if(b==c)
		{
			b++;
			c=a;
		}
		else
		{
			c++;
		}
	}
}




void distribution_3_4J(int nbJoueur,piece** trio, piece** trioJ1, piece** trioJ2, piece** trioJ3, piece** trioJ4)
{
	int a=0,i=0,b=0,c=0,d=0, melange[56];
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
		else if(i%4==2 && (nbJoueur==3 || nbJoueur==4) )
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
	} while((a<7) || (b<7) || ( (c<7) && (nbJoueur==3)) || ( (d<7) && (nbJoueur==4)) );
	
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


void init_trioJ( piece** trio)
{ 
	int i,j;
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<3;j++)
		{
			(*trio)[i].number[j] = 8;
		}
	}
}
