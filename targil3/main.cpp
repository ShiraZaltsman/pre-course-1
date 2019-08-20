#include <iostream>
#include <unistd.h>
#include "my_time.h"
#include "msg_printer.h"
#include "my_timer.h"

using namespace std;
void  test_phase_1(){
    Time time1=Time(20000);
    Time time2=Time(3000);
    Time time4=Time(1278);
    cout<<time2.get_as_str(true)<<endl;
    Time time3=time1+time2;
    time2=6000+time2;
    time1+=300;
    cout<<time1.get_seconds()<<endl;
    cout<<(time1>time2)<<endl;
    cout<<(time1!=time2)<<endl;
    cout<<(time1==time2)<<endl;


}
void test_phase_2(){
/*    MsgPrinter msg1("msg_1");
    msg1.print();
    Time target(200);
    Timer* timer=new Timer(target,&msg1);
    //cout<<timer->tic();
    timer->tick(100);
    timer->tick(100);
    timer->tick("m");*/

    MsgPrinterSurrounding l=MsgPrinterSurrounding("msg", "bef", "after");
    l.print();

}

void run_timer_1(){
    Time target=Time(1, 30, 0);
    MsgPrinter* msg=new MsgPrinter("Hello World!");
    Timer timer=Timer(target,msg);
    for (int i = 0; i < 50; ++i) {
        cout<<i+1<<endl;
        timer.tick("Min", 2);
    }

}

void run_timer_2(){
    Time target=Time(7);
    MsgPrinter* msg=new MsgPrinter("Seven Seconds");
    Timer timer=Timer(target,msg);
    for (int i = 0; i < 10; ++i) {
        sleep(1);
        cout<<i+1<<endl;
        timer.tick();
    }

}
int main() {

    //test_phase_1();
    test_phase_2();
    //run_timer_1();
    //run_timer_2();

    return 0;
}
