#ifndef TIMER_H
#define TIMER_H
#include<SDL2\SDL.h>

class Timer
{
    public:
        Timer();
        virtual ~Timer();
        void start();
        void pause();
        void unpause();
        void stop();
        Uint32 getTicks();
    protected:
    private:
        Uint32 StartTicks;
        Uint32 PausedTicks;
        bool paused;
        bool started;
};

#endif // TIMER_H
