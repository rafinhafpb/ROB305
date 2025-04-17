#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
#include "Chrono.h"

class Thread
{
public:
    Thread(int id);
    virtual ~Thread();
    void start(int priority = 0);
    void join();
    bool isStarted();
    static int getMaxPrio(int policy);
    static int getMinPrio(int policy);
    static void setMainSched(int policy);
    static int getMainSched(int policy);
    Chrono m_chrono;
    long duration_ms();
    int id;

private:
    pthread_attr_t posixThreadAttrId;
    pthread_t posixThreadId;
    static void* call_run(void* v_Thread);

protected:
    virtual void run() = 0;
};

#endif