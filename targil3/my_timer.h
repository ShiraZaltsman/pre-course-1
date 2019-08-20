//
// Created by shira on 8/19/19.
//

#ifndef TARGIL3_MY_TIMER_H
#define TARGIL3_MY_TIMER_H

#include "my_time.h"
#include "msg_printer.h"

class Timer{
private:
    Time target;
    Time clock;
    MsgPrinter* pprinter;

public:
    Timer(Time tar, MsgPrinter *p);

    void tick();
    void tick(long t);
    void tick (string str, int i=0);

    inline int tic(){ return 90;}
};

inline void Timer::tick() {
    int sec=clock.get_seconds();
    clock=Time(sec+1);
    if(clock>=target){
        pprinter->print();
    }

}

inline void Timer::tick(long t) {
    int sec=clock.get_seconds();
    clock=Time(sec+t);
    if(clock>=target){
        pprinter->print();
    }
}

inline void Timer::tick(string str,int i) {
    int sec=clock.get_seconds();
    if (str=="M" || str=="m" || str=="Min" || str=="min" || str=="Minute" || str=="minute"){
        clock=Time(sec+60*i);
    }
    else if (str=="H" || str=="h" || str=="Hour" || str=="hour"){
        clock=Time(sec+3600*i);
    }
    else{
        throw invalid_argument (str);
    }
    if(clock>=target){
        pprinter->print();
    }
}


#endif //TARGIL3_MY_TIMER_H
