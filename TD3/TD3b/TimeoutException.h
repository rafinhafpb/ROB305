#ifndef TIMEOUTEXCEPTION_h
#define TIMEOUTEXCEPTION_h

class TimeoutException
{
    public:
        TimeoutException(long timeout_ms);
        const long timeout_ms;
};

#endif