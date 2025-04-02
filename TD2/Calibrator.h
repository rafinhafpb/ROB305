#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "Timer.h"
#include "Looper.h"
#include <vector>

class Calibrator : Timer
{
public:
    Calibrator(double samplingPeriod_ms, unsigned nSamples);
    double nLoops(double duration_ms) const;
    Looper looper;

private:
    double a;
    double b;
    std::vector<double> samples;
    unsigned nSamples;

protected:
    void callback();
};


#endif