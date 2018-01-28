#include<SDL.h>
#include"structures.h"
int nbjoueur=0,type=0;
piece *pj1=NULL,*pj2=NULL,*pj3=NULL,*pj4=NULL,*pord=NULL,*p=NULL;
piece * init_piece(int type){
	piece *p;
	int i,j,s=sizeof(piece),d=0,a=0, b=0;	
	p = (piece*) malloc (28*sizeof(piece));

	for(i=0;i<28;i++)
	{
			p[i].number = (int*) malloc (2*sizeof(int));
	}


	for(i=0;i<28;i++)
	{
		for(j=0;j<2;j++)
		{
			if(j==0)
			{
				p[i].number[j] = a;
			}
			else
			{
				p[i].number[j] = b;
				b++;
			}
			if(b==7)
			{
				a++;
				b=a;
			}
		}	
	}
	/*for(i=0;i<28;i++)
	{
		printf("%d\t%d\n",p[i].number[0],p[i].number[1]);
	}*/
return p;
}

// Fonction qui permet à accédé aux jeux tremino ou domino
void jeu(SDL_Surface *ecran){
SDL_Event event;
int continuer=1;
SDL_Surface  *a=NULL,*bd=NULL,*bt=NULL,*bj=NULL,*bq=NULL;
SDL_Rect posBdomino,posBtremino, posAccueil,posBjouer,posBquitter;
	a = SDL_LoadBMP("accueil/menu-bg.bmp");
	bd=SDL_LoadBMP("accueil/button_dominos.bmp");
	bt=SDL_LoadBMP("accueil/button_triominos.bmp");
	posAccueil.x = 0;
	posAccueil.y = 0;
	posBdomino.x=471;
	posBdomino.y=315;
	posBtremino.x=471;
	posBtremino.y=415;
	ecran = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE);
        SDL_BlitSurface(a, NULL, ecran, &posAccueil);
	SDL_BlitSurface(bd,NULL,ecran,&posBdomino);
	SDL_BlitSurface(bt,NULL,ecran,&posBtremino);
	SDL_Flip(ecran);
while (continuer)
	{
    		SDL_WaitEvent(&event); 
    		switch(event.type) 
    		{
        		case SDL_QUIT : 
            		continuer = 0;
            		break;
			case SDL_MOUSEBUTTONUP:

			if (event.button.x>=posBdomino.x && event.button.x<=posBdomino.x+278 && event.button.y>=posBdomino.y && event.button.y<=posBdomino.y+80)
			{
				continuer=0;nb_joueur(ecran);break;
			}
			else if (event.button.x>=posBtremino.x && event.button.x<=posBtremino.x+278 && event.button.y>=posBtremino.y && event.button.y<=posBtremino.y+80)
			{
				continuer=0;nb_joueur(ecran);
			}
    		}
		switch( event.key.keysym.sym )
        	{
        	case SDLK_ESCAPE: continuer = 0; break;
        	}
	}
}
void accueil(SDL_Surface *ecran)
{
	SDL_Event event;
	int continuer=1;
	SDL_Surface  *a=NULL,*bd=NULL,*bt=NULL,*bj=NULL,*bq=NULL,*bh=NULL,*bs=NULL;
	SDL_Rect posBdomino,posBtremino, posAccueil,posBjouer,posBquitter,posBhelp,posBstat;
	a = SDL_LoadBMP("accueil/menu-bg.bmp");
	bj=SDL_LoadBMP("accueil/button_jouer.bmp");
	bq=SDL_LoadBMP("accueil/button_quitter.bmp");
	bh=SDL_LoadBMP("accueil/button_help.bmp");
	bs=SDL_LoadBMP("accueil/button_stat.bmp");
	if(!a){
		printf("Erreur de chargement de l'image : %s",SDL_GetError());   
	}
	
	posAccueil.x = 0; posAccueil.y = 0;
	posBjouer.x=471; posBjouer.y=280;
	posBquitter.x=471; posBquitter.y=380;
	posBhelp.x=471; posBhelp.y=480;
	posBstat.x=611; posBstat.y=480;
	
	ecran = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE);
        
	SDL_BlitSurface(a, NULL, ecran, &posAccueil);
	SDL_BlitSurface(bj,NULL,ecran,&posBjouer);
	SDL_BlitSurface(bq,NULL,ecran,&posBquitter);
	SDL_BlitSurface(bh,NULL,ecran,&posBstat);
	SDL_BlitSurface(bs,NULL,ecran,&posBhelp);
	SDL_Flip(ecran);
	
	while (continuer)
	{
    		SDL_WaitEvent(&event); 
    		switch(event.type) 
    		{
        		case SDL_QUIT : 
            		continuer = 0;
            		break;
			case SDL_MOUSEBUTTONUP:

			if (event.button.x>=posBquitter.x && event.button.x<=posBquitter.x+278 && event.button.y>=posBquitter.y && event.button.y<=posBquitter.y+80)
			{
				continuer=0;break;
			}
			else if (event.button.x>=posBjouer.x && event.button.x<=posBjouer.x+278 && event.button.y>=posBjouer.y && event.button.y<=posBjouer.y+80)
			{
				continuer=0;jeu(ecran);
			}
    		}
		switch( event.key.keysym.sym )
        	{
        	case SDLK_ESCAPE: continuer = 0; break;
        	}
	}
}
void nb_joueur(SDL_Surface *ecran){
	SDL_Event event;
	int continuer=1;
	SDL_Surface  *a=NULL,*bj1=NULL,*bj2=NULL,*bj3=NULL,*bj4=NULL;
	SDL_Rect posB1joueur,posB2joueur, posAccueil,posB3joueur,posB4joueur,posBhelp,posBstat;
	a = SDL_LoadBMP("accueil/menu-bg.bmp");
	bj1=SDL_LoadBMP("accueil/button_1joueur.bmp");
	bj2=SDL_LoadBMP("accueil/button_2joueurs.bmp");
	bj3=SDL_LoadBMP("accueil/button_3joueurs.bmp");
	bj4=SDL_LoadBMP("accueil/button_4joueurs.bmp");
	posAccueil.x = 0; posAccueil.y = 0;
	posB1joueur.x=471; posB1joueur.y=280;
	posB2joueur.x=471; posB2joueur.y=365;
	posB3joueur.x=471; posB3joueur.y=450;
	posB4joueur.x=471; posB4joueur.y=535;
	
	ecran = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE);
        
	SDL_BlitSurface(a, NULL, ecran, &posAccueil);
	SDL_BlitSurface(bj1,NULL,ecran,&posB1joueur);
	SDL_BlitSurface(bj2,NULL,ecran,&posB2joueur);
	SDL_BlitSurface(bj3,NULL,ecran,&posB3joueur);
	SDL_BlitSurface(bj4,NULL,ecran,&posB4joueur);
	SDL_Flip(ecran);
while (continuer)
	{
    		SDL_WaitEvent(&event); 
    		switch(event.type) 
    		{
        		case SDL_QUIT : 
            		continuer = 0;
            		break;
			case SDL_MOUSEBUTTONUP:

			if (event.button.x>=posB1joueur.x && event.button.x<=posB1joueur.x+278 && event.button.y>=posB1joueur.y && event.button.y<=posB1joueur.y+80)
			{
				continuer=0;break;
			}
			else if (event.button.x>=posB2joueur.x && event.button.x<=posB2joueur.x+278 && event.button.y>=posB2joueur.y && event.button.y<=posB2joueur.y+80)
			{
				continuer=0;p=init_piece(2);nbjoueur=1;board_d(ecran);
			}
    		}
		switch( event.key.keysym.sym )
        	{
        	case SDLK_ESCAPE: continuer = 0; break;
        	}
	}

}
void board_d(SDL_Surface *ecran){
	SDL_Event event;
	int continuer=1,i;
	SDL_Surface  *a=NULL,*b=NULL;
	SDL_Rect  posAccueil,posBoard;
	a = SDL_LoadBMP("accueil/menu-bg.bmp");
	b=SDL_LoadBMP("accueil/board.bmp");
	posBoard.x=200;posBoard.y=150;

	posAccueil.x = 0; posAccueil.y = 0;
	SDL_BlitSurface(a, NULL, ecran, &posAccueil);
	SDL_BlitSurface(b, NULL, ecran, &posBoard);
	SDL_Flip(ecran);
	melange(nbjoueur,p);
	for(i=0;i<7;i++)
	{
		printf("%d\t%d\n",pj1[i].number[0],pj1[i].number[1]);
		printf("%d\t%d\n",pord[i].number[0],pord[i].number[1]);
	}
while (continuer)
	{
    		SDL_WaitEvent(&event); 
    		switch(event.type) 
    		{
        		case SDL_QUIT : 
            		continuer = 0;
            		break;
			/*case SDL_MOUSEBUTTONUP:

			if (event.button.x>=posBquitter.x && event.button.x<=posBquitter.x+278 && event.button.y>=posBquitter.y && event.button.y<=posBquitter.y+80)
			{
				continuer=0;break;
			}
			else if (event.button.x>=posBjouer.x && event.button.x<=posBjouer.x+278 && event.button.y>=posBjouer.y && event.button.y<=posBjouer.y+80)
			{
				continuer=0;jeu(ecran);init_piece(2);
			}*/
    		}
		switch( event.key.keysym.sym )
        	{
        	case SDLK_ESCAPE: continuer = 0; break;
        	}
	}
}
void melange(int nbjoueur,piece *p){
	int i,b;
	piece *p1=NULL;
	p1= (piece*) malloc (28*sizeof(piece));
	for(i=0;i<28;i++)
		{
			b =rand()%28;
			p1[i]= p[b];
			
		}
	if(nbjoueur=1)
		{
			pj1=(piece*) malloc(7*sizeof(piece));
			pord=(piece*) malloc(7*sizeof(piece));
			for(i=0;i<7;i++)
			{
				pj1[i]=p1[i];
				pord[i]=p1[i+7];
			}				
		}


}
		

