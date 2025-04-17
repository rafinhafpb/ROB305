#include "Calibrator.h"
#include "Chrono.h"
#include "CpuLoop.h"
#include <iostream>
#include <iomanip> // For formatting output

int main() 
{
    // ----------- TEST CLASS CPULOOP ----------
    const double samplingPeriod_ms = 200; // Sampling period for calibrator
    const unsigned nSamples = 10;         // Number of samples for calibrator
    const double testDuration_ms = 10000; // Total test duration
    const double loopDuration_ms = 200;   // Duration for each CpuLoop run

    Calibrator calibrator(samplingPeriod_ms, nSamples);
    CpuLoop cpuLoop(calibrator);

    for(double run_time = 0; run_time <= testDuration_ms; run_time += loopDuration_ms) 
    {
        double relative_error = cpuLoop.runTime(run_time);
        std::cout << "Time: " << run_time << " ms - Relative Error: " << relative_error << " %" << std::endl;
    }

    return 0;
}