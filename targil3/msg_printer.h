//
// Created by shira on 8/19/19.
//

#ifndef TARGIL3_MSG_PRINTER_H
#define TARGIL3_MSG_PRINTER_H

#include <string>

using namespace std;
class MsgPrinter{
protected:
    const string message;

public:
    explicit MsgPrinter(string m);
    ~MsgPrinter();
    virtual void print();
};

class MsgPrinterSurrounding:public MsgPrinter{
private:
    char* before;
    char* after;

public:
    MsgPrinterSurrounding(string str);
    MsgPrinterSurrounding(string str, const char* before_msg,  const char* after_msg);
    ~MsgPrinterSurrounding();
    void print();

protected:
    virtual void print_before();
    void print_after();
};

#endif //TARGIL3_MSG_PRINTER_H
