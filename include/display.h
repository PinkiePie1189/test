#ifndef DISPLAY_H
#define DISPLAY_H
#include<SDL2\SDL.h>
#include<SDL2\SDL_image.h>
#include<stdio.h>
#include<string>
#include <Vector2.h>

class display
{
    public:
        display(int _screen_width,int _screen_height);
        SDL_Surface* loadSurface (std::string path);
        bool LoadMedia(std::string _path);
        void PutPicture(SDL_Surface* foto,bool _stretch);
        bool IsQuit();
        void SetQuit(bool _quit);
        int width,height;
        SDL_Event handler;
        SDL_Window* window=NULL;
        SDL_Surface* poza=NULL;
        SDL_Surface* Surface=NULL;
        virtual ~display();
    protected:
    private:
        SDL_Rect WholeScreen;
        bool quit=false;
};


#endif // DISPLAY_H
