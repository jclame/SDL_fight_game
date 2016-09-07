/****************************************************************************
 *
 *   Copyright (c) 2015-2016 jclame. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Timer.h"
#include <string>

#include "global.h"
#include "Foo.h"

SDL_Surface *person_L;

// The person on the right
SDL_Surface *person_R;

SDL_Surface *screen;

// the background
SDL_Surface *background;

SDL_Surface *L_win;

SDL_Surface *R_win;

SDL_Surface *blood;

//The event structure
SDL_Event event;

//The areas of the sprite sheet of the person on the left
//walk right
SDL_Rect L_Right[ 8 ];
//walk left
SDL_Rect L_Left[ 8 ];
// the attack sprite
SDL_Rect L_Attack[ 13 ];
// the head photo
SDL_Rect L_Head;

// The areas of the sprite sheet of the person on the right
//walk right
SDL_Rect R_Right[ 8 ];
//walk left
SDL_Rect R_Left[ 8 ];
// the attack sprite
SDL_Rect R_Attack[ 13 ];
// the head photo
SDL_Rect R_Head;

void set_clips()
{
    //Clip the sprites
    L_Head.x = 0;
    L_Head.y = 0;
    L_Head.w = 120;
    L_Head.h = 54;

    L_Right[ 0 ].x = 5;
    L_Right[ 0 ].y = 345;
    L_Right[ 0 ].w = FOO_WIDTH;
    L_Right[ 0 ].h = FOO_HEIGHT;

    L_Right[ 1 ].x = 5+FOO_WIDTH;
    L_Right[ 1 ].y = 345;
    L_Right[ 1 ].w = FOO_WIDTH;
    L_Right[ 1 ].h = FOO_HEIGHT;

    L_Right[ 2 ].x = 5+FOO_WIDTH * 2;
    L_Right[ 2 ].y = 345;
    L_Right[ 2 ].w = FOO_WIDTH;
    L_Right[ 2 ].h = FOO_HEIGHT;

    L_Right[ 3 ].x = 5+FOO_WIDTH * 3;
    L_Right[ 3 ].y = 345;
    L_Right[ 3 ].w = FOO_WIDTH;
    L_Right[ 3 ].h = FOO_HEIGHT;

    L_Right[ 4 ].x = 5+FOO_WIDTH * 4;
    L_Right[ 4 ].y = 345;
    L_Right[ 4 ].w = FOO_WIDTH;
    L_Right[ 4 ].h = FOO_HEIGHT;

    L_Right[ 5 ].x = 5+FOO_WIDTH * 5;
    L_Right[ 5 ].y = 345;
    L_Right[ 5 ].w = FOO_WIDTH;
    L_Right[ 5 ].h = FOO_HEIGHT;

    L_Right[ 6 ].x = 5+FOO_WIDTH * 6;
    L_Right[ 6 ].y = 345;
    L_Right[ 6 ].w = FOO_WIDTH;
    L_Right[ 6 ].h = FOO_HEIGHT;

    L_Right[ 7 ].x = 5+FOO_WIDTH * 7;
    L_Right[ 7 ].y = 345;
    L_Right[ 7 ].w = FOO_WIDTH;
    L_Right[ 7 ].h = FOO_HEIGHT;

    L_Left[ 0 ].x = 5;
    L_Left[ 0 ].y = 590;
    L_Left[ 0 ].w = FOO_WIDTH + 20;
    L_Left[ 0 ].h = FOO_HEIGHT;

    L_Left[ 1 ].x = 85;
    L_Left[ 1 ].y = 590;
    L_Left[ 1 ].w = FOO_WIDTH + 20;
    L_Left[ 1 ].h = FOO_HEIGHT;

    L_Left[ 2 ].x = 175;
    L_Left[ 2 ].y = 590;
    L_Left[ 2 ].w = FOO_WIDTH + 20;
    L_Left[ 2 ].h = FOO_HEIGHT;

    L_Left[ 3 ].x = 270;
    L_Left[ 3 ].y = 590;
    L_Left[ 3 ].w = FOO_WIDTH + 20 + 5;
    L_Left[ 3 ].h = FOO_HEIGHT;

    L_Left[ 4 ].x = 360;
    L_Left[ 4 ].y = 590;
    L_Left[ 4 ].w = FOO_WIDTH + 20;
    L_Left[ 4 ].h = FOO_HEIGHT;

    L_Left[ 5 ].x = 445;
    L_Left[ 5 ].y = 590;
    L_Left[ 5 ].w = FOO_WIDTH + 20;
    L_Left[ 5 ].h = FOO_HEIGHT;

    L_Left[ 6 ].x = 530;
    L_Left[ 6 ].y = 590;
    L_Left[ 6 ].w = FOO_WIDTH + 20;
    L_Left[ 6 ].h = FOO_HEIGHT;

    L_Left[ 7 ].x = 605;
    L_Left[ 7 ].y = 590;
    L_Left[ 7 ].w = FOO_WIDTH + 20;
    L_Left[ 7 ].h = FOO_HEIGHT;

    L_Attack[ 0 ].x = 0;
    L_Attack[ 0 ].y = 1855;
    L_Attack[ 0 ].w = FOO_WIDTH + 16;
    L_Attack[ 0 ].h = FOO_HEIGHT;

    L_Attack[ 1 ].x = 80;
    L_Attack[ 1 ].y = 1855;
    L_Attack[ 1 ].w = FOO_WIDTH + 16;
    L_Attack[ 1 ].h = FOO_HEIGHT;

    L_Attack[ 2 ].x = 165;
    L_Attack[ 2 ].y = 1855;
    L_Attack[ 2 ].w = FOO_WIDTH + 21;
    L_Attack[ 2 ].h = FOO_HEIGHT;

    L_Attack[ 3 ].x = 250;
    L_Attack[ 3 ].y = 1855;
    L_Attack[ 3 ].w = FOO_WIDTH + 26;
    L_Attack[ 3 ].h = FOO_HEIGHT;

    L_Attack[ 4 ].x = 340;
    L_Attack[ 4 ].y = 1855;
    L_Attack[ 4 ].w = FOO_WIDTH + 41;
    L_Attack[ 4 ].h = FOO_HEIGHT;

    L_Attack[ 5 ].x = 445;
    L_Attack[ 5 ].y = 1855;
    L_Attack[ 5 ].w = FOO_WIDTH + 36;
    L_Attack[ 5 ].h = FOO_HEIGHT;

    L_Attack[ 6 ].x = 543;
    L_Attack[ 6 ].y = 1855;
    L_Attack[ 6 ].w = FOO_WIDTH + 38;
    L_Attack[ 6 ].h = FOO_HEIGHT;

    L_Attack[ 7 ].x = 645;
    L_Attack[ 7 ].y = 1855;
    L_Attack[ 7 ].w = FOO_WIDTH + 71;
    L_Attack[ 7 ].h = FOO_HEIGHT;

    L_Attack[ 8 ].x = 780;
    L_Attack[ 8 ].y = 1855;
    L_Attack[ 8 ].w = FOO_WIDTH + 59;
    L_Attack[ 8 ].h = FOO_HEIGHT;

    L_Attack[ 9 ].x = 903;
    L_Attack[ 9 ].y = 1855;
    L_Attack[ 9 ].w = FOO_WIDTH + 8;
    L_Attack[ 9 ].h = FOO_HEIGHT;

    L_Attack[ 10 ].x = 980;
    L_Attack[ 10 ].y = 1855;
    L_Attack[ 10 ].w = FOO_WIDTH + 11;
    L_Attack[ 10 ].h = FOO_HEIGHT;

    L_Attack[ 11 ].x = 1055;
    L_Attack[ 11 ].y = 1855;
    L_Attack[ 11 ].w = FOO_WIDTH + 11;
    L_Attack[ 11 ].h = FOO_HEIGHT;

    L_Attack[ 12 ].x = 1130;
    L_Attack[ 12 ].y = 1855;
    L_Attack[ 12 ].w = FOO_WIDTH + 11;
    L_Attack[ 12 ].h = FOO_HEIGHT;

    R_Head.x = 2122;
    R_Head.y = 0;
    R_Head.w = 126;
    R_Head.h = 54;

    R_Right[ 0 ].x = 2135;
    R_Right[ 0 ].y = 400;
    R_Right[ 0 ].w = 105;
    R_Right[ 0 ].h = FOO_HEIGHT;

    R_Right[ 1 ].x = 2033;
    R_Right[ 1 ].y = 400;
    R_Right[ 1 ].w = 105;
    R_Right[ 1 ].h = FOO_HEIGHT;

    R_Right[ 2 ].x = 1930;
    R_Right[ 2 ].y = 400;
    R_Right[ 2 ].w = 105;
    R_Right[ 2 ].h = FOO_HEIGHT;

    R_Right[ 3 ].x = 1830;
    R_Right[ 3 ].y = 400;
    R_Right[ 3 ].w = 100;
    R_Right[ 3 ].h = FOO_HEIGHT;

    R_Right[ 4 ].x = 1727;
    R_Right[ 4 ].y = 400;
    R_Right[ 4 ].w = 100;
    R_Right[ 4 ].h = FOO_HEIGHT;

    R_Right[ 5 ].x = 1625;
    R_Right[ 5 ].y = 400;
    R_Right[ 5 ].w = 100;
    R_Right[ 5 ].h = FOO_HEIGHT;

    R_Right[ 6 ].x = 1525;
    R_Right[ 6 ].y = 400;
    R_Right[ 6 ].w = 100;
    R_Right[ 6 ].h = FOO_HEIGHT;

    R_Right[ 7 ].x = 1420;
    R_Right[ 7 ].y = 400;
    R_Right[ 7 ].w = 100;
    R_Right[ 7 ].h = FOO_HEIGHT;

    R_Left[ 0 ].x = 2070;
    R_Left[ 0 ].y = 550;
    R_Left[ 0 ].w = 80;
    R_Left[ 0 ].h = FOO_HEIGHT;

    R_Left[ 1 ].x = 1988;
    R_Left[ 1 ].y = 550;
    R_Left[ 1 ].w = 80;
    R_Left[ 1 ].h = FOO_HEIGHT;

    R_Left[ 2 ].x = 1905;
    R_Left[ 2 ].y = 550;
    R_Left[ 2 ].w = 80;
    R_Left[ 2 ].h = FOO_HEIGHT;

    R_Left[ 3 ].x = 1733;
    R_Left[ 3 ].y = 550;
    R_Left[ 3 ].w = 80;
    R_Left[ 3 ].h = FOO_HEIGHT;

    R_Left[ 4 ].x = 1305;
    R_Left[ 4 ].y = 550;
    R_Left[ 4 ].w = 80;
    R_Left[ 4 ].h = FOO_HEIGHT;

    R_Left[ 5 ].x = 1222;
    R_Left[ 5 ].y = 550;
    R_Left[ 5 ].w = 80;
    R_Left[ 5 ].h = FOO_HEIGHT;

    R_Left[ 6 ].x = 1137;
    R_Left[ 6 ].y = 550;
    R_Left[ 6 ].w = 80;
    R_Left[ 6 ].h = FOO_HEIGHT;

    R_Left[ 7 ].x = 1153;
    R_Left[ 7 ].y = 550;
    R_Left[ 7 ].w = 80;
    R_Left[ 7 ].h = FOO_HEIGHT;

    R_Attack[ 0 ].x = 2155;
    R_Attack[ 0 ].y = 2310;
    R_Attack[ 0 ].w = 95;
    R_Attack[ 0 ].h = FOO_HEIGHT;

    R_Attack[ 1 ].x = 2055;
    R_Attack[ 1 ].y = 2310;
    R_Attack[ 1 ].w = 100;
    R_Attack[ 1 ].h = FOO_HEIGHT;

    R_Attack[ 2 ].x = 1915;
    R_Attack[ 2 ].y = 2310;
    R_Attack[ 2 ].w = 135;
    R_Attack[ 2 ].h = FOO_HEIGHT;

    R_Attack[ 3 ].x = 1755;
    R_Attack[ 3 ].y = 2310;
    R_Attack[ 3 ].w = 155;
    R_Attack[ 3 ].h = FOO_HEIGHT;

    R_Attack[ 4 ].x = 1640;
    R_Attack[ 4 ].y = 2310;
    R_Attack[ 4 ].w = 110;
    R_Attack[ 4 ].h = FOO_HEIGHT;

    R_Attack[ 5 ].x = 1560;
    R_Attack[ 5 ].y = 2310;
    R_Attack[ 5 ].w = 80;
    R_Attack[ 5 ].h = FOO_HEIGHT;

    R_Attack[ 6 ].x = 1455;
    R_Attack[ 6 ].y = 2310;
    R_Attack[ 6 ].w = 100;
    R_Attack[ 6 ].h = FOO_HEIGHT;

    R_Attack[ 7 ].x = 1360;
    R_Attack[ 7 ].y = 2310;
    R_Attack[ 7 ].w = 90;
    R_Attack[ 7 ].h = FOO_HEIGHT;

    R_Attack[ 8 ].x = 1275;
    R_Attack[ 8 ].y = 2310;
    R_Attack[ 8 ].w = 80;
    R_Attack[ 8 ].h = FOO_HEIGHT;

    R_Attack[ 9 ].x = 1197;
    R_Attack[ 9 ].y = 2310;
    R_Attack[ 9 ].w = 78;
    R_Attack[ 9 ].h = FOO_HEIGHT;

    R_Attack[ 10 ].x = 1077;
    R_Attack[ 10 ].y = 2310;
    R_Attack[ 10 ].w = 120;
    R_Attack[ 10 ].h = FOO_HEIGHT;

    R_Attack[ 11 ].x = 960;
    R_Attack[ 11 ].y = 2310;
    R_Attack[ 11 ].w = 115;
    R_Attack[ 11 ].h = FOO_HEIGHT;

    R_Attack[ 12 ].x = 867;
    R_Attack[ 12 ].y = 2310;
    R_Attack[ 12 ].w = 90;
    R_Attack[ 12 ].h = FOO_HEIGHT;
}


bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Animation Test", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    // Load the background
    background = load_image("img/background.png");
    // If there was a problem in loading the background
    if ( background == NULL )
    {
        return false;
    }

    //Load the sprite sheet of the person on the left
    person_L = IMG_Load( "img/person_L.png" );
    //If there was a problem in loading the sprite
    if( person_L == NULL )
    {
        return false;
    }

    //load the sprite sheet of the person on the right
    person_R = IMG_Load( "img/person_R.png" );

    //If there was a problem in loading the sprite
    if( person_R == NULL )
    {
        return false;
    }

    R_win = IMG_Load( "img/R_win.png");

    if ( R_win == NULL)
    {
        return false;
    }

    L_win = IMG_Load( "img/L_win.png");

    if ( L_win == NULL)
    {
        return false;
    }

    blood = IMG_Load( "img/blood.png" );

    if ( blood == NULL)
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{

    //Free the surface
    SDL_FreeSurface( person_L );

    SDL_FreeSurface( person_R );

    SDL_FreeSurface( background );

    SDL_FreeSurface( blood );

    SDL_FreeSurface( R_win );

    SDL_FreeSurface( L_win );

    //Quit SDL
    SDL_Quit();
}

void show_background( int * back_frame )
{
    if ( *back_frame < -7)
        *back_frame = 0;

    apply_surface(0, *back_frame * SCREEN_HEIGHT, background, screen, NULL);
    *back_frame = *back_frame - 1;

}


int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    // record the background frame
    int j=0;


    //Clip the sprite sheet
    set_clips();

    //The frame rate regulator
    Timer fps;

    //The stick figure
    // initialize the offset and status
    Foo L_Person(0, PERSON_L);

    Foo R_Person(SCREEN_WIDTH-90, PERSON_R);

    //While the user hasn't quit
    while( quit == false )
    {
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the stick figure
            L_Person.handle_events();

            R_Person.handle_events();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //show the background
        show_background(&j);
        apply_surface(0, 0, person_L, screen, &L_Head);
        apply_surface(SCREEN_WIDTH-120, 0, person_R, screen, &R_Head);

        //Move the stick figure
        L_Person.move(R_Person.get_offset());
        //Show the stick figure on the screen
        L_Person.show_hp();
        L_Person.show(person_L, L_Right, L_Left);
        L_Person.check_col(R_Person.get_atk(), R_Person.attack(person_R, R_Attack));

        //Move the stick figure
        R_Person.move(L_Person.get_offset());
        //Show the stick figure on the screen
        R_Person.show_hp();
        R_Person.show(person_R, R_Right, R_Left);
        R_Person.check_col(L_Person.get_atk(), L_Person.attack(person_L,L_Attack));


        if (L_Person.lose())
        {
            apply_surface(0, 0,R_win, screen, NULL);
        }

        else if (R_Person.lose())
        {
            apply_surface(0, 0,L_win, screen, NULL);
        }
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}
