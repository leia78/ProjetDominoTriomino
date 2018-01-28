#include "structures.h"

int main (void)
{	
	srand(time(NULL));
	SDL_Surface *ecran=NULL;       
	accueil(ecran);
	SDL_Quit();
	return 0;
}
