#ifndef INCREMENTER_H
#define INCREMENTER_H

#include "Thread.h"
#include "Counter.h"

class Incrementer : public Thread
{
public:
    Incrementer(int id, Counter& counter, double nLoops);
private:
    const double nLoops;
    Counter& r_counter;
    void run() override;
};

#endif