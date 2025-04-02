#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>

class Mutex
{
friend class Monitor;

public:
    Mutex();
    ~Mutex();

    class Lock
    {
    public:
        Lock(Mutex& mutex);
        Lock(Mutex& mutex, double timeout_ms);
        ~Lock();

    private:
        Mutex& mutex;
    };

private:
    pthread_mutex_t posixMutexId;
    void lock();
    bool lock(double timeout_ms);
    void unlock();
};

#endif