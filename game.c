
#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer* renderer) {
    Personnage mario;
    Map map;

    chargerMario(&mario, &map, renderer);
	//charger image et personnage. 
    Map* map2 = ChargerMap("level/niveau0.lvl"); //charge la map dans le jeu
    Sprites* sprites = chargerImages(renderer); //charge les images dans le jeu
    
    
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //on met le fond en blanc
    int continuer = 1;
    SDL_Event events;

    while(continuer){ //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
        SDL_RenderClear(renderer); //efface le rendu précédent
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
				
            }
        }
        
		//on gère les divers events.
		afficherPerso(&mario, 0, 0, renderer);
        afficherMap(map2, sprites, renderer); //affiche la map
        SDL_RenderPresent(renderer); // affiche le tout
        
    }
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    //LibererMap(map, sprites);
    //freePersonnage(mario, goomba, nbGoomba);


    return continuer;
}