#include "Looper.h"
#include "Chrono.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // ----------- TEST CLASS LOOPER ----------
    std::cout << "argc: " << argc << std::endl; 
    double nLoops = atoi(argv[1]);
    Looper looper;
    Chrono chrono;
    chrono.restart();
    looper.runLoop(nLoops);
    chrono.stop();
    std::cout << "nLoops: " << nLoops << " - Time: " << chrono.lap_ms() << " ms" << std::endl;
    return 0;
}