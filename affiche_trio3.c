#include "structures.h"

extern int nbjoueur;
extern  int nb_pion[6];

int affiche_jeu_trio(SDL_Surface *ecran, piece* trioJ1, piece* trioJ2, piece* trioJ3, piece* trioJ4, int Jactuel)
{
	SDL_Event event;
	SDL_Surface *back=NULL, *a=NULL;
	SDL_Rect posAccueil, posJ1,posJ2, posJ3, posJ4, posClic;
	int i,l,k,h, continuer = 1, fin=1 ;
	
	printf("coucou dans laccueil\n");
	a = SDL_LoadBMP("accueil/menu-bg.bmp");
	posAccueil.x = 0;
	posAccueil.y = 0;
	SDL_BlitSurface(a, NULL, ecran, &posAccueil);
	
	posJ1.x=250 ; posJ1.y=700;
	posJ3.x=250 ; posJ3.y=50;
	posJ4.x=50 ; posJ4.y=130;
	
	if(nbjoueur == 2)
	{
		posJ2.x=250 ; posJ2.y=50;
	}
	else
	{
		posJ2.x=1100 ; posJ2.y=130;
	}
	
	affiche_piece(ecran, trioJ1,  trioJ2,  trioJ3,  trioJ4, Jactuel);
	SDL_Flip(ecran);
	
	/*while(continuer)
	{
		SDL_WaitEvent(&event); 
		switch(event.type) 
		{
			case SDL_QUIT : 
			   continuer = 0;
			   break;
		}
	}*/
	
	printf("coucou dans laccueil\n");
	//pause();
	
	return 1;
}

void affiche_piece(SDL_Surface *ecran,piece* trioJ1, piece* trioJ2, piece* trioJ3, piece* trioJ4, int Jactuel)
{
	SDL_Rect posAccueil, posJ1, posJ2, posJ3, posJ4;
	SDL_Surface *pieceJ1=NULL, *pieceJ2=NULL, *pieceJ3=NULL, *pieceJ4=NULL;
	int i;
	
	char nom_fichier[FILENAME_MAX];

	if(nbjoueur == 2)
	{
		if(Jactuel  ==1 )
		{
			printf("le joueur actuel est %d\n",Jactuel);
			afficher_J(ecran,trioJ1,1);
			afficher_cacher(ecran,2,0,0);
			
		}
		else
		{
			printf("le joueur actuel est %d\n",Jactuel);
			afficher_J(ecran,trioJ2,2);
			afficher_cacher(ecran,1,0,0);
		}
	}
	
	else if(nbjoueur == 3)
	{
		if(Jactuel  ==1 )
		{
			afficher_J(ecran,trioJ1,1);
			afficher_cacher(ecran,2,3,0);
			
		}
		else if(Jactuel == 2)
		{
			afficher_J(ecran,trioJ2,2);
			afficher_cacher(ecran,1,3,0);
		}
		else
		{
			afficher_J(ecran,trioJ3,3);
			afficher_cacher(ecran,1,2,0);
		}
	}
	
	else
	{
		if(Jactuel == 1 )
		{
			afficher_J(ecran,trioJ1,1);
			afficher_cacher(ecran,2,3,4);
			
		}
		else if(Jactuel == 2)
		{
			afficher_J(ecran,trioJ2,2);
			afficher_cacher(ecran,1,3,4);
		}
		else if (Jactuel ==3)
		{
			afficher_J(ecran,trioJ3,3);
			afficher_cacher(ecran,1,2,4);
		}
		else
		{
			afficher_J(ecran,trioJ4,4);
			afficher_cacher(ecran,1,2,3);
		}
			
	}
	return ;
}

int clic_joueur(SDL_Rect posClic, SDL_Rect posJ, int Jactuel)
{
	int pion=-1;
	int i,a;
	
	printf("On clique\n");
	printf("x : %d\n y : %d\n",posClic.x,posClic.y);
	
	if(Jactuel==1)
		a=nb_pion[0];
	else if(Jactuel==2)
		a=nb_pion[1];
	else if(Jactuel==2)
		a=nb_pion[2];
	else 
		a=nb_pion[3];
	
	for(i=0;i<a;i++)
	{
		//~ printf("on est dans le for\n");
		if( nbjoueur == 2)
		{
			if((posClic.x >= posJ.x+(i*90))  && (posClic.x <= posJ.x+(i+1)*90 ))
			{
				pion = i;
				
			}
		}
		else if(Jactuel == 2 || Jactuel == 4)
		{
			if((posClic.y >= posJ.y-(i*90))  && (posClic.y <= posJ.y-(i+1)*90 ))
			{
				//~ printf("on est dans le if\n");
				pion = i;
			}
		}
	}
	printf("pion: %d\n", pion);
	return pion;
	
	
}

int clic_joueur2(int Jactuel)
{
	int pion = -1, continuer=1, i; 
	
	SDL_Event event;
	SDL_Rect posJ1,posJ2, posJ3, posJ4, posClic;
	
	posJ1.x=250 ; posJ1.y=700;
	posJ3.x=250 ; posJ3.y=50;
	posJ4.x=50 ; posJ4.y=130;
	
	printf("clic joueur 2\n");
	
	if(nbjoueur == 2)
	{
		posJ2.x=250 ; posJ2.y=50;
	}
	else
	{
		posJ2.x=1100 ; posJ2.y=130;
	}
	
	while(continuer)
	{
		
		SDL_WaitEvent(&event); 
		switch(event.type) 
		{
			case SDL_QUIT: 
			   continuer = 0;
			   break;
			case SDL_MOUSEBUTTONUP:
				continuer=0;
				if(Jactuel == 1)
				{
					//~ printf("nb pion %d\n", nb_pion[0]);
					for(i=0;i<nb_pion[0];i++)
					{
						if (event.button.x>=posJ1.x+(i*90) && event.button.x<=posJ1.x+(i+1)*90 && event.button.y>=posJ1.y && event.button.y<=posJ1.y+75)
						{
							//~ printf("joueur 1 joue\n");
							continuer=0;
							posClic.x = event.button.x;
							posClic.y = event.button.y;
							pion = clic_joueur(posClic, posJ1,Jactuel);
							break;
						}
						
					//posJ1.x = posJ1.x+90;
					}
				}
				else if(Jactuel == 2)
				{
					//~ printf("nb pion %d\n", nb_pion[1]);
					for(i=0;i<nb_pion[1];i++)
					{						
						if(nbjoueur == 2)
						{
							if (event.button.x>=posJ2.x+(i*90) && event.button.x<=posJ2.x+(i+1)*90 && event.button.y>=posJ2.y && event.button.y<=posJ2.y+75)
							{
								//~ printf("joueur 2 joue\n");
								continuer=0;
								posClic.x = event.button.x;
								posClic.y = event.button.y;
								//~ printf("x : %d\n y : %d\n",posClic.x,posClic.y);
								pion = clic_joueur(posClic, posJ2,Jactuel);
								break;
							}
						}
						else
						{
							if (event.button.x>=posJ2.x && event.button.x<=posJ2.x+75 && event.button.y>=posJ2.y+(i*90) && event.button.y<=posJ2.y+(i+1)*90)
							{
								//~ printf("joueur 2 joue\n");
								continuer=0;
								posClic.x = event.button.x;
								posClic.y = event.button.y;
								//~ printf("x : %d\n y : %d\n",posClic.x,posClic.y);
								pion = clic_joueur(posClic, posJ2,Jactuel);
								break;
							}
						}
							//posJ2.y=posJ2.y+90;		
					}					
				}
				else if(Jactuel == 3)
				{
					for(i=0;i<nb_pion[2];i++)
					{
						if (event.button.x>=posJ3.x+(i*90) && event.button.x<=posJ3.x+(i+1)*90 && event.button.y>=posJ3.y && event.button.y<=posJ3.y+75)
						{
							continuer=0;
							posClic.x = event.button.x;
							posClic.y = event.button.y;
							pion = clic_joueur(posClic, posJ3, Jactuel);
							break;
						}
						
						//posJ3.x=posJ3.x+90;
					}
				}
				else
				{
					for(i=0;i<nb_pion[3];i++)
					{
						if (event.button.x>=posJ4.x && event.button.x<=posJ4.x+75 && event.button.y>=posJ4.y-(i*90) && event.button.y<=posJ4.y-(i+1)*90)
						{
							continuer=0;
							posClic.x = event.button.x;
							posClic.y = event.button.y;
							pion = clic_joueur(posClic,posJ4, Jactuel);
							break;
						}
						
					//posJ4.y=posJ4.y+90;
					}
				}
				break;
				
		}
		switch( event.key.keysym.sym )
        {
        	case SDLK_ESCAPE: continuer = 0; break;
        }
	}
	
	return pion;
}



void afficher_cacher(SDL_Surface *ecran, int j, int k, int m)
{
	SDL_Rect posJ1, posJ2, posJ3, posJ4;
	SDL_Surface *pieceJ=NULL;
	posJ1.x=250 ; posJ1.y=700;
	posJ3.x=250 ; posJ3.y=50;
	posJ4.x=50 ; posJ4.y=130;
	int i;
	printf("on entre dans afficher cacher\n");
	
	if(nbjoueur == 2)
	{
		posJ2.x=250 ; posJ2.y=50;
	}
	else
	{
		posJ2.x=1100 ; posJ2.y=130;
	}
	
	
	pieceJ = SDL_LoadBMP("triomino/vide.bmp");
	SDL_SetColorKey(pieceJ, SDL_SRCCOLORKEY, SDL_MapRGB(pieceJ->format, 0, 0, 255));
	
	if(j == 1 || k == 1 || m == 1)
	{
		for(i=0;i<nb_pion[0];i++)
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ1);
			posJ1.x=posJ1.x+90;
		}
	}
	if(j == 2 || k == 2 || m == 2)
	{
		for(i=0;i<nb_pion[1];i++)
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ2);
			
			if(nbjoueur == 2)
				posJ2.x=posJ2.x+90;
			else
				posJ2.y=posJ2.y+90;
		}
	}
	if(j == 3 || k == 3 || m == 3)
	{
		for(i=0;i<nb_pion[2];i++)
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ3);
			posJ3.x=posJ3.x+90;
		}
	}
	if(j == 4 || k == 4 || m == 4)
	{
		for(i=0;i<nb_pion[3];i++)
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ4);
			posJ4.y=posJ4.y+90;
		}
	}
}

void afficher_J(SDL_Surface *ecran, piece *trioJ, int jouer)
{	
	SDL_Rect posJ1, posJ2, posJ3, posJ4;
	SDL_Surface *pieceJ=NULL;
	int i,h,l,m, a;
	char nom_fichier[FILENAME_MAX];
	
	posJ1.x=250 ; posJ1.y=700;
	posJ4.x=50 ; posJ4.y=130;
	
	printf("on entre dans afficher J\n");
	
	if(jouer==1)
		a=nb_pion[0];
	else if(jouer==2)
		a=nb_pion[1];
	else if(jouer==2)
		a=nb_pion[2];
	else 
		a=nb_pion[3];
	
	if(nbjoueur == 2)
	{
		posJ2.x=250 ; posJ2.y=50;
	}
	else
	{
		posJ2.x=1100 ; posJ2.y=130;
		posJ3.x=250 ; posJ3.y=50;
	}

	for(i=0;i<a;i++)
	{
		h = trioJ[i].number[0];
		l = trioJ[i].number[2];
		m = trioJ[i].number[3];	
		sprintf(nom_fichier, "triomino/%d_%d_%d.bmp",h,l,m);
		pieceJ = SDL_LoadBMP(nom_fichier);
		SDL_SetColorKey(pieceJ, SDL_SRCCOLORKEY, SDL_MapRGB(pieceJ->format, 0, 0, 255));
		
		if(jouer == 1)
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ1);
			posJ1.x=posJ1.x+90;
		}
		else if(jouer == 2)
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ2);
			if(nbjoueur == 2)
				posJ2.x=posJ2.x+90;
			else
			{
				posJ2.y=posJ2.y+90;
			}
		}
		else if(jouer == 3)
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ3);
			posJ3.x=posJ3.x+90;
		}
		else
		{
			SDL_BlitSurface(pieceJ, NULL, ecran, &posJ4);
			posJ4.y=posJ4.y+90;
		}
			
	}
	
	printf("on sort de afficher J\n");
}

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
