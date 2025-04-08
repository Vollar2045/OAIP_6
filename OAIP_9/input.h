#ifndef INPUT_H
#define INPUT_H

#include "stack.h"
#include <string>
using namespace std;

char toupper(char ñ);
char tolower(char ñ);
bool is_alpha(char ñ);
bool checkMenu(string N);
bool check(string str);
bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
void input_patient(Stack*& newNode);
string input_name(Stack*& top, bool isEditing);
string input_birthdate(Stack*& top, bool isEditing);
int input_medcardNumber(Stack*& top, bool isEditing);
string input_diagnosis(Stack*& top, bool isEditing);
string input_lastVisitDate(Stack*& top, bool isEditing);
void input_filename(string& filename, int m);
void input_toDelete(int& pos);
void input_direction(int& direction);
void input_search(int& fieldChoice);

#endif