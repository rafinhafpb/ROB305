#include <iostream>
#include <time.h>
#include <signal.h>

void MyHandler(int , siginfo_t* si, void*) 
{ 
    int* p_counter = (int*) si->si_value.sival_ptr;
    *p_counter += 1;
    std::cout << "Counter: " << *p_counter << std::endl;
}

int main() 
{
    // ----------- TEST POSIX TIMERS WITH CALLBACK ----------
    int counter = 0;
    int* myData = &counter;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = MyHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) myData;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 5 * 1e8;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 5 * 1e8;
    timer_settime(tid, 0, &its, nullptr);
    while(counter < 15) {}
    std::cout << "Counter reached 15" << std::endl;
    timer_delete(tid);

}