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

void load_DB(const string& filename, Stack*& top) {
	ifstream file(filename, ios::binary | ios::in);
	if (!file) {
		error_open2();
		return;
	}
	clear(top);
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
		newNode->next = top;
		top = newNode;
	}
	file.close();
	success_read(filename);
}