#ifndef CHRONO_H
#define CHRONO_H

#include "timespec.h"

class Chrono 
{
public:
    Chrono();
    void restart();
    timespec stop();
    bool isActive() const;
    timespec lap() const;
    double lap_ms() const;

private:
    timespec m_startTime, m_stopTime;
};

#endif
