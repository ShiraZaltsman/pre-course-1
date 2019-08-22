//
// Created by shira on 8/19/19.
//

#ifndef TARGIL3_MSG_PRINTER_H
#define TARGIL3_MSG_PRINTER_H

#include <string>

class MsgPrinter{
public:
    explicit MsgPrinter(std::string m);
    virtual ~MsgPrinter();
    virtual void print();

protected:
    const std::string message;
};

class MsgPrinterSurrounding: public MsgPrinter{
private:
    char* before;
    char* after;

public:
    MsgPrinterSurrounding(std::string str);
    MsgPrinterSurrounding(std::string str, const char* before_msg,  const char* after_msg);
    ~MsgPrinterSurrounding();
    void print();

protected:
    virtual void print_before();
    virtual void print_after();
};

class MsgPrinterMultipleSurrounding: public MsgPrinterSurrounding{
public:
    MsgPrinterMultipleSurrounding(std::string str, const char* before_msg,
                                    const char* after_msg, unsigned char times_=2);
    ~MsgPrinterMultipleSurrounding();
    unsigned char get_times() const;
    void set_times(unsigned char times);
    void print_before();
    void print_after();

private:
    unsigned char times;
};

#endif //TARGIL3_MSG_PRINTER_H
