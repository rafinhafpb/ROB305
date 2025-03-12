#include "CountDown.h"
#include <iostream>

CountDown::CountDown(int n) : Timer(),  m_counter(n) {}

void CountDown::callback()
{
    if (m_counter > 0)
    {
        m_counter--;
    }
}