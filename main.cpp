#include<SDL2\SDL.h>
#include "display.h"
#include "Player.h"
#define DEBUG
#include "Vector2.h"
#include<SDL2\SDL_ttf.h>
#include<SDL2\SDL_image.h>
#include<stdlib.h>
#include <conio.h>
#include "Marcos.h"
#include "Ball.h"
Vector2<float> rata;
Vector2<int> dsp;

int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0 || IMG_Init(IMG_INIT_PNG) < 0)
    {
        fprintf(stderr,"SDL failed to initialize and returned error: %s %s\n",SDL_GetError(),IMG_GetError());
    }
   else
    {
        display Display (800,600);
        const Uint8 *MagieNeagra = SDL_GetKeyboardState(NULL);
        rata = Vector2<float> ((float) Display.width / 800, (float) Display.height / 600);
        dsp = Vector2<int> (Display.width, Display.height);
        Display.PutPicture(Display.loadSurface("Assets/masa.png"),1);

        Player player1(Display.Surface,Vector2<int>(rata.x * 749, rata.y * 198), 1);
        Player player2(Display.Surface,Vector2<int>(rata.x * 34, rata.y * 198), 2);
        Ball ball(Display.Surface, Vector2<int>(Display.width / 2, Display.height / 2));

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

            ball.MV();
            if((Display.handler).type==SDL_QUIT)
                Display.SetQuit(true);

            #ifdef DEBUG
            Vector2<int> MousePos;
            SDL_GetMouseState(&MousePos.x,&MousePos.y);
            //printf("%d %d\n",MousePos.x,MousePos.y);
            #endif // DEBUG*/

            SDL_UpdateWindowSurface(Display.window);
        }
    }
    SDL_Quit();
    return 0;
}
