#include "Thread.h"

Thread::Thread(int id) : id(id) 
{
    pthread_attr_init(&posixThreadAttrId);
}

void Thread::start(int priority)
{
    m_chrono.restart();
    sched_param schedParams;
    schedParams.sched_priority = priority;
    pthread_attr_setschedparam(&posixThreadAttrId, &schedParams);
    pthread_create(&posixThreadId, &posixThreadAttrId, call_run, this);
}

Thread::~Thread()
{
    m_chrono.stop();
    pthread_attr_destroy(&posixThreadAttrId);
}

bool Thread::isStarted()
{
    return m_chrono.isActive();
}

void Thread::join()
{
    pthread_join(posixThreadId, NULL);
}

long Thread::duration_ms()
{
    return m_chrono.lap_ms();
}

void* Thread::call_run(void* v_Thread) 
{
    Thread* p_thread = (Thread*) v_Thread;
    p_thread->start();
    return v_Thread;
}

int Thread::getMaxPrio(int policy)
{
    return sched_get_priority_max(policy);
}

int Thread::getMinPrio(int policy)
{
    return sched_get_priority_min(policy);
}

void Thread::setMainSched(int policy)
{
    sched_param schedParams;
    schedParams.sched_priority = getMinPrio(policy);
    pthread_setschedparam(pthread_self(), policy, &schedParams);
}

int Thread::getMainSched(int policy)
{
    sched_param schedParams;
    pthread_getschedparam(pthread_self(), &policy, &schedParams);
    return schedParams.sched_priority;
}