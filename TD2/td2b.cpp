#include "Timer.h"
#include "CountDown.h"
#include <iostream>

CountDown countdown(10);

int main()
{
    // ----------- TEST CLASS TIMER/COUNTDOWN ----------
    countdown.start_ms(1000, true);
    int current_timer = countdown.getCounter();

    while (countdown.getCounter() > 0)
    {
        if (current_timer != countdown.getCounter()) 
        {
            std::cout << "Counter interrupt, value: "<< countdown.getCounter() << std::endl;
            current_timer = countdown.getCounter();
        }
    }

    countdown.stop();
}