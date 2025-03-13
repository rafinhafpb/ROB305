#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>

class Mutex
{
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
        const void lock();
        bool lock(double timeout_ms);
        const void unlock();
};

#endif