#ifndef FILE_H
#define FILE_H

#include "stack.h"
#include <fstream>
#include <string>
using namespace std;

ofstream new_DB(const string& filename);
void save_DB(const string& filename, Stack* top);
void load_DB(const string& filename, Stack*& top);
void remove_DB(const string& filename);

#endif