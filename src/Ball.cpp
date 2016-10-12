#include "Ball.h"
#include "Vector2.h"
#include "Marcos.h"

int pl1X;
int pl2X;

Ball::Ball(SDL_Surface* _supraf, Vector2<int> _poz)
{
    pl2X = PlayerWidth + (float) rata.x * 198;
    pl1X = rata.x * 749;
    //ctor
    position = _poz;
    speed = -1;
    Suprafata=_supraf;
    InitRect();
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGB(Suprafata->format,255,255,255));
    printf("Player constructed\n");
}

void Ball::InitRect()
{
    Rectanglu.x = position.x;
    Rectanglu.y = position.y;
    Rectanglu.w = 25 * rata.x;
    Rectanglu.h = 25 * rata.y;
}

void Ball::MV() {
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGBA(Suprafata->format,0,0,0,100));
    Rectanglu.x += speed;
    if (Rectanglu.x >= dsp.x / 2) {
    } else {
        if (Rectanglu.x <= pl2X) { //passed by the left player
                printf("Rectanglu %d\n", Rectanglu.y);
                printf("P2pos %d\n", P2pos);
                printf("P2pos %d\n", P2pos);
            if ((Rectanglu.y >= P2pos - PlayerLength) && (Rectanglu.y <= Rectanglu.h + P2pos)) { //Hit the left player
                speed =-speed;
            }
        }
    }
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGB(Suprafata->format,255,0,0));
}

Ball::~Ball()
{
    //dtor
}
