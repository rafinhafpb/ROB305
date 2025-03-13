#ifndef CHRONO_H
#define CHRONO_H

#include "timespec.h"

class Chrono 
{
public:
    Chrono();                           // Constructor
    void restart();                     // Methods
    timespec stop();
    bool isActive() const;
    timespec lap() const;
    double lap_ms() const;

private:
    timespec m_startTime, m_stopTime;   // Atributes
};

#endif
