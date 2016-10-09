#include<SDL2\SDL.h>
#include "display.h"

int main(int argc,char*args[])
{
        if(SDL_Init(SDL_INIT_EVERYTHING)<0)
        {
            fprintf(stderr,"SDL failed to initialize and returned error %s\n",SDL_GetError());
        }
        else
        {
            display display(640,480);
            while(!display.IsQuit())
            {
                while(SDL_PollEvent(&display.handler)!=0)
                {
                    if((display.handler).type==SDL_QUIT)
                    {
                        display.SetQuit(true);
                    }
                }
            }
        }
    SDL_Quit();
    return 0;
}
