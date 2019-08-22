//
// Created by shira on 8/19/19.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include "msg_printer.h"
using namespace std;

MsgPrinter::MsgPrinter(string m_) :message(m_){}

MsgPrinter::~MsgPrinter() {

    cout<<"End of MsgPrinter: "<<this->message<<endl;
}

void MsgPrinter::print() {
    cout<<"Message: "<<this->message<<" ";
}

MsgPrinterSurrounding::MsgPrinterSurrounding(string str) : MsgPrinter(str) {
    this->before=NULL;
    this->after=NULL;
}

MsgPrinterSurrounding::MsgPrinterSurrounding(string str, const char* before_msg,
        const char* after_msg) : MsgPrinter(str){
    this->before=new char[strlen(before_msg) + 1];
    strcpy(before, before_msg);
    this->after=new char[strlen(after_msg) + 1];
    strcpy(after, after_msg);

}

MsgPrinterSurrounding::~MsgPrinterSurrounding() {
    delete[] before;
    delete[] after;
    cout<<"End of MsgPrinterSorrounding: "<<this->message<<endl;
}

void MsgPrinterSurrounding::print_before() {
    if(this->before) {
        cout << this->before;
    }

}

void MsgPrinterSurrounding::print_after() {
    if (this->after) {
        cout << this->after;
    }
}

void MsgPrinterSurrounding::print() {
    this->print_before();
    MsgPrinter::print();
    this->print_after();
    cout<<endl;
}

MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(std::string str, const char *before_msg,
                                                             const char *after_msg,
                                                             unsigned char times_) :
                                                             MsgPrinterSurrounding(str, before_msg, after_msg),
                                                             times(times_){


}

unsigned char MsgPrinterMultipleSurrounding::get_times() const {
    return this->times;
}

void MsgPrinterMultipleSurrounding::set_times(unsigned char times_) {
    this->times = times_;
}

void MsgPrinterMultipleSurrounding::print_before() {
    for (unsigned char i = 0; i < this->times; ++i) {
        MsgPrinterSurrounding::print_before();
    }

}

void MsgPrinterMultipleSurrounding::print_after() {
    for (unsigned char i = 0; i < this->times; ++i) {
        MsgPrinterSurrounding::print_after();
    }
}

MsgPrinterMultipleSurrounding::~MsgPrinterMultipleSurrounding() {
    cout<<"End of MsgPrinterMultipleSurrounding: "<<this->message<<endl;
}
