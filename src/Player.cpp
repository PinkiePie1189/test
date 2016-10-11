#include "Player.h"

Player::Player(SDL_Surface* _supraf)
{
    //ctor
    Suprafata=_supraf;
    InitRect();
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGB(Suprafata->format,255,0,0));
    printf("Player constructed\n");
}
Player::~Player()
{
    //dtor
    printf("Player destructed\n");
}
void Player::InitRect()
{
    Rectanglu.x=0;
    Rectanglu.y=0;
    Rectanglu.w=400;
    Rectanglu.h=300;
}
void Player::MOV(int dir)
{
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGBA(Suprafata->format,0,0,0,100));
    switch (dir)
    {
    case 1:
        Rectanglu.y-=10;
        break;
    case 2:
        Rectanglu.y+=10;
        break;
    case 3:
        Rectanglu.x+=10;
        break;
    case 4:
        Rectanglu.x-=10;
    }
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGB(Suprafata->format,255,0,0));
}
