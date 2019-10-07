#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void pause();

int main(int argc, char* argv[]) {
    SDL_Surface *ecran = NULL;

    SDL_Init(SDL_INIT_VIDEO);//initialisation de la sdl

    ecran=SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); //initialisation de la fenetre

    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("voici le titre de ma sdl", NULL);

    // Coloration de la surface ecran en bleu-vert
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 206, 255));

    SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */

    pause();
    SDL_Quit();
    return 0;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}