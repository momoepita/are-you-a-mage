#ifndef BINARIZE_H
#define BINARIZE_H

void pause();
Uint32 getpixel(SDL_Surface *surface, int x, int y);
void setPixel(SDL_Surface* dst, int x, int y, size_t r,size_t g,size_t b);
Uint32 getpixel(SDL_Surface *surface, int x, int y);

#endif