#include "Player.h"

Player::Player(SDL_Surface* _supraf,Vector2<int> _poz)
{
    //ctor
    position=_poz;
    speed=1;
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
    Rectanglu.x=position.x;
    Rectanglu.y=position.y;
    Rectanglu.w=25;
    Rectanglu.h=200;
}

void Player::MOV(int dir)
{
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGBA(Suprafata->format,0,0,0,100));
    switch (dir)
    {
    case 1:
        Rectanglu.y-=speed;
        break;
    case 2:
        Rectanglu.y+=speed;
        break;
    case 3:
        Rectanglu.x+=speed;
        break;
    case 4:
        Rectanglu.x-=speed;
    }
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGB(Suprafata->format,255,0,0));
}
