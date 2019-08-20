//
// Created by shira on 8/15/19.
//

#include "my_time.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

Time::Time(unsigned int h, unsigned short m, unsigned short s) {
    if(h < 0 || h > 100000){
        throw invalid_argument("hours is not valid");
    }
    if(m < 0 || m > 59){
        throw invalid_argument("minutes is not valid");
    }
    if(m < 0 || m > 59){
        throw invalid_argument("minutes is not valid");
    }
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
    this->set_dalimiter('.',':');

}

Time::Time(size_t s) {
    this->hours=s/3600;
    this->minutes=(s-(this->hours*3600))/60;
    this->seconds=s-(this->hours*3600)-(this->minutes*60);
}

const char * Time::get_as_str(bool is_using_days) const {
    char *time=new char[30];
    if(is_using_days){
        int days=this->hours/24;
        int h=this->hours-(days*24);
        if (this->minutes < 10 && this->seconds < 10) {
            sprintf(time, "%d.%d:0%d:0%d", days, h, this->minutes, this->seconds);
        }else if(this->minutes < 10){
            sprintf(time, "%d.%d:0%d:%d", days, h, this->minutes, this->seconds);
        }else if (this->seconds < 10){
            sprintf(time, "%d.%d:%d:0%d", days, h, this->minutes, this->seconds);
        }else{
            sprintf(time, "%d.%d:%d:%d", days, h, this->minutes, this->seconds);
        }

    }else{
        if (this->minutes < 10 && this->seconds < 10) {
            sprintf(time, "%d:0%d:0%d", this->hours, this->minutes, this->seconds);
        }else if(this->minutes < 10){
            sprintf(time, "%d:0%d:%d", this->hours, this->minutes, this->seconds);
        }else if (this->seconds < 10){
            sprintf(time, "%d:%d:0%d", this->hours, this->minutes, this->seconds);
        }else{
            sprintf(time, "%d:%d:%d", this->hours, this->minutes, this->seconds);
        }
    }
    return time;
}

const int Time::get_seconds() const {
    const int sec=(this->seconds)
            +
            (this->minutes*60)
            +
            (this->hours*3600);
    return sec;
}

Time Time::operator+(Time t) {
    const int sec1=this->get_seconds();
    const int sec2=t.get_seconds();
    Time time=Time(sec1+sec2);
    return time;
}

Time Time::operator+(unsigned long s) {
    long sec=s+this->get_seconds();
    Time time=Time(sec);
    return time;

}

Time& Time::operator+=(unsigned long s) {
    long sec=s+this->get_seconds();
    this->hours=sec/3600;
    this->minutes=(sec-(this->hours*3600))/60;
    this->seconds=sec-(this->hours*3600)-(this->minutes*60);
    return *this;

}
char Time::time_delimiter;
char Time::day_delimiter;

 void Time::set_dalimiter(char day, char time) {
    if (isdigit(day) || isdigit(time)){
        throw invalid_argument("dalimiter can't be a digit!");
    }
    else{
        time_delimiter=time;
        day_delimiter=day;
    }

}

void print(Time* t) {
    string str = t->get_as_str(true);
    std::replace(str.begin(), str.end(), ':', '/');
    std::replace(str.begin(), str.end(), '.', '/');
    cout<<str;

}

Time operator+(unsigned long s, Time t) {
    long sec=s+t.get_seconds();
    Time time=Time(sec);
    return time;
}

bool operator>(const Time &t1, const Time &t2) {
    return (t1.get_seconds() > t2.get_seconds());
}

bool operator<(const Time &t1, const Time &t2) {
    return (t1.get_seconds() < t2.get_seconds());
}

bool operator<=(const Time &t1, const Time &t2) {
    return (t1.get_seconds() <= t2.get_seconds());
}

bool operator>=(const Time &t1, const Time &t2) {
    return (t1.get_seconds() >= t2.get_seconds());
}

bool operator==(const Time &t1, const Time &t2) {
    return (t1.get_seconds() == t2.get_seconds());
}

bool operator!=(const Time &t1, const Time &t2) {
    return (t1.get_seconds() != t2.get_seconds());
}

std::ostream &operator<<(std::ostream &out, const Time &t) {
    return out<<t.get_as_str(true);
}

