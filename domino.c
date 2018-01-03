#include "structures.h"

void alloc(piece* domino);
void desalloc(piece* domino);
void init_pieces( piece* domino);
void hasard( int* melange);
void init_domJ(piece* domino);
void distribution_2J(piece domino, piece* domJ1, piece* domJ2, piece* pioche);
int main()
{
	piece domino;
	int i, j,b, a,c;
	piece domJ1, domJ2, domJ3, domJ4, pioche;
	
	srand(time(NULL));
	
	alloc(&domino);
	alloc(&domJ1);
	alloc(&domJ2);
	alloc(&domJ3);
	alloc(&domJ4);
	alloc(&pioche);
	
	init_pieces(&domino);
	init_domJ(&domJ1);
	init_domJ(&domJ2);
	init_domJ(&domJ3);
	init_domJ(&domJ4);
	init_domJ(&pioche);
	
	
	distribution_2J( domino, &domJ1, &domJ2, &pioche);
		
	
	desalloc(&domino);
	desalloc(&domJ1);
	desalloc(&domJ2);
	desalloc(&domJ3);
	desalloc(&domJ4);
	desalloc(&pioche);
	 
	return 0;
}

void alloc(piece* domino)
{
	int i;
	domino->number = (int**) malloc (28*sizeof(int*));
	for(i=0;i<28;i++)
	{
		domino->number[i] = (int*) malloc(2*sizeof(int));
	}
}
void desalloc(piece* domino)
{ 
	int i;
	for(i=0;i<28;i++)
	{
		free(domino->number[i]);
	}
	free(domino->number);
}
void init_domJ(piece* domino)
{ 
	int i,j;
	
	for(i=0;i<28;i++)
	{
		for(j=0;j<2;j++)
		{
			domino->number[i][j] = 8;
		}
	}
}
void init_pieces( piece* domino)
{
	int a=0, b=0, i,j;

	for(i=0;i<28;i++)
	{
		for(j=0;j<2;j++)
		{
			if(j==0)
			{
				domino->number[i][j] = a;
			}
			else
			{
				domino->number[i][j] = b;
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

void distribution_2J(piece domino, piece* domJ1, piece* domJ2, piece* pioche)
{
	int melange[28], a=0,b=0,c=0,i;
	
	hasard(melange);
	
	for(i=0;i<28;i++)
	{
		if(i<14)
		{
			if(i%2==0)
			{
				domJ1->number[a][0]= domino.number[melange[i]][0];
				domJ1->number[a][1]= domino.number[melange[i]][1];
				a++;
			}
			else
			{
				domJ2->number[b][0]= domino.number[melange[i]][0];
				domJ2->number[b][1]= domino.number[melange[i]][1];
				b++;
				
			}
		}
		else
		{
			pioche->number[c][0]= domino.number[melange[i]][0];
			pioche->number[c][1]= domino.number[melange[i]][1];
			c++;
		}
	}
	
}
