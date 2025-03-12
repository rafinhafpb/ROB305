#include "Looper.h"
#include "Chrono.h"
#include <iostream>

int main(int argc, char* argv[])
{
    double nLoops = atoi(argv[1]);
    Looper looper;
    looper.runLoop(nLoops);
}