//
// Created by shira on 8/15/19.
//

#ifndef TARGIL3_MY_TIME_H
#define TARGIL3_MY_TIME_H
#include <iostream>
using namespace std;
class Time{
private:
    unsigned int hours;
    unsigned short minutes;
    unsigned short seconds;
    static char day_delimiter;
    static char time_delimiter;

public:
    Time(unsigned int h, unsigned short m, unsigned short s=0);
    Time(size_t s);
    const char * get_as_str(bool is_using_days) const;
    const int get_seconds() const;
    static void set_dalimiter(char day, char time);

    // Overload operators
    Time operator+(Time t);

    Time operator+(unsigned long s);

    Time& operator+=(unsigned long s);


};

void print(Time* t);


// Overload operators
Time operator+(unsigned long s,Time t);
bool operator< (const Time& t1, const Time& t2);
bool operator> (const Time& t1, const Time& t2);
bool operator<=(const Time& t1, const Time& t2);
bool operator>=(const Time& t1, const Time& t2);
bool operator==(const Time& t1, const Time& t2);
bool operator!=(const Time& t1, const Time& t2);

std::ostream& operator<<(std::ostream& out, const Time& t);



#endif //TARGIL3_MY_TIME_H
