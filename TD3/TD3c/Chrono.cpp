#include "Chrono.h"

Chrono::Chrono()
{
    restart();
}

void Chrono::restart()
{
    m_startTime = timespec_now();
    m_stopTime = m_startTime;
}

timespec Chrono::stop() 
{
    m_stopTime = timespec_now();
    return (m_stopTime - m_startTime);
}

bool Chrono::isActive() const
{
    return (m_stopTime == m_startTime);
}

timespec Chrono::lap() const
{
    if (m_stopTime == m_startTime)
    {
        return (timespec_now() - m_startTime);
    }
    else
    {
        return (m_stopTime - m_startTime);
    }
}

double Chrono::lap_ms() const
{
    return timespec_to_ms(lap());
}