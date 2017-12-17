#include "structures.h"

int main (void)
{
	int continuer=1;
	SDL_Surface *ecran=NULL;
	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING); 
	
	while(continuer)
	{
		SDL_WaitEvent(&event);
		
		switch(event.type) // On teste le type d'événement.
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            default:
                ecran = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                accueil(ecran);
                break;
        }
	}
	
	SDL_Quit();
	
	return 0;
}
