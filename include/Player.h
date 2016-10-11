#ifndef PLAYER_H
#define PLAYER_H
#include<SDL2\SDL.h>
#include<stdio.h>
#include<string>
class Player
{
    public:
        Player(SDL_Surface* _param);
        void MOV(int dir);
        virtual ~Player();
        void InitRect();
        int x,y;
        SDL_Rect Rectanglu;
        SDL_Surface* Suprafata;
};
#endif // PLAYER_H
