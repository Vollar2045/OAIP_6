#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

struct Patient {
    char name[100];
    char birthDate[11];
    int medicalCardNumber;
    char diagnosis[50];
    char lastVisitDate[11];
};

struct Stack {
    Patient data;
    Stack* next;
};

void addPatient(Stack*& top);
void clear(Stack*& top);
void add_memory(Stack*& top);

#endif