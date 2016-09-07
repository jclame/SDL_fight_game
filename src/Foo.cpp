#include "foo.h"

Foo::Foo(int init_set, int person)
{
    //Initialize movement variables
    offSet = init_set;
    velocity = 0;
    HP = 0;

    //Initialize animation variables
    frame = 0;
    person_mark = person;
    atk_status = ATK_OFF;
    attack_frame = 0;
    status = FOO_RIGHT;
}


void Foo::handle_events()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        if (person_mark == PERSON_L)
        {
            //Set the velocity
            switch( event.key.keysym.sym )
            {
            // the left person walk right
            case SDLK_d:
                //person_mark = PERSON_L;
                velocity += FOO_WIDTH / 4;
                break;
            // the left person walk left
            case SDLK_a:
                // person_mark = PERSON_L;
                velocity -= FOO_WIDTH / 4;
                break;
            // the left person attack
            case SDLK_f:
                // person_mark = PERSON_L;
                atk_status = ATK_ON;
                break;
            default :
                break;
            }
        }
        else if (person_mark == PERSON_R)
        {
            switch( event.key.keysym.sym )
            {
            case SDLK_RIGHT:
                // person_mark = PERSON_R;
                velocity += FOO_WIDTH / 4;
                break;
            case SDLK_LEFT:
                person_mark = PERSON_R;
                velocity -= FOO_WIDTH / 4;
                break;
            case SDLK_l:
                // person_mark = PERSON_R;
                atk_status = ATK_ON;
                break;
            default:
                break;
            }
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        if (person_mark == PERSON_L)
        {
            //Set the velocity
            switch( event.key.keysym.sym )
            {
            case SDLK_d :

                velocity -= FOO_WIDTH / 4;
                break;
            case SDLK_a :

                velocity += FOO_WIDTH / 4;
                break;
            default :
                break;
            }
        }
        else if (person_mark == PERSON_R)
        {
            //Set the velocity
            switch( event.key.keysym.sym )
            {

            case SDLK_RIGHT :
                velocity -= FOO_WIDTH / 4;
                break;

            case SDLK_LEFT :
                velocity += FOO_WIDTH / 4;
                break;
            default :
                break;
            }
        }
    }
}


void Foo::move(int collis_offset)
{
    //int frameL, frameR;
    //Move
    offSet += velocity;

    //Keep the stick figure in bounds
    if( ( offSet < 0 ) || ( offSet + FOO_WIDTH > SCREEN_WIDTH ) || ((offSet > collis_offset-50)&&(offSet < collis_offset+50))  )
    {
        offSet -= velocity;
    }

}

void Foo::show(SDL_Surface* image, SDL_Rect *clipsR, SDL_Rect *clipsL)
{
    //If Foo is moving left
    if( velocity < 0 )
    {
        //Set the animation to left
        status = FOO_LEFT;

        //Move to the next frame in the animation
        frame++;
    }
    //If Foo is moving right
    else if( velocity > 0 )
    {
        //Set the animation to right
        status = FOO_RIGHT;

        //Move to the next frame in the animation
        frame++;
    }
    //If Foo standing
    else
    {
        //Restart the animation
        frame = 0;
    }

    //Loop the animation
    if( frame >= 8 )
    {
        frame = 0;
    }

    //Show the stick figure
    if( status == FOO_RIGHT && atk_status == ATK_OFF )
    {
        apply_surface( offSet, SCREEN_HEIGHT - FOO_HEIGHT, image, screen, &clipsR[ frame ] );
    }
    else if( status == FOO_LEFT && atk_status == ATK_OFF )
    {
        apply_surface( offSet, SCREEN_HEIGHT - FOO_HEIGHT, image, screen, &clipsL[ frame ] );
    }
}

int Foo::attack(SDL_Surface* image, SDL_Rect* clips_ATK)
{
    if (atk_status == ATK_ON)
    {

        apply_surface(offSet, SCREEN_HEIGHT - FOO_HEIGHT, image, screen, &clips_ATK[attack_frame]);
        // the next attack frame
        attack_frame++;

    }
    if (attack_frame >= 13)
    {
        atk_status = ATK_OFF;
        attack_frame = 0;
    }
    return offSet;
}

void Foo::check_col(int atk, int collision_offset)
{
    if (atk == ATK_ON )
    {
        if (person_mark == PERSON_L)
        {
            if (offSet > collision_offset-100 && HP<95)
                HP++;
        }
        else if (person_mark == PERSON_R )
        {
            if (offSet < collision_offset+100 && HP<95)
                HP++;
        }
    }
}

void Foo::show_hp()
{
    if (person_mark == PERSON_L )
        apply_surface(0-HP*HP_DEC, 54, blood, screen, NULL);
    else
        apply_surface(450+HP*HP_DEC, 54, blood, screen, NULL);
}

bool Foo::lose()
{
    if (HP == 95)
        return true;
    else
        return false;
}
