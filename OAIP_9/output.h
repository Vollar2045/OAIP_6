#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <iomanip>
#include "stack.h"
using namespace std;

void printPatient(Stack* top);
void printTab(Stack* top);
void output_menu(int m);
void error_create();
void error_initMem();
void error_delete(string filename);
void success_del(string filename);
void success_save(string filename);
void success_read(string filename);
void error_open1();
void error_open2();
void error_choice();

#endif
