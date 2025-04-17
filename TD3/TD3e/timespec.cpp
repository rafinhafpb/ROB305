#include "timespec.h"
#include <cmath>
#include <errno.h>
#include <iostream>
#include <string.h>

using namespace std;

double timespec_to_ms(const timespec& time_ts)
{
    return (time_ts.tv_sec * 1e3 + time_ts.tv_nsec / 1e6);
};

timespec timespec_from_ms(double time_ms)
{
    timespec time_ts;
    time_ts.tv_sec = static_cast<time_t>(time_ms / 1e3);
    time_ts.tv_nsec = std::lround((time_ms - time_ts.tv_sec * 1e3) * 1e6);
    if(time_ts.tv_nsec < 0.0)
    {
        time_ts.tv_sec -= 1;
        time_ts.tv_nsec += 1e9;
    }
    return time_ts;
};


timespec timespec_now() 
{
    struct timespec abstime;
    clock_gettime(CLOCK_REALTIME, &abstime);
    return abstime;
};

timespec timespec_negate(const timespec& time_ts)
{
    timespec time_neg;
    time_neg.tv_sec = -time_ts.tv_sec - 1;
    time_neg.tv_nsec = 1e9 - time_ts.tv_nsec;
    if(time_neg.tv_nsec == 1e9)
    {
        time_neg.tv_sec += 1;
        time_neg.tv_nsec = 0;
    }
    return time_neg;
};

timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
    timespec time_sum;
    time_sum.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;
    time_sum.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;
    if(time_sum.tv_nsec >= 1e9)
    {
        time_sum.tv_sec += 1;
        time_sum.tv_nsec -= 1e9;
    }
    return time_sum;
};

timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
    timespec time_sub;
    time_sub = timespec_add(time1_ts, timespec_negate(time2_ts));
    return time_sub;
};

void timespec_wait(const timespec& delay_ts)
{
    try
    {
        if(nanosleep(&delay_ts, nullptr)) 
        {
            throw(errno);
        }
    }
    catch(...)
    {
        std::cout << "Error detected:\t" << strerror(errno) << "\n";
    }
};

timespec operator- (const timespec& time_ts)
{
    return timespec_negate(time_ts);
};

timespec operator+ (const timespec& time1_ts, const timespec& time2_ts) 
{
    return timespec_add(time1_ts, time2_ts);
};

timespec operator- (const timespec& time1_ts, const timespec& time2_ts)
{
    return timespec_subtract(time1_ts, time2_ts);
};

timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = timespec_add(time_ts, delay_ts);
    return time_ts;
};

timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = timespec_subtract(time_ts, delay_ts);
    return time_ts;
};

bool operator== (const timespec& time1_ts, const timespec& time2_ts)
{
    return (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec);
};

bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
{
    return (time1_ts.tv_sec != time2_ts.tv_sec || time1_ts.tv_nsec != time2_ts.tv_nsec);
};

bool operator< (const timespec& time1_ts, const timespec& time2_ts)
{
    if(time1_ts.tv_sec == time2_ts.tv_sec)
    {
        return time1_ts.tv_nsec < time2_ts.tv_nsec;
    }
    else
    {
        return time1_ts.tv_sec < time2_ts.tv_sec;
    }
};

bool operator> (const timespec& time1_ts, const timespec& time2_ts)
{
    if(time1_ts.tv_sec == time2_ts.tv_sec)
    {
        return time1_ts.tv_nsec > time2_ts.tv_nsec;
    }
    else
    {
        return time1_ts.tv_sec > time2_ts.tv_sec;
    }
};