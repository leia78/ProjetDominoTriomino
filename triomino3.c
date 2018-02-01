#include "structures.h"

extern int nbjoueur;
int nb_pion[6] = {0,0,0,0,0,0};


void init_triomino(SDL_Surface *ecran)
{
	SDL_Event event;
	piece* trio = NULL, *trioPla = NULL;
	piece *trioJ1 = NULL, *trioJ2 = NULL, *trioJ3 = NULL, *trioJ4 = NULL, *trioP = NULL;
	piece *jJoue;
	int i,j, score=0;
	int win=0, fin =1, pion;
	int jCommence, somme, resultat=0;
	int j1=0, j2=0, j3=0, j4=0;
	
	srand(time(NULL));
	//Initialisation du jeu
	alloc_jeu(&trio);
	alloc_jeu(&trioPla);
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
	init_trioP(&trioPla);
	
	
	distribution(&trio, &trioJ1,  &trioJ2,  &trioJ3,  &trioJ4, &trioP);

	//Choix du joueur qui commence : celui qui a la somme la plus grande quand il prend un trio de la pioche
	for(i=0;i<nbjoueur;i++)
	{
		somme = calc_score(trioP, i);
		if( resultat<somme)
		{
			resultat = somme;
			jCommence = i+1;
		}
	}
	
		
	
	
	while(fin)
	{
		SDL_WaitEvent(&event); 
    	switch(event.type) 
    	{
        	case SDL_QUIT : 
           			fin = 0;
           			break;
           			
           	default:
			{	
				//debut du jeu 
				//1er tour: 
				renomme_joueur(&jJoue, jCommence, trioJ1, trioJ2, trioJ3, trioJ4, &score, &j1, &j2, &j3, &j4);
				
				fin = affiche_jeu_trio(ecran, trioJ1, trioJ2, trioJ3, trioJ4,jCommence); //affiche jeu
				pion=-1;
				do{
					pion = clic_joueur2(jCommence); //récupération de l'indice du triomino cliqué par le joueur
				}while(pion==-1);
				
				score = calc_score(jJoue, pion);
				for(i=0;i<4;i++)
				{
					trioPla[0].number[i]=jJoue[pion].number[i]; //Place les données du trio posé dans les données des trio du plateau
					jJoue[pion].number[i] = 8; //suppression du trio des données du joueurs
				}
				decalage_trio(&jJoue, (jCommence-1), pion); //declalage des données pour quels correspondent avec l'affichage
				
				nb_pion[(jCommence-1)]--; 
					
				//joueur suivant
				if( (nbjoueur==2 && jCommence==2) || (nbjoueur==3 && jCommence==3) || (nbjoueur==4 && jCommence==4) )
				{
					jCommence=1;
				}
				else
				{ 
					jCommence++;
				}
				
				
				break;
			}
		}

    }
	
	

		
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


void distribution_2J(piece** trio, piece** trioJ1, piece** trioJ2, piece** trioP)
{
	int a=0,i,b=0,e=0, melange[56];
	hasard(melange);
	i=0;
	do
	{
		if(i%2==0)	//on remplit le jeu du premier joueur
		{
			(*trioJ1)[a].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ1)[a].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ1)[a].number[3]= (*trio)[melange[i]].number[3];
			a++;
			nb_pion[0]++;
		}
		else if(i%2==1)	//on remplit le jeu du deuxième joueur
		{
			(*trioJ2)[b].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ2)[b].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ2)[b].number[3]= (*trio)[melange[i]].number[3];
			b++;
			nb_pion[1]++;
		}
		i++;
	} while((a<9)||(b<9));
	
	for(i=i;i<56;i++)	//on remplit la pioche
	{
		(*trioP)[e].number[0]= (*trio)[melange[i]].number[0];
		(*trioP)[e].number[2]= (*trio)[melange[i]].number[2];
		(*trioP)[e].number[3]= (*trio)[melange[i]].number[3];
		e++;
		nb_pion[4]++;
	}
	
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
			nb_pion[0]++;
		}
		else if(i%4==1)
		{
			(*trioJ2)[b].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ2)[b].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ2)[b].number[3]= (*trio)[melange[i]].number[3];
			b++;
			nb_pion[1]++;
		}
		else if(i%4==2)
		{
			(*trioJ3)[c].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ3)[c].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ3)[c].number[3]= (*trio)[melange[i]].number[3];
			c++;
			nb_pion[2]++;
		}
		else if(i%4==3 && nbjoueur==4)
		{
			(*trioJ4)[d].number[0]= (*trio)[melange[i]].number[0];
			(*trioJ4)[d].number[2]= (*trio)[melange[i]].number[2];
			(*trioJ4)[d].number[3]= (*trio)[melange[i]].number[3];
			d++;
			nb_pion[3]++;
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
		nb_pion[4]++;
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

void init_trioP( piece** trio)
{
	int i,j;
	
	for(i=0;i<56;i++)
	{
		for(j=0;j<4;j++)
		{
			(*trio)[i].number[j] = 8;
		}
	}
}

void decalage_trio(piece** trio, int num, int pion)
{
	int i, j, a;
	for(i=pion; i<nb_pion[num];i++)
	{
		a=i+1;
		for(j=0;j<4;j++)
		{
			(*trio)[i].number[j] = (*trio)[a].number[j];
		}
	}
}
