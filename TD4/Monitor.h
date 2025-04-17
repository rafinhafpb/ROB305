#ifndef MONITOR_H
#define MONITOR_H
#include "../TD3/TD3b/Mutex.h"
#include "../TD1/timespec.h"
#include "../TD3/TD3b/TimeoutException.h"

class Monitor 
{
public:
    Monitor(Mutex& mutex);
    ~Monitor();
    void notify();
    void notifyAll();

private:
    class Lock: public Mutex::Lock
    {
        public:
            Lock(Monitor& monitor);
            Lock(Monitor& monitor, double timeout_ms);
            void wait();
            void wait(double timeout_ms);

        private:
            Monitor& m_monitor;
    };
    pthread_cond_t posixCondId;
    Mutex& m_mutex;
};

#endif