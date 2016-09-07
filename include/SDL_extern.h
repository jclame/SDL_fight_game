#ifndef SDL_EXTERN_H_INCLUDED
#define SDL_EXTERN_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include "global.h"

SDL_Surface *load_image( std::string filename );

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);


#endif // SDL_EXTERN_H_INCLUDED
