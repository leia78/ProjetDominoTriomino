#include "structures.h"

int main (void)
{
	int continuer=1;
	SDL_Surface *ecran=NULL;
	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING); 
	ecran = SDL_SetVideoMode(LECRAN, HECRAN, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	while(continuer)
	{
		SDL_WaitEvent(&event);
		
		switch(event.type) // On teste le type d'événement.
        	{
		    case SDL_QUIT:
			continuer = 0;
			break;
		    default:
			accueil(ecran);
			break;
		}
	}
	
	SDL_Quit();
	
	return 0;
}
