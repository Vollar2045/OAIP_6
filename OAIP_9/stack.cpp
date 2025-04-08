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

void deletePatient(Stack*& top, int pos) {
	if (top == nullptr) {
		cerr << "Стек пуст. Удаление невозможно." << endl;
		return;
	}
	Stack* tempStack = nullptr;	
	int currentPos = 1;
	while (top != nullptr && currentPos < pos) {
		Stack* temp = top;
		top = top->next;
		temp->next = tempStack;
		tempStack = temp;
		currentPos++;
	}
	if (top == nullptr) {
		cerr << "Запись пациента с таким номером отсутствует." << endl;
		while (tempStack) {
			Stack* temp = tempStack;
			tempStack = tempStack->next;
			temp->next = top;
			top = temp;
		}
		return;
	}
	pop(top);
	while (tempStack) {
		Stack* temp = tempStack;
		tempStack = tempStack->next;
		temp->next = top;
		top = temp;
	}
	cout << "Запись пациента на позиции " << pos << " удалена." << endl;
}

Patient pop(Stack*& top) {
	if (top == nullptr) {
		cerr << endl << "Стек пуст. Удаление невозможно." << endl;		
		Patient emptyPatient = { "", "", 0, "", "" };
		return emptyPatient;
	}
	Stack* temp = top;
	Patient poppedPatient = temp->data; 
	top = top->next;
	free(temp); 
	return poppedPatient;
}

void push(Stack*& top, const Patient& patient) {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));	
	newNode->data = patient;
	newNode->next = top;
	top = newNode;
}

Patient peek(Stack* top) {
	if (top == nullptr) {
		cerr << endl << "Стек пуст. Невозможно получить значение." << endl;
		Patient emptyPatient = { "", "", 0, "", "" };
		return emptyPatient;
	}
	return top->data;
}

void clear(Stack*& top) {
	while (top) {
		Stack* temp = top;
		top = top->next;
		free(temp);
	}
}