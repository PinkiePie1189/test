#include<SDL2\SDL.h>
#include "display.h"
#include "Player.h"
#define DEBUG
#include "Vector2.h"
#include<SDL2\SDL_ttf.h>
#ifdef DEBUG
#include<stdlib.h>
#include <conio.h>
#endif // DEBUG
int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        fprintf(stderr,"SDL failed to initialize and returned error: %s\n",SDL_GetError());
    }
   else
    {
        const Uint8 *MagieNeagra = SDL_GetKeyboardState(NULL);
        display Display(1080,720);
        Vector2<float> rata((float) Display.width/800,(float) Display.height/600);
        Player player1(Display.Surface,Vector2<int>(rata.x * 749, rata.y * 198));
        Player player2(Display.Surface,Vector2<int>(rata.x * 34, rata.y * 198));
        Display.LoadMedia("Assets/Fluttershy.bmp");
        while(!Display.IsQuit())
        {
            SDL_PollEvent(&Display.handler);

            if (MagieNeagra[SDL_SCANCODE_ESCAPE])
                Display.SetQuit(true);
            if (MagieNeagra[SDL_SCANCODE_DOWN])
                player1.MOV(2);
            if (MagieNeagra[SDL_SCANCODE_UP])
                player1.MOV(1);
            if (MagieNeagra[SDL_SCANCODE_W])
                player2.MOV(1);
            if (MagieNeagra[SDL_SCANCODE_S])
                player2.MOV(2);

            #ifdef DEBUG
            printf("Aici sunt!\n");
            #endif // DEBUG
            if((Display.handler).type==SDL_QUIT)
                Display.SetQuit(true);

            /*#ifdef DEBUG
            Vector2<int> MousePos;
            SDL_GetMouseState(&MousePos.x,&MousePos.y);
            printf("%d %d\n",MousePos.x,MousePos.y);
            system("cls");
            #endif // DEBUG*/

            SDL_UpdateWindowSurface(Display.window);
        }
    }
    SDL_Quit();
    return 0;
}
