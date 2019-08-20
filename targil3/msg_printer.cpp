//
// Created by shira on 8/19/19.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include "msg_printer.h"

MsgPrinter::MsgPrinter(string m) :message(m){

}

MsgPrinter::~MsgPrinter() {

    cout<<"End of MsgPrinter: "<<this->message<<endl;
}

void MsgPrinter::print() {
    cout<<"Message: "<<this->message<<endl;
}

MsgPrinterSurrounding::MsgPrinterSurrounding(string str) : MsgPrinter(str) {
    this->before=NULL;
    this->after=NULL;
}

MsgPrinterSurrounding::MsgPrinterSurrounding(string str, const char* before_msg,  const char* after_msg) : MsgPrinter(str){
    this->before=new char[sizeof before_msg];
    strcpy(before, before_msg);
    this->after=new char[sizeof after_msg];
    strcpy(after, after_msg);

}

MsgPrinterSurrounding::~MsgPrinterSurrounding() {
    delete[] before;
    delete[] after;
    cout<<"End of MsgPrinterSorrounding: "<<this->message<<endl;
}

void MsgPrinterSurrounding::print_before() {
    if(this->before) {
        cout << this->before<<endl;
    }

}

void MsgPrinterSurrounding::print_after() {
    if (this->after) {
        cout << this->after<<endl;
    }
}

void MsgPrinterSurrounding::print() {
    this->print_before();
    MsgPrinter::print();
    this->print_after();
}
