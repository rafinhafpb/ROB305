#include "TimeoutException.h"
#include <iostream>

TimeoutException::TimeoutException(long timeout_ms) : timeout_ms(timeout_ms) 
{
    std::cerr << "Timeout of " << timeout_ms << "ms reached" << std::endl;
}