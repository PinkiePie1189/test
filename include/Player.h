#ifndef PLAYER_H
#define PLAYER_H
#include<SDL2\SDL.h>
#include<stdio.h>
#include<string>
#include"Vector2.h"
class Player
{
    public:
        Player(SDL_Surface* _param,Vector2<int> _poz);
        void MOV(int dir);
        virtual ~Player();
        void InitRect();
        int x,y;
        SDL_Rect Rectanglu;
        SDL_Surface* Suprafata;
        float speed;
        Vector2<int> position;
};
#endif // PLAYER_H
