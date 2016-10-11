#include<SDL2\SDL.h>
#include "display.h"
#include "Player.h"

int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        fprintf(stderr,"SDL failed to initialize and returned error: %s\n",SDL_GetError());
    }
   else
    {
        display Display(800,600);
        Player player1(Display.Surface);
        Display.LoadMedia("Assets/Fluttershy.bmp");
        while(!Display.IsQuit())
        {
            while(SDL_PollEvent(&Display.handler)!=0)
            {
                if((Display.handler).type==SDL_QUIT)
                {
                    Display.SetQuit(true);
                }
                else if((Display.handler).type==SDL_KEYDOWN)
                {
                    switch(Display.handler.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        Display.SetQuit(true);
                        break;
                    case SDLK_DOWN:
                        player1.MOV(2);
                        break;
                    case SDLK_UP:
                        player1.MOV(1);
                        break;
                    case SDLK_RIGHT:
                        player1.MOV(3);
                        break;
                    case SDLK_LEFT:
                        player1.MOV(4);
                    default:
                        break;
                    }
                }
            }
            SDL_UpdateWindowSurface(Display.window);
        }
    }
    SDL_Quit();
    return 0;
}
