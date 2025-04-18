#include "Calibrator.h"
#include "Chrono.h"
#include <iostream>

int main() 
{
    // ----------- TEST CLASS CALIBRATOR ----------
    const double samplingPeriod_ms = 200; // Sampling period for calibrator
    const unsigned nSamples = 10;         // Number of samples for calibrator
    const double testDuration_ms = 10000; // Total test duration
    const double loopDuration_ms = 200;   // Duration for each CpuLoop run
    double run_time = 0;

    Calibrator calibrator(samplingPeriod_ms, nSamples);
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
                    std::cout << "Time: " << run_time << " ms - nLoops: " << calibrator.nLoops(run_time) << std::endl;
                    run_time += chrono.lap_ms();
                    chrono.restart();
                }
            }
            break;
        }
    }
    return 0;
}