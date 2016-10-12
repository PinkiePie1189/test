#include<SDL2\SDL.h>
#include<stdio.h>
#include<string>
#include"Vector2.h"

class Ball
{
    public:
        void MV();
        Ball(SDL_Surface* _supraf, Vector2<int> _poz);
        void InitRect();
        int x,y;
        SDL_Rect Rectanglu;
        SDL_Surface* Suprafata;
        float speed;
        Vector2<int> position;
        Ball();
        virtual ~Ball();

    protected:
    private:
};
