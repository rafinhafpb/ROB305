#ifndef LOOPER_H
#define LOOPER_H

class Looper
{
    public:
        double runLoop(double nLoops = __DBL_MAX__);
        double getSample() {return iLoop;};
        const void stopLoop() {doStop = true;};

    private:
        bool doStop;
        double iLoop;
};


#endif