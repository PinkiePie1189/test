#ifndef DISPLAY_H
#define DISPLAY_H
#include<SDL2\SDL.h>
#include<stdio.h>
class display
{
    public:
        display(int _screen_width,int _screen_height);
        bool LoadMedia();
        void PutPicture();
        bool IsQuit();
        void SetQuit(bool _quit);
        SDL_Event handler;
        virtual ~display();
    protected:
    private:
        SDL_Window* window=NULL;
        SDL_Surface* Surface=NULL;
        SDL_Surface* poza=NULL;
        bool quit=false;
};

#endif // DISPLAY_H
