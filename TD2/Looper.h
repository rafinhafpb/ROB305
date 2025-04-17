#ifndef LOOPER_H
#define LOOPER_H

class Looper
{
public:
    Looper();
    double runLoop(double nLoops = __DBL_MAX__);
    double getSample() const {return iLoop;};
    void stopLoop() {doStop = true;};

private:
    volatile bool doStop;
    double iLoop;
};


#endif