#include "Mutex.h"
#include "timespec.h"

Mutex::Mutex() {
    pthread_mutex_init(&posixMutexId, nullptr);
}

Mutex::~Mutex() {
    pthread_mutex_destroy(&posixMutexId);
}

const void Mutex::lock() {
    pthread_mutex_lock(&posixMutexId);
}

bool Mutex::lock(double timeout_ms) {
    timespec timeout = timespec_from_ms(timeout_ms);
    return pthread_mutex_timedlock(&posixMutexId, &timeout) == 0;
}

const void Mutex::unlock() {
    pthread_mutex_unlock(&posixMutexId);
}

Mutex::Lock::Lock(Mutex& mutex) {
    mutex.lock();
}
