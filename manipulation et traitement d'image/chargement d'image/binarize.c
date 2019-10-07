#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "binarize.h"

int main()
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;

    positionFond.x = 0;
    positionFond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    /* Chargement de l'icône AVANT SDL_SetVideoMode en 16*16 */
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);
    //use IMG_Load to load any image format
    //use SDL_LoadBMP for a bmp

    ecran = SDL_SetVideoMode(500, 400, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = SDL_LoadBMP("image4.bmp");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    grayscale(ecran,500,400);

    SDL_Flip(ecran);

    pause();

    SDL_FreeSurface(imageDeFond); /* On libère la surface */
    SDL_Quit();

    return EXIT_SUCCESS;
}

void grayscale(SDL_Surface *surface, size_t height,size_t width){
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            Uint8 R=0;
            Uint8 G=0;
            Uint8 B=0;
            SDL_GetRGB(getpixel(surface,i,j),surface->format,&R,&G,&B);
            //n'arrondi pas à l'entier supérieur(à modifier dans le pire des cas)
            Uint8 gray=0.2125 * R + 0.7154 * G + 0.0721 * B;

            //je laisse ça ici pour une nuance de noire et de blanc
            /*if(gray>255/2){
                gray=255;
            }
            else{
                gray=0;
            }*/
            setPixel(surface,i,j,gray,gray,gray);
        }

    }
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
void setPixel(SDL_Surface* dst, int x, int y, size_t r,size_t g,size_t b)
{
    Uint32 color = (Uint32)((r << 16) + (g << 8) + (b << 0));
    *((Uint32*)(dst->pixels) + x + y * dst->w) = color;
}
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    //int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;  // 4=bpp

    return *(Uint32 *)p;
}