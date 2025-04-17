#ifndef COUNTER_H
#define COUNTER_H

#include "Mutex.h"
#include <stdlib.h>
#include <memory>

class Counter
{
public:
    Counter(bool protect);
    double increment();
    double value() {return m_value;};
    bool isProtected() {return p_mutex != nullptr;};
private:
    double m_value;
    std::unique_ptr<Mutex> p_mutex;
};


#endif