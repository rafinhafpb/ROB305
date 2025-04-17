#include "Counter.h"

Counter::Counter(bool protect) : m_value(0)
{
    if (protect)
    {
        p_mutex = std::make_unique<Mutex>();
    }
    else
    {
        p_mutex = nullptr;
    }
}

double Counter::increment()
{
    if (isProtected())
    {
        Mutex::Lock lock(*p_mutex);
        m_value += 1;
    }
    else
    {
        m_value += 1;
    }
    return m_value;
}