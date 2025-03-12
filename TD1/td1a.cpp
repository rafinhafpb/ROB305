#include "timespec.h"
#include "Chrono.h"
#include <iostream>

using namespace std;

int main(){

    // ----------- TEST 1 -----------

    timespec time_ts, time_neg;
    double time_ms = 2700;

    cout << "\n----first test-----\n" << endl;

    time_ts = timespec_from_ms(time_ms);
    cout << "timespec variable: " << time_ts.tv_sec << " seconds, " << time_ts.tv_nsec << " nanoseconds." << endl;

    time_ms = timespec_to_ms(time_ts);
    cout << "milliseconds variable: " << time_ms << " milliseconds." << endl;

    timespec time_now = timespec_now();
    cout << "timespec now: " << time_now.tv_sec << " seconds, " << time_now.tv_nsec << " nanoseconds." << endl;

    time_neg = timespec_negate(time_ts);
    cout << "timespec after negate: " << time_neg.tv_sec << " seconds, " << time_neg.tv_nsec << " nanoseconds." << endl;

    time_neg = timespec_negate(time_neg);
    cout << "timespec negate again: " << time_neg.tv_sec << " seconds, " << time_neg.tv_nsec << " nanoseconds." << endl;


    // ----------- TEST 2 -----------

    timespec time_1, time_2, time_sum, time_sub, time_delay;

    cout << "\n----second test-----\n" << endl;

    time_1 = timespec_from_ms(3500);
    time_2 = timespec_from_ms(4250);

    time_sum = timespec_add(time_1, time_2);
    cout << "timespec after addition: " << time_sum.tv_sec << " seconds " << time_sum.tv_nsec << " nanoseconds." << endl;

    time_sub = timespec_subtract(time_1, time_2);
    cout << "timespec after subtract: " << time_sub.tv_sec << " seconds " << time_sub.tv_nsec << " nanoseconds." << endl;

    time_delay = timespec_from_ms(1000);
    timespec_wait(time_delay);
    cout << "Print after delay of " << time_delay.tv_sec << " seconds and " << time_delay.tv_nsec / 1e6 << " milliseconds." << endl;


    // ----------- TEST 3 -----------

    cout << "\n----third test-----\n" << endl;

    time_sum = time_1 + time_2;
    cout << "timespec after operator +: " << time_sum.tv_sec << " seconds " << time_sum.tv_nsec << " nanoseconds." << endl;

    time_sub = time_1 - time_2;
    cout << "timespec after operator - (subtract): " << time_sub.tv_sec << " seconds " << time_sub.tv_nsec << " nanoseconds." << endl;

    time_1 = -time_1;
    cout << "timespec after operator - (negate): " << time_1.tv_sec << " seconds " << time_1.tv_nsec << " nanoseconds." << endl;

    time_1 += time_2;
    cout << "timespec after operator +=: " << time_1.tv_sec << " seconds " << time_1.tv_nsec << " nanoseconds." << endl;

    time_2 -= time_1;
    cout << "timespec after operator -=: " << time_2.tv_sec << " seconds " << time_2.tv_nsec << " nanoseconds." << endl;

    cout << "comparators between " << time_1.tv_sec << " seconds " << time_1.tv_nsec << " nanoseconds and " << time_2.tv_sec << " seconds " << time_2.tv_nsec << " nanoseconds\n" // ...
    << "equals: " << (time_1 == time_2) << "\ndifferent: " << (time_1 != time_2) << "\nfirst greater than second: " << (time_1 > time_2) << "\nfirst smaller than second: " << (time_1 < time_2) << endl;

    return 0;
}