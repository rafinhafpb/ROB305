#include "Mutex.h"
#include "../../TD2/Calibrator.h"
#include "../TD3c/Thread.h"
#include "../../TD2/CpuLoop.h"
#include <iostream>

class Thread_A : public Thread
{
public:
    Thread_A(Calibrator& calibrator, Mutex& mutex) : Thread(0), cpuLoop(calibrator), m_mutex(mutex) {};

private:
    CpuLoop cpuLoop;
    Mutex& m_mutex;
    void run() override 
    {
        cpuLoop.runTime(100);
        {
            Mutex::Lock lock(m_mutex);
            cpuLoop.runTime(100);
        }
        cpuLoop.runTime(200);
    };
};

class Thread_B : public Thread
{
public:
    Thread_B(Calibrator& calibrator) : Thread(1), cpuLoop(calibrator) {};

private:
    CpuLoop cpuLoop;
    void run() override
    {
        cpuLoop.runTime(100);
    };
};

class Thread_C : public Thread
{
public:
    Thread_C(Calibrator& calibrator, Mutex& mutex) : Thread(2), cpuLoop(calibrator), m_mutex(mutex) {};

private:
    CpuLoop cpuLoop;
    Mutex& m_mutex;
    void run() override 
    {
        cpuLoop.runTime(200);
        {
            Mutex::Lock lock(m_mutex);
            cpuLoop.runTime(200);
        }
        cpuLoop.runTime(100);
    };
};

int main()
{
    // ----------- TEST SHARED RESSOURCES: INVERSION SAFE FALSE ----------
    Mutex ressource;
    Calibrator calibrator(200, 10);
    CpuLoop cpuLoop(calibrator);

    Thread_A task_A(calibrator, ressource);
    Thread_B task_B(calibrator);
    Thread_C task_C(calibrator, ressource);

    task_C.start(1);
    cpuLoop.runTime(300);
    task_A.start(3);
    task_B.start(2);

    std::cout << "\nResults Inversion Safe False:" << std::endl;
    std::cout << "Task A duration: " << task_A.duration_ms() << " ms" << std::endl;
    std::cout << "Task B duration: " << task_B.duration_ms() << " ms" << std::endl;
    std::cout << "Task C duration: " << task_C.duration_ms() << " ms" << std::endl;

    // ----------- TEST SHARED RESSOURCES: INVERSION SAFE TRUE ----------
    Mutex ressource_safe(true);

    Thread_A task_A_safe(calibrator, ressource_safe);
    Thread_B task_B_safe(calibrator);
    Thread_C task_C_safe(calibrator, ressource_safe);

    task_C_safe.start(1);
    cpuLoop.runTime(300);
    task_A_safe.start(3);
    task_B_safe.start(2);

    std::cout << "\nResults Inversion Safe True:" << std::endl;
    std::cout << "Task A duration: " << task_A_safe.duration_ms() << " ms" << std::endl;
    std::cout << "Task B duration: " << task_B_safe.duration_ms() << " ms" << std::endl;
    std::cout << "Task C duration: " << task_C_safe.duration_ms() << " ms" << std::endl;
}