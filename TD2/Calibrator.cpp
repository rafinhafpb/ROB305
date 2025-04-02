#include "Calibrator.h"
#include <climits>

Calibrator::Calibrator(double samplingPeriod_ms, unsigned nSamples) : nSamples(nSamples)
{
    start_ms(samplingPeriod_ms, true);
    samples.reserve(nSamples); // Reserve memory for nSamples elements
    looper.runLoop();

    // Linear Regression Calculation
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (unsigned i = 0; i < nSamples; ++i) 
    {
        double x = i * samplingPeriod_ms;
        double y = samples[i];
        sumX += x;
        sumY += y;
        sumXY += x * y;
        sumX2 += x * x;
    }
    double denominator = nSamples * sumX2 - sumX * sumX;
    a = (nSamples * sumXY - sumX * sumY) / denominator;
    b = (sumY * sumX2 - sumX * sumXY) / denominator;
}

void Calibrator::callback()
{
    samples.push_back(looper.getSample());
    if (samples.size() >= nSamples) 
    {
        looper.stopLoop();
        stop();
    }
}

double Calibrator::nLoops(double duration_ms) const
{
    return a * duration_ms + b;
}