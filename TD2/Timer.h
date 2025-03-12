#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <signal.h>
#include "timespec.h"

class Timer 
{
    public:
        Timer();
        virtual ~Timer();
        void start(timespec duration, bool isPeriodic);
        void start_ms(double duration_ms, bool isPeriodic);
        void stop();

    private:
        timer_t tid;
        static void call_callback(int, siginfo_t* si, void*);

    protected:
        virtual void callback() = 0;
};

#endif