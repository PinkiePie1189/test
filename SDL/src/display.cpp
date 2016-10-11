#include "display.h"

display::display(int _screen_width,int _screen_height)
{
    //ctor
    width=_screen_width;
    height=_screen_height;
    WholeScreen.x=0;
    WholeScreen.y=0;
    WholeScreen.w=_screen_width;
    WholeScreen.h=_screen_height;
    window=SDL_CreateWindow("joj",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_screen_width,_screen_height,SDL_WINDOW_SHOWN);
    if(window==NULL)
    {
        fprintf(stderr,"Window could not be initialized! SDL Error:%s\n",SDL_GetError());
    }
    else
    {
        //SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
        Surface=SDL_GetWindowSurface(window);
    }
     printf("Display constructed\n");
}

display::~display()
{
    //dtor
    SDL_FreeSurface(poza);
    SDL_DestroyWindow(window);
    printf("Display destructed\n");
}
bool display::LoadMedia(std::string _path)
{
    bool success=true;
    poza=SDL_LoadBMP(_path.c_str());
    if(poza==NULL)
    {
        fprintf(stderr,"Unable to load image %s! SDL Error: %s\n",_path.c_str(), SDL_GetError() );
        success=false;
    }
    return success;
}
void display::PutPicture(SDL_Surface* foto,bool _stretch)
{
    switch(_stretch)
    {
        case 1:
    SDL_BlitScaled(foto,NULL,Surface,&WholeScreen);
    break;
        case 0:
            SDL_BlitSurface(foto,NULL,Surface,NULL);
            break;
        default:
            break;
    }
}
bool display::IsQuit()
{
    return quit;
}
void display::SetQuit(bool _quit)
{
    quit=_quit;
}
