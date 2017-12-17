#include "structures.h"

void accueil(SDL_Surface *ecran)
{
	int continuer=1;
	SDL_Surface *accueil=NULL;
	SDL_Rect posAccueil;
	SDL_Event event;
	
	accueil = SDL_LoadBMP("accueil.bmp");
	
	posAccueil.x = 0;
	posAccueil.y = 0;
	
	
	while(continuer)
	{
		SDL_WaitEvent(&event) ;
		
		switch(event.type)
        {
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					default:
						break;
				}
            
            default:	//affichage de l'écran d'accueil
                SDL_BlitSurface(accueil, NULL, ecran, &posAccueil);
                break;
        }
	
	}
	
	return;
}
