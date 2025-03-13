#include "Calibrator.h"
#include "Chrono.h"
#include <iostream>

int main() {
    double samplingPeriod_ms = 200;
    unsigned nSamples = 10;
    double run_time = 0;

    Calibrator calibrator(samplingPeriod_ms, nSamples);
    Chrono chrono;

    while (true) {
        if (chrono.lap_ms() >= 500){
            run_time += chrono.lap_ms();
            chrono.restart();

            while (run_time <= 10000) {
                if (chrono.lap_ms() >= 200) {
                    std::cout << "Time: " << run_time << " - nLoops: " << calibrator.nLoops(run_time) << std::endl;
                    run_time += chrono.lap_ms();
                    chrono.restart();
                }
            }

            break;
        }
    }
    
    return 0;
}