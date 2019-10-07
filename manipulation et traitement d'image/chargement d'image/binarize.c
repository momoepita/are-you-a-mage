#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "binarize.h"

void grayscale(SDL_Surface *surface, size_t height,size_t width){
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Uint8 R=0;
            Uint8 G=0;
            Uint8 B=0;
            SDL_GetRGB(getpixel(surface,i,j),ecran->format,&R,&G,&B);
            //n'arrondi pas à l'entier supérieur(à modifier dans le pire des cas)
            Uint8 gray=0.2125 * R + 0.7154 * G + 0.0721 * B;
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