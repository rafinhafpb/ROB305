#include "Counter.h"
#include "Incrementer.h"
#include "Chrono.h"
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <sched.h>
#include <iomanip>

int main(int argc, char* argv[])
{
    // ----------- TEST CLASSES THREAD, COUNTER AND INCREMENTER ----------
    if (argc < 3 || argc > 5)
    {
        std::cerr << "Usage: " << argv[0] << " <nLoops> <nTasks> [protect] [policy]" << std::endl;
        return 1;
    }

    int nLoops = atoi(argv[1]);
    int nTasks = atoi(argv[2]);
    bool protect = (argc > 3) ? atoi(argv[3]) : false;

    int policy = SCHED_OTHER; // Default scheduling policy
    if (argc == 5)
    {
        if (strcmp(argv[4], "SCHED_RR") == 0)
            policy = SCHED_RR;
        else if (strcmp(argv[4], "SCHED_FIFO") == 0)
            policy = SCHED_FIFO;
        else if (strcmp(argv[4], "SCHED_OTHER") != 0)
        {
            std::cerr << "Invalid scheduling policy. Use SCHED_OTHER, SCHED_RR, or SCHED_FIFO." << std::endl;
            return 1;
        }
    }

    // Set scheduling policy
    sched_param schedParam;
    schedParam.sched_priority = (policy == SCHED_OTHER) ? 0 : sched_get_priority_max(policy);
    if (sched_setscheduler(0, policy, &schedParam) != 0)
    {
        perror("sched_setscheduler");
        return 1;
    }

    Counter counter(protect);
    std::vector<std::unique_ptr<Incrementer>> incrementers;

    Chrono chrono;

    for (int i = 0; i < nTasks; i++)
    {
        incrementers.emplace_back(std::make_unique<Incrementer>(i, counter, nLoops));
        incrementers.back()->start();
    }

    for (auto& incrementer : incrementers)
    {
        incrementer->join();
    }

    chrono.stop();

    // Display results
    int expectedValue = nTasks * nLoops;
    int finalValue = counter.value();
    double percentage = (static_cast<double>(finalValue) / expectedValue) * 100.0;

    std::cout << "\nResults:" << std::endl;
    std::cout << "Final counter value: " << finalValue << std::endl;
    std::cout << "Expected value: " << expectedValue << std::endl;
    std::cout << "Accuracy: " << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;
    std::cout << "Execution time: " << std::fixed << std::setprecision(1) << chrono.lap_ms() << " milliseconds" << std::endl;

    return 0;
}