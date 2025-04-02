#include <pthread.h>
#include <iostream>
#include "Mutex.h"

struct Data 
{
    Data() : stop(false), counter(0) {}
    volatile bool stop;
    volatile double counter;
    Mutex mutex;
};


void* incrementer(void* v_data)
{
    Data* p_data = (Data*) v_data;

    while (!p_data->stop)
    {
        Mutex::Lock lock(p_data->mutex);
        p_data->counter += 1.0;
    }
    return v_data;
}

int main()
{
    Data data;
    pthread_t incrementThread[3];
    pthread_create(&incrementThread[0], nullptr, incrementer, (void*) &data);
    pthread_create(&incrementThread[1], nullptr, incrementer, (void*) &data);
    pthread_create(&incrementThread[2], nullptr, incrementer, (void*) &data);
    
    for (char cmd = 'r'; cmd != 's'; std::cin >> cmd)
        std::cout << "Type 's' to stop: " << std::flush;
    data.stop = true;

    for (int i=0; i<3; i++) 
        pthread_join(incrementThread[i], nullptr);

    std::cout << "Counter value: " << data.counter << std::endl;
}