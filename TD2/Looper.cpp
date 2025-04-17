#include "Looper.h"

Looper::Looper()
{
    doStop = true;
    iLoop = 0;
};

double Looper::runLoop(double nLoops)
{
    iLoop = 0;
    doStop = false;

    while (iLoop < nLoops && !doStop)
    {
        iLoop += 1.0;
    }
    return iLoop;
};
