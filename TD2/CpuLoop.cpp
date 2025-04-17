#include "CpuLoop.h"

CpuLoop::CpuLoop(Calibrator& calibrator) : m_calibrator(calibrator) { }

double CpuLoop::runTime(double duration_ms)
{
    chrono.restart();

    runLoop(m_calibrator.nLoops(duration_ms)); // Run the CPU-consuming loop

    double actual_duration_ms = chrono.lap_ms(); // Measure the actual duration in milliseconds

    return (actual_duration_ms - duration_ms) / duration_ms;
}