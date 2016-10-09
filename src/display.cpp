#include "display.h"

display::display(int _screen_width,int _screen_height)
{
    //ctor
    printf("Display constructed\n");
    window=SDL_CreateWindow("joj",100,100,_screen_width,_screen_height,SDL_WINDOW_SHOWN);
    LoadMedia();
    if(window==NULL)
    {
        fprintf(stderr,"Window could not be initialized! SDL Error:%s",SDL_GetError());
    }
    else
    {
        Surface=SDL_GetWindowSurface(window);
        PutPicture();
        SDL_UpdateWindowSurface(window);
    }
}

display::~display()
{
    //dtor
    SDL_FreeSurface(poza);
    SDL_DestroyWindow(window);
    printf("Display destructed\n");
}
bool display::LoadMedia()
{
    bool success=true;
    poza=SDL_LoadBMP("Assets/Fluttershy.bmp");
    if(poza==NULL)
    {
        fprintf(stderr,"Unable to load image %s! SDL Error: %s\n","Assets/Fluttershy.bmp", SDL_GetError() );
        success=false;
    }
    return success;
}
void display::PutPicture()
{
    SDL_BlitSurface(poza, NULL,Surface, NULL );
}
bool display::IsQuit()
{
    return quit;
}
void display::SetQuit(bool _quit)
{
    quit=_quit;
}
