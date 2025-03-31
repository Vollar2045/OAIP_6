#ifndef INPUT_H
#define INPUT_H

#include "stack.h"
#include <string>
using namespace std;

bool checkMenu(string N);
bool check(string str);
bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
void input_patient(Stack*& newNode);
void input_filename(string& filename, int m);
void input_str(string& str);

#endif