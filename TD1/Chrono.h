#ifndef CHRONO_H
#define CHRONO_H

#include "timespec.h"

class Chrono 
{
public:
    Chrono();
    void restart();
    timespec stop();
    timespec lap() const;
    bool isActive() const;
    double lap_ms() const;

private:
    timespec m_startTime, m_stopTime;
};

#endif
