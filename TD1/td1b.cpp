#include "timespec.h"
#include "Chrono.h"
#include <iostream>

using namespace std;

int main() {
    // ----------- TEST CLASS CHRONO -----------
    cout << "\n---- test class chrono -----\n" << endl;

    Chrono chrono;
    cout << "Cronometer status: " << chrono.isActive() << endl;

    timespec_wait(timespec_from_ms(1000));
    chrono.stop();
    cout << "Crono time after timespec wait: " << chrono.lap().tv_sec << " seconds, " << chrono.lap().tv_nsec << " nanoseconds." << endl;
    cout << "Crono time in milliseconds: " << chrono.lap_ms() << endl;
    cout << "Cronometer status: " << chrono.isActive() << endl;

    chrono.restart();
    timespec_wait(timespec_from_ms(569));
    cout << "Crono time after timespec wait: " << chrono.lap().tv_sec << " seconds, " << chrono.lap().tv_nsec << " nanoseconds." << endl;
    cout << "Crono time in milliseconds: " << chrono.lap_ms() << endl;
    cout << "Cronometer status: " << chrono.isActive() << endl;
}