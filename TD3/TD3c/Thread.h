#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
#include "../TD2/Chrono.h"

class Thread
{
    private:
        pthread_attr_t posixThreadAttrId;
        pthread_t posixThreadId;
        static void* call_run(void* v_Thread);

    protected:
        virtual void run() = 0;
};

#endif