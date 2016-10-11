#include "Timer.h"

Timer::Timer()
{
    //ctor
    started=0;
    paused=0;
    StartTicks=0;
    PausedTicks=0;
}

Timer::~Timer()
{
    //dtor
}
void Timer::start()
{
    started=1;
    paused=0;
    StartTicks=SDL_GetTicks();
    PausedTicks=0;
}
void Timer::stop()
{
    started=0;
    paused=0;
    StartTicks=0;
    PausedTicks=0;
}
void Timer::pause()
{
    if(started && !paused)
    {
        paused=true;
        PausedTicks=SDL_GetTicks()-StartTicks;
        StartTicks=0;
    }
}
void Timer::unpause()
{
    if(started && paused)
    {
        paused=0;
        StartTicks=SDL_GetTicks() - PausedTicks;
        PausedTicks=0;
    }
}
Uint32 Timer::getTicks()
{
    if(started)
    {
        if(paused)
        {
            return PausedTicks;
        }
        else
        {
            return SDL_GetTicks()-StartTicks;
        }
    }
    return 0;
}
