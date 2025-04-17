#include "Mutex.h"

Mutex::Mutex(bool isInversionSafe)
{
    pthread_mutexattr_init(&posixMutexAttrId);
    pthread_mutexattr_settype(&posixMutexAttrId, PTHREAD_MUTEX_RECURSIVE);
    if (isInversionSafe)
    {
        pthread_mutexattr_setprotocol(&posixMutexAttrId, PTHREAD_PRIO_INHERIT);
    }
    pthread_mutex_init(&posixMutexId, &posixMutexAttrId);
}

Mutex::~Mutex() 
{
    pthread_mutex_destroy(&posixMutexId);
    pthread_mutexattr_destroy(&posixMutexAttrId);
}

void Mutex::lock() 
{
    pthread_mutex_lock(&posixMutexId);
}

bool Mutex::lock(double timeout_ms) 
{
    timespec timeout = timespec_now() + timespec_from_ms(timeout_ms);
    return pthread_mutex_timedlock(&posixMutexId, &timeout) == 0;
}

void Mutex::unlock() 
{
    pthread_mutex_unlock(&posixMutexId);
}

Mutex::Lock::Lock(Mutex& mutex) : mutex(mutex) 
{
    mutex.lock();
}

Mutex::Lock::Lock(Mutex& mutex, double timeout_ms) : mutex(mutex) 
{
    if (!mutex.lock(timeout_ms)) {
        throw TimeoutException(timeout_ms);
    }
}

Mutex::Lock::~Lock() 
{
    mutex.unlock();
}
