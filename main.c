#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"


//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2

int main(){
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        fprintf(stderr,"error%s",SDL_GetError());
        exit(0);
    }
    SDL_Window* window =  SDL_CreateWindow("Mario",
                                   0,
                                   0,
                                   LARGEUR_FENETRE,
                                   HAUTEUR_FENETRE,
                                   SDL_WINDOW_SHOWN);
   SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   SDL_Texture * textureMenu = loadImage("img/menu.jpg", renderer );
   SDL_Rect src1 = {0 , 0 , 40 , 40};
   SDL_Rect dst1 = { 0 , 0 , 40 , 40 };
   SDL_RenderClear ( renderer );
   SDL_RenderCopy ( renderer , textureMenu , NULL , NULL );
   SDL_RenderPresent ( renderer );
   SDL_Event events ;
int continuer = 1;
while ( continuer ){
    while ( SDL_PollEvent (& events ))
    {
    switch ( events . type )
        {
        case SDL_QUIT :
        // on a clique sur la croix de la fenetre
        continuer = 0;
        // continuer passe a 0 , la boucle se termine
        break ;
        case SDL_KEYDOWN : // on a appuye sur une touche
        switch ( events . key . keysym . sym ) // liste des touches a p p u y
        {
        case SDLK_1 :
        // on a appuye sur la touche 1
        jouer(renderer);
        }
        break ;
        case SDL_KEYUP :
        switch ( events . key . keysym . sym )
        {
        case SDLK_1 :
        // on a relache la touche 1
        }
            break ;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
