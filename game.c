
#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer* renderer) {
    Personnage mario;
    Personnage mob;
    Map map;

    chargerMario(&mario, &map, renderer);
    chargerMob(&mob,&map,renderer);
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
			case SDL_KEYDOWN : // on a appuye sur une touche
            switch ( events . key . keysym . sym ) // liste des touches a p p u y
            {
            case SDLK_RIGHT:
                mario.direction = 1;
                break;

            case SDLK_LEFT:
                mario.direction = 2;
                break;
            case SDLK_UP:
                if(mario.jump == 2){
                    break;
                }
                mario.jump = 1;
                break;
            }            
            break;
            case SDL_KEYUP :
            switch ( events . key . keysym . sym )
            {
            case SDLK_RIGHT :
                mario.dernieredirection = 1;
                mario.direction = 0;
                break;
            case SDLK_LEFT:
                mario.dernieredirection = 2;
                mario.direction = 0;
                break;
            }
            break ;
            }


            

        }
        
		//on gère les divers events.
        
        deplacement(&map,&mario,0,&mob,0);
		afficherPerso(&mario, 0, 0, renderer);
<<<<<<< HEAD
        afficherMap(map2, sprites, renderer); //affiche la map
=======
        afficherMob(&mob,0,0,renderer);
>>>>>>> eaead4570adccb9b0e38d3764d75f6f6b9eeae03
        SDL_RenderPresent(renderer); // affiche le tout
        
    }
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    //LibererMap(map, sprites);
    //freePersonnage(mario, goomba, nbGoomba);
    freePersonnage(&mario);

    return continuer;
}