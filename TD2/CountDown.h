#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include "Timer.h"

class CountDown : public Timer
{
public:
    CountDown(int n);
    int getCounter() const {return m_counter;}

private:
    void callback();
    int m_counter;
};

#endif