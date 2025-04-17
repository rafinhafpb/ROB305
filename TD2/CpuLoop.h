#ifndef CPULOOP_H
#define CPULOOP_H

#include "Calibrator.h"
#include "Chrono.h"

class CpuLoop : public Looper
{
public:
    CpuLoop(Calibrator& calibrator);
    double runTime(double duration_ms);
    Chrono chrono;

private:
    Calibrator& m_calibrator;
};

#endif