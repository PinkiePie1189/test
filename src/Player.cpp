#include "Player.h"
#include "Marcos.h"

int P1pos;
int P2pos;
int PlayerLength;
int PlayerWidth;

Player::Player(SDL_Surface* _supraf,Vector2<int> _poz, int _ord)
{
    //ctor
    P1pos = _poz.y;
    P2pos = _poz.y;
    ord = _ord;
    position = _poz;
    speed = 1;
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
    Rectanglu.x = position.x;
    Rectanglu.y = position.y;
    Rectanglu.w = 25 * rata.x;
    Rectanglu.h = 200 * rata.y;
    PlayerLength = Rectanglu.h;
    PlayerWidth = Rectanglu.w;
}

void Player::MOV(int dir)
{
    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGBA(Suprafata->format,0,0,0,100));
    printf("%d %d \n", Rectanglu.x, Rectanglu.y);
    switch (dir)
    {
        case 1:
            if (Rectanglu.y >= 23 * rata.y)
                Rectanglu.y -= speed;
            break;

        case 2:
            if (Rectanglu.y <= 578 * rata.y - Rectanglu.h)
                Rectanglu.y += speed;
            break;
    }
    if (ord == 1)
        P1pos = Rectanglu.y;

    if (ord == 2)
        P2pos = Rectanglu.y;

    SDL_FillRect(Suprafata,&Rectanglu,SDL_MapRGB(Suprafata->format,255,0,0));
}
