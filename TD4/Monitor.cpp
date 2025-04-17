#include "Monitor.h"

Monitor::Monitor(Mutex& mutex) : m_mutex(mutex) 
{
    pthread_cond_init(&posixCondId, nullptr);
}

Monitor::~Monitor() 
{
    pthread_cond_destroy(&posixCondId);
}

Monitor::Lock::Lock(Monitor& monitor) : Mutex::Lock(monitor.m_mutex), m_monitor(monitor) {}

Monitor::Lock::Lock(Monitor& monitor, double timeout_ms) : Mutex::Lock(monitor.m_mutex, timeout_ms), m_monitor(monitor) {}

void Monitor::Lock::wait() 
{
    pthread_cond_wait(&m_monitor.posixCondId, &m_monitor.m_mutex.posixMutexId);
}

void Monitor::Lock::wait(double timeout_ms) 
{
    timespec abstime = timespec_now() + timespec_from_ms(timeout_ms);
    pthread_cond_timedwait(&m_monitor.posixCondId, &m_monitor.m_mutex.posixMutexId, &abstime);
}

void Monitor::notify() 
{
    pthread_cond_signal(&posixCondId);
}

void Monitor::notifyAll() 
{
    pthread_cond_broadcast(&posixCondId);
}