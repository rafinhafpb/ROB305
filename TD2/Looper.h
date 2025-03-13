#ifndef LOOPER_H
#define LOOPER_H

class Looper
{
    public:
        Looper();
        double runLoop(double nLoops = __DBL_MAX__);
        double getSample() {return iLoop;};
        void stopLoop() {doStop = true;};

    private:
        bool doStop;
        double iLoop;
};


#endif