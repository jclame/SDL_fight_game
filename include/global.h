#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

//The screen set
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_BPP;

//The frames per second
extern const int FRAMES_PER_SECOND;

//The dimenstions of the stick figure
extern const int FOO_WIDTH;
extern const int FOO_HEIGHT;

// the person status
extern const int PERSON_L;
extern const int PERSON_R;

//The direction status of the stick figure
extern const int FOO_RIGHT;
extern const int FOO_LEFT;

// The attack status of the person
extern const int ATK_ON;
extern const int ATK_OFF;

// The HP decline of every attack
extern const int HP_DEC;

//The surfaces
// The person on the left
extern SDL_Surface *person_L;

// The person on the right
extern SDL_Surface *person_R;

extern SDL_Surface *screen;

// the background
extern SDL_Surface *background;

extern SDL_Surface *L_win;

extern SDL_Surface *R_win;

extern SDL_Surface *blood;


//The event structure
extern SDL_Event event;


#endif // GLOBAL_H_INCLUDED
