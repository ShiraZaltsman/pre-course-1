#include <iostream>
#include <unistd.h>
#include <list>
#include "my_time.h"
#include "msg_printer.h"
#include "my_timer.h"

using namespace std;
void test_phase_1(){
    cout<<"-------------------"<<endl;
    cout<<"test phase 1: "<<endl;
    Time time1=Time(500,50,40);
    time1.set_dalimiter('(',')');
    cout<<time1.get_as_str(true)<<endl;
    Time time2=Time(3000);
    time2.set_dalimiter('&','$');
    cout<<time2.get_as_str(true)<<endl;
    time2=6000+time2;
    time1+=300;

    cout<<(time1>time2)<<endl;
    cout<<(time1!=time2)<<endl;
    cout<<(time1==time2)<<endl;

}
void test_phase_2(){
    cout<<"-------------------"<<endl;
    cout<<"test phase 2: "<<endl;
    MsgPrinter msg1("msg_1");
    msg1.print();
    Time target(200);
    Timer* timer=new Timer(target,&msg1);
    //cout<<timer->tic();
    timer->tick(100);
    timer->tick(100);
    timer->tick("m");


}
void test_phase_3(){

    cout<<"test phase 3: "<<endl;
    MsgPrinterSurrounding l=MsgPrinterSurrounding("msg", "bef", "after");
    l.print();

}

void run_timer_1(){
    cout<<"run timer 3:"<<endl;
    Time target=Time(1, 30, 0);
    MsgPrinter msg("Hello World!");
    Timer timer=Timer(target,&msg);
    for (int i = 0; i < 50; ++i) {
        cout<<i+1<<endl;
        timer.tick("Min", 2);
    }
    cout<<endl<<"-----------------------------"<<endl;
}

void run_timer_2(){
    cout<<"run timer 2:"<<endl;
    Time target=Time(7);
    MsgPrinter msg("Seven Seconds");
    Timer timer=Timer(target,&msg);
    for (int i = 0; i < 10; ++i) {
        sleep(1);
        cout<<i+1<<endl;
        timer.tick();
    }

    cout<<endl<<"-----------------------------"<<endl;
}

void run_timer_3(){
    cout<<"run timer 3:"<<endl;
    MsgPrinter* printers[3];
    printers[0]=new MsgPrinter("This is the message");
    printers[1]=new MsgPrinterSurrounding("Surrounded",
                                "---Start---", "----End----");
    printers[2] = new MsgPrinterMultipleSurrounding ("Really Surrounded", ">>>>>>>" , "<<<<<<<", 3);

    Timer** timers=new Timer* [5];
    unsigned int sec=10;
    for (int i = 0; i < 5; ++i) {
        if (i < 1) {
            timers[i] = new Timer(sec, printers[0]);
        }
        else if(i < 3){
            timers[i] = new Timer(sec, printers[1]);
        }
        else{
            timers[i] = new Timer(sec, printers[2]);
        }

        sec += 5;
    }

    for (int j = 0; j < 40; ++j) {
        cout<<"itration: "<<j+1<<endl;
        for (int i = 0; i < 5; ++i) {
            timers[i]->tick();
        }

    }
    for (int k = 0; k < 3; ++k) {
        delete printers[k];
    }
    delete[]timers;
    cout<<endl<<"-----------------------------"<<endl;
}

void  run_timer_4(){

    cout<<"run timer 4"<<endl;
    list<Timer> timers_list;
    MsgPrinter* printers[3];
    printers[0]=new MsgPrinter("This is the message");
    printers[1]=new MsgPrinterSurrounding("Surrounded",
                                          "---Start---", "----End----");
    printers[2] = new MsgPrinterMultipleSurrounding ("Really Surrounded", ">>>>>>>" , "<<<<<<<", 3);

    timers_list.push_back(Timer(10, printers[0]));
    timers_list.push_back(Timer(15, printers[1]));
    timers_list.push_back(Timer(20, printers[1]));
    timers_list.push_back(Timer(25, printers[2]));
    timers_list.push_back(Timer(30, printers[2]));

    std::list<Timer>::iterator it;

    for (int i = 0; i < 80; ++i) {
        for (it = timers_list.begin(); it != timers_list.end(); ++it){
            it->tick();
        }
    }
    for (int k = 0; k < 3; ++k) {
        delete printers[k];
    }
    cout<<endl<<"-----------------------------"<<endl;
}
int main() {

    test_phase_1();
    //test_phase_2();
    //test_phase_3();
    //run_timer_1();
    //run_timer_2();
    //run_timer_3();
    //run_timer_4();
    return 0;
}
