#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "stack.h"
#include <string>
using namespace std;

bool compareNumber(int a, int b, bool ubivanie);
void shellSort_medCard(Stack*& top, bool ubivanie);
void shellSort_medCard1(Stack*& top, bool ubivanie);
bool diagnosisCompare(const char* a, const char* b, int choice);
int getOrder(char c);
void sort_diagnosis(Stack*& top, int choice);
void searchPatients(Stack*& top);
int getStackSize(Stack* top);
void insertSorted(Stack*& sorted, Patient p);
void sortStackByCardNumber(Stack*& originalTop, Stack*& sorted);
Patient getElementAt(Stack*& source, int index);
void binarySearchByCardNumber(Stack*& originalTop, int searchNumber);

#endif
