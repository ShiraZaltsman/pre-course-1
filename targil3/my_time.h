//
// Created by shira on 8/15/19.
//

#ifndef TARGIL3_MY_TIME_H
#define TARGIL3_MY_TIME_H
#include <iostream>
//using namespace std;

class Time{
public:
    Time(unsigned int h, unsigned char m, unsigned char s=0);
    Time(unsigned int s);
    const std::string get_as_str(bool is_using_days) const;
    const unsigned int get_seconds() const;
    static void set_dalimiter(char day, char time);

    // Overload operators
    Time operator+(Time t);

    Time operator+(unsigned int s);

    Time& operator+=(unsigned long s);

    friend void time_reset(Time* time_);
private:
    unsigned int hours;
    unsigned char minutes;
    unsigned char seconds;
    static char day_delimiter;
    static char time_delimiter;
    static const unsigned int  hour_rang=100000;
    static const unsigned char min_rang=60;
    static const unsigned char sec_rang=60;

    friend std::ostream& operator<<(std::ostream& out, const Time& t);
};

void print(Time* t);


// Overload operators
Time operator+(unsigned int s,Time t);
bool operator< (const Time& t1, const Time& t2);
bool operator> (const Time& t1, const Time& t2);
bool operator<=(const Time& t1, const Time& t2);
bool operator>=(const Time& t1, const Time& t2);
bool operator==(const Time& t1, const Time& t2);
bool operator!=(const Time& t1, const Time& t2);





#endif //TARGIL3_MY_TIME_H
