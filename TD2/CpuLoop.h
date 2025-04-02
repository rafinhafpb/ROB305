#ifndef CPULOOP_H
#define CPULOOP_H

#include "Calibrator.h"

class CpuLoop
{
public:
    CpuLoop(Calibrator& calibrator);
    double runTime(double duration_ms);

private:
    Calibrator& m_calibrator;
    Looper looper;
};

#endif