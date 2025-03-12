#include "Looper.h"

Looper::Looper()
{
    double doStop = true;
    double iLoop = 0;
}

double Looper::runLoop(double nLoops)
{
    double iLoop = 0;
    doStop = false;

    while (iLoop < nLoops && !doStop)
    {
        iLoop++;
    }
    return iLoop;
}
