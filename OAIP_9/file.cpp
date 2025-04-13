#include "file.h"
#include "output.h"
#include <iostream>
using namespace std;

ofstream new_DB(const string& filename) {
	ofstream file(filename, ios::out | ios::trunc);
	if (!file) {
		error_create();
	}
	return file;
}

void remove_DB(const string& filename) {
	if (remove(filename.c_str()) != 0) {
		error_delete(filename);
	}
	else {
		success_del(filename);
	}
}

void save_DB(const string& filename, Stack* top) {
	ofstream file(filename, ios::binary | ios::out);
	if (!file) {
		error_open1();
		return;
	}
	Stack* current = top;
	while (current) {
		file.write(reinterpret_cast<char*>(&current->data), sizeof(Patient));
		current = current->next;
	}
	file.close();
	success_save(filename);
}

void save_DB_txt(const string& filename, Stack* top) {	
	ofstream file(filename);
	if (!file) {
		cerr << "Ошибка при открытии файла!" << endl;
		return;
	}
	file << "Имя | Дата рождения | Номер карты | Диагноз | Дата последнего визита" << endl;
	file << "------------------------------------------------------------" << endl;
	Stack* current = top;
	while (current) {
		file << current->data.name << " | "
			<< current->data.birthDate << " | "
			<< current->data.medicalCardNumber << " | "
			<< current->data.diagnosis << " | "
			<< current->data.lastVisitDate << endl;
		current = current->next;
	}

	file.close(); 
	cout << "Данные успешно сохранены в файл " << filename << endl;
}

void load_DB(const string& filename, Stack*& top) {
	ifstream file(filename, ios::binary | ios::in);
	if (!file) {
		error_open2();
		return;
	}
	clear(top);
	Stack* tempStack = nullptr;
	while (true) {
		Stack* newNode = (Stack*)malloc(sizeof(Stack));
		if (!newNode) {
			error_initMem();
			break;
		}
		file.read(reinterpret_cast<char*>(&newNode->data), sizeof(Patient));
		if (file.eof()) {
			free(newNode);
			break;
		}
		newNode->next = tempStack;
		tempStack = newNode;
	}
	file.close();
	while (tempStack != nullptr) {
		Stack* temp = tempStack;
		tempStack = tempStack->next;
		temp->next = top;
		top = temp;
	}
	success_read(filename);
}