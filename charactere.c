#include <stdlib.h>
#include <stdio.h>
#include "charactere.h"


void chargerMario(Personnage* mario, Map* map, SDL_Renderer *renderer)
{
    //Images
    mario->image = malloc(NUMBER_IMAGE_MARIO * sizeof(SDL_Texture *));
    if (mario->image == NULL) {
        printf("Erreur malloc\n");
        exit(EXIT_FAILURE);
    }
    mario->image[0] = loadImage("img/Mario1.png", renderer );
    mario->image[1] = loadImage("img/Mario2.png", renderer );
    mario->image[2] = loadImage("img/Mario3.png", renderer );
    mario->image[3] = loadImage("img/Mario4.png", renderer );
    mario->image[4] = loadImage("img/Mario5.png", renderer );
    mario->image[5] = loadImage("img/Mario6.png", renderer );
    //Position
    mario->position.x = 0;
    mario->position.y = 885;
    mario->position.w = WIDTH_MARIO;
    mario->position.h = HEIGHT_MARIO;
    //Compteurs
    mario->jump = 0;
    mario->jumptime = 0;
    mario->gravite = 0;
    mario->direction = 0;
    mario->dernieredirection = 1;
    mario->temp = 0;
    mario->win = 0;
    mario->invisible = 0;
    mario->lvl = 1;
    mario->lvlperdu = 0;


    
    /*chargerMario : consiste à initialiser Mario(voir charactère.h), il faudra définir
    la valeur jump, jump time, etc..., ainsi que créer un malloc de pointeur pour pouvoir charger
    toutes les images de mario en mm temps, et enfin en fonction des touches appuyées/position de mario changer 
    son image*/
}
void chargerMob(Personnage* mob, Map* map, SDL_Renderer *renderer)
{
    //Images
    mob->image = malloc(NUMBER_IMAGE_MOB * sizeof(SDL_Texture *));
    if (mob->image == NULL) {
        printf("Erreur malloc\n");
        exit(EXIT_FAILURE);
    }
    mob->image[0] = loadImage("img/goomba1.png", renderer );
    mob->image[1] = loadImage("img/goomba2.png", renderer );
    mob->image[2] = loadImage("img/goomba3.png", renderer );
    //Position
    mob->position.x = 600;
    mob->position.y = 885;
    mob->position.w = WIDTH_MARIO;
    mob->position.h = HEIGHT_MARIO;
    //Compteurs
    mob->jump = 0;
    mob->jumptime = 0;
    mob->gravite = 0;
    mob->direction = 0;
    mob->dernieredirection = 1;
    mob->temp = 0;
    mob->win = 0;
    mob->invisible = 0;
    mob->lvl = 1;
    mob->lvlperdu = 0;


    
    /*chargerMario : consiste à initialiser Mario(voir charactère.h), il faudra définir
    la valeur jump, jump time, etc..., ainsi que créer un malloc de pointeur pour pouvoir charger
    toutes les images de mario en mm temps, et enfin en fonction des touches appuyées/position de mario changer 
    son image*/
}

void afficherPerso(Personnage* mario, int xscroll, int yscroll , SDL_Renderer *renderer) {
    if(mario->direction == 0){
        if(mario->dernieredirection==1){
            SDL_RenderCopy(renderer, mario->image[0], NULL,&mario->position);
        }
        if(mario->dernieredirection==2){
            SDL_RenderCopy(renderer, mario->image[3], NULL,&mario->position);
        }

    }
    if(mario->direction == 1){
        SDL_RenderCopy(renderer, mario->image[chooseSpriteMovement(mario,0,1)], NULL,&mario->position);
    }   
    if(mario->direction == 2){
        SDL_RenderCopy(renderer, mario->image[chooseSpriteMovement(mario, 3,4)], NULL,&mario->position);
    }  
    if(mario->jump == 1){
        if(mario->direction == 0){
        if(mario->dernieredirection==1){
            SDL_RenderCopy(renderer, mario->image[2], NULL,&mario->position);
        }
        if(mario->dernieredirection==2){
            SDL_RenderCopy(renderer, mario->image[5], NULL,&mario->position);
        }
    }
        if(mario->direction == 1){
        SDL_RenderCopy(renderer, mario->image[2], NULL,&mario->position);
        }   
        if(mario->direction == 2){
            SDL_RenderCopy(renderer, mario->image[5], NULL,&mario->position);
        }  /*Mettre les images, jump time ce regle dans event.c*/
    }
}
void afficherMob(Personnage* mob, int xscroll, int yscroll , SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, mob->image[chooseSpriteMovement(mob,0,1)], NULL,&mob->position);
}


//retourne soit numéro1 soit numéro2 pour alterner entre 2 sprite sur un mouvement.
int chooseSpriteMovement(Personnage* mario, int numero1, int numero2) {
    (mario->temp)++;
    if (mario->temp>120){
        mario->temp = 0;
    }
    if(mario->temp<60){
        return numero2;
    } else{
        
        return numero1;
    }  
}

void freePersonnage(Personnage* mario/*, Personnage **goomba, int nbGoomba*/) {
    for (int i = 0; i < NUMBER_IMAGE_MARIO; i++) {
        SDL_DestroyTexture(mario->image[i]);
    }
    free(mario->image);
}