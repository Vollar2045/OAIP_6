#include "stack.h"
#include "output.h"
#include "input.h"
#include <iostream>
#include <iomanip>
using namespace std;

void addPatient(Stack*& top) {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	if (newNode == nullptr) {
		error_initMem();
		return;
	}
	input_patient(newNode);
	newNode->next = top;
	top = newNode;
}

void add_memory(Stack*& newNode) {
	newNode = (Stack*)malloc(sizeof(Stack));
}

void clear(Stack*& top) {
	while (top) {
		Stack* temp = top;
		top = top->next;
		free(temp);
	}
}