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
    double run_time = 0;

    Calibrator calibrator(samplingPeriod_ms, nSamples);
    CpuLoop cpuLoop(calibrator);
    Chrono chrono;

    while (true) 
    {
        if (chrono.lap_ms() >= 500)
        {
            run_time += chrono.lap_ms();
            chrono.restart();

            while (run_time <= testDuration_ms) 
            {
                if (chrono.lap_ms() >= loopDuration_ms) 
                {
                    double relativeError = cpuLoop.runTime(loopDuration_ms) * 100; // Get relative error in percentage
                    run_time += chrono.lap_ms();
                    chrono.restart();

                    // Print the results
                    std::cout << "Time: " << run_time << " ms - Relative Error: " << relativeError << " %" << std::endl;
                }
            }
            break;
        }
    }

    return 0;
}