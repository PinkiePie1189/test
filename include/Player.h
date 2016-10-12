#ifndef PLAYER_H
#define PLAYER_H
#include<SDL2\SDL.h>
#include<stdio.h>
#include<string>
#include"Vector2.h"

class Player
{
    public:
        int ord;
        Player(SDL_Surface* _param,Vector2<int> _poz, int _ord);
        void MOV(int dir);
        virtual ~Player();
        void InitRect();
        int x,y;
        SDL_Rect Rectanglu;
        SDL_Surface* Suprafata;
        float speed;
        Vector2<int> position;
        bool hit=false;
};
#endif // PLAYER_H
