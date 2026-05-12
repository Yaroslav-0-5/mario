#include <SDL2/SDL_image.h>

#include "file.h"


/*permet de charger une image dans une SDL_Texture avec l'option SDL_TEXTUREACCESS_TARGET
pour pouvoir modifier la texture après. */
SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer) //NE PAS MODIFIER CETTE FONCTION
{
    SDL_Surface *surface = NULL; 
    SDL_Texture *tmp = NULL, *texture = NULL;
    surface = IMG_Load(path);
    if(NULL == surface)
    {
        fprintf(stderr, "Erreur IMG_Load : %s", SDL_GetError());
        return NULL;
    }
    tmp = SDL_CreateTextureFromSurface(renderer, surface);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                            SDL_TEXTUREACCESS_TARGET, surface->w, surface->h); 
    if(texture == NULL) 
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    SDL_SetRenderTarget(renderer, texture); /* La cible de rendu est maintenant texture. */
    SDL_SetTextureBlendMode(tmp, SDL_BLENDMODE_NONE); /* gère la transparence du fond des images*/
    SDL_RenderCopy(renderer, tmp, NULL, NULL); /* On copie tmp sur texture */
    SDL_DestroyTexture(tmp); //nettoyage
    SDL_FreeSurface(surface); //nettoyage
    SDL_SetRenderTarget(renderer, NULL); /* La cible de rendu est de nouveau le renderer. */
    return texture;
}

Sprites* chargerImages(SDL_Renderer *renderer) {
    Sprites* sprites;
    
    sprites = malloc(NbSprites * sizeof(Sprites));
    sprites[0].sprite = loadImage("img/sky.png", renderer);
    sprites[0].traverser = 0;
    sprites[1].sprite = loadImage("img/sol.png", renderer);
    sprites[1].traverser = 1;
    sprites[2].sprite = loadImage("img/block.png", renderer); 
    sprites[2].traverser = 1;
    sprites[3].sprite = loadImage("img/boite.png", renderer);
    sprites[3].traverser = 1;
    sprites[4].sprite = loadImage("img/tuyau1.png", renderer);
    sprites[4].traverser = 1;
    sprites[5].sprite = loadImage("img/tuyau2.png", renderer);
    sprites[5].traverser = 1;
    sprites[6].sprite = loadImage("img/tuyau3.png", renderer);
    sprites[6].traverser = 1;
    sprites[7].sprite = loadImage("img/tuyau4.png", renderer);
    sprites[7].traverser = 1;
    sprites[8].sprite = loadImage("img/fin1.png", renderer);
    sprites[8].traverser = 0;
    sprites[9].sprite = loadImage("img/fin2.png", renderer);
    sprites[9].traverser = 0;


    /*int goomba[] = malloc(3 * sizeof(SDL_Texture *));
    if (goomba == NULL) {
        printf("Erreur malloc\n");
        exit(EXIT_FAILURE);
    }
    goomba[0] = loadImage("img/goomba1.png", renderer );
    goomba[1] = loadImage("img/goomba.png", renderer );
    goomba[2] = loadImage("img/goomba.png", renderer );*/
	
    return sprites;
}

Map* ChargerMap(char* level)
{
    Map* map = malloc(sizeof(Map));
	FILE*fichier = fopen("level/niveau0.lvl", "r");
    if(fichier == NULL){
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    char ligne[256];
    int buffer1, buffer2;

    // Ignorer la première ligne "niveau 0"
    fgets(ligne, sizeof(ligne), fichier);

    // Lire la deuxième ligne "30 30"
    fscanf(fichier, "%d %d", &buffer1, &buffer2);

    map -> width = buffer1;
    map -> height = buffer2;

    map -> LoadedMap = malloc(buffer2 * sizeof(int*));
    for (int i = 0; i < buffer2; i++) {
        map -> LoadedMap[i] = malloc(buffer1 * sizeof(int));
    }

    for(int i = 0; i < buffer2; i++) {
        for(int j = 0; j < buffer1; j++) {
            fscanf(fichier, "%d", &(map ->LoadedMap[i][j]));
        }
    }



    fclose(fichier);
    return map;
}


void afficherMap(Map* map, Sprites* sprites, SDL_Renderer *renderer) {
    SDL_Rect src1 = {0, 0, 33, 33};
    for(int i = 0; i < map -> height; i++) {
        for(int j = 0; j < map -> width; j++) { 
            SDL_RenderCopy ( renderer , sprites[map -> LoadedMap[i][j]].sprite , NULL , &src1 ); //affiche le ciel
            src1.x = src1.x + 33 ; //on décale la position de src1 pour faire le déplacement de la map
            }
            src1.x = 0 ; //on remet la position de src1 à 0 pour faire le déplacement de la map
            src1.y = src1.y + 33 ;
        }
}

void LibererMap(Map* map, Sprites* sprites)
{
  
}