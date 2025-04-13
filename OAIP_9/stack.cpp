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

void editPatient(Stack*& top, int pos) {
	if (top == nullptr) {
		cerr << endl << "Стек пуст. Редактирование невозможно.";
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
		cerr << endl << "Запись пациента с таким номером отсутствует.";
		while (tempStack) {
			Stack* temp = tempStack;
			tempStack = tempStack->next;
			temp->next = top;
			top = temp;
		}
		return;
	}	
	string str;
	int choice = 0;
	do {		
		cout << endl << "0. Завершить редактирование";
		cout << endl << "1. Имя";
		cout << endl << "2. Дата рождения";
		cout << endl << "3. Номер медкарты";
		cout << endl << "4. Диагноз";
		cout << endl << "5. Дата последнего визита";		
		cout << endl << "Выберите поле для редактирования: ";
		cin >> str;
		if (check(str)) {
			choice = stoi(str);
		}
	} while (!check);
	cin.ignore();
	switch (choice) {
	case 1:
		cout << endl << "Ввод нового имени.";
		input_name(top, 1);
		break;
	case 2:
		cout << endl << "Ввод новой даты рождения.";
		input_birthdate(top, 1);
		break;
	case 3:
		cout << endl << "Ввод нового номера медкарты.";
		input_medcardNumber(top, 1);
		cin.ignore();
		break;
	case 4:
		cout << endl << "Ввод нового диагноза.";
		input_diagnosis(top, 1);
		break;
	case 5:
		cout << endl << "Ввод новой даты последнего визита.";
		input_lastVisitDate(top, 1);
		break;
	case 0:
		cout << endl << "Редактирование завершено.";
		break;
	default:
		cout << endl << "Неверный выбор. Повторите попытку.";
	}	
	while (tempStack) {
		Stack* temp = tempStack;
		tempStack = tempStack->next;
		temp->next = top;
		top = temp;
	}
}

void push(Stack*& top, const Patient& patient) {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));	
	newNode->data = patient;
	newNode->next = top;
	top = newNode;
}

void clear(Stack*& top) {
	while (top) {
		Stack* temp = top;
		top = top->next;
		free(temp);
	}
}