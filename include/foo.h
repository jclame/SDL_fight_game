#ifndef FOO_H_INCLUDED
#define FOO_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL_extern.h"
#include "global.h"

class Foo
{
public:

    //Initializes the variables
    Foo(int intit_set, int person);

    // get the frame
    int get_frame(){ return attack_frame; };

    //get the offset
    int get_offset(){ return offSet; };

    //Handles input
    void handle_events();

    //Moves the stick figure
    void move(int collis_test);

    //Shows the stick figure
    void show(SDL_Surface* image, SDL_Rect *clipsR, SDL_Rect *clipsL);

    // Attack
    int attack(SDL_Surface* image, SDL_Rect *clips_ATK);

    void show_hp();

    void check_col( int atk, int collision_offset );

    int get_atk(){return atk_status;};

    bool lose();

private:

    //The offset
    int offSet;

    //Its rate of movement
    int velocity;

    //Its current attack frame
    int frame;

    int attack_frame;

    // the person mark
    int person_mark;

    // the attack status
    int atk_status;

    //Its animation status
    int status;

    int HP;
};

#endif // FOO_H_INCLUDED
