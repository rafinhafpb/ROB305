#include "CpuLoop.h"
#include "Chrono.h"

CpuLoop::CpuLoop(Calibrator& calibrator) : m_calibrator(calibrator) { }

double CpuLoop::runTime(double duration_ms)
{
    Chrono chrono; // Create a Chrono object to measure time
    chrono.restart(); // Start the timer

    looper.runLoop(m_calibrator.nLoops(duration_ms)); // Run the CPU-consuming loop

    double actual_duration_ms = chrono.lap_ms(); // Measure the actual duration in milliseconds

    // Calculate the relative error: (actual - expected) / expected
    double relative_error = (actual_duration_ms - duration_ms) / duration_ms;

    return relative_error; // Return the relative error
}