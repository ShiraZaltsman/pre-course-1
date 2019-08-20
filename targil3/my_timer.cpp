//
// Created by shira on 8/19/19.
//

#include "my_timer.h"

Timer::Timer(Time tar, MsgPrinter *p):clock(Time(0)) ,target(tar) {
    this->pprinter=p;
}

