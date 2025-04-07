#include "output.h"
#include "file.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void printPatient(Stack* top) {   
    if (!top) {
        cout << "��� ���������� � ���������.\n";
        return;
    }
    Stack* current = top;
    while (current) {
        cout << "�.�.�.: " << current->data.name << "\n";
        cout << "���� ��������: " << current->data.birthDate << "\n";
        cout << "����� ��������: " << current->data.medicalCardNumber << "\n";
        cout << "�������: " << current->data.diagnosis << "\n";
        cout << "���� ���������� ������: " << current->data.lastVisitDate << "\n\n";
        current = current->next;
    }
}

void printTab(Stack* top) {
    if (!top) {
        cout << "��� ���������� � ���������.\n";
        return;
    }
    cout << left << setw(30) << "�.�.�."
        << setw(15) << "���� ��������"
        << setw(15) << "���. ����� �"
        << setw(30) << "�������"
        << setw(15) << "���� ���������� ������" << endl;
    cout << string(115, '-') << endl;

    Stack* current = top;
    while (current) {
        cout << left << setw(30) << current->data.name
            << setw(15) << current->data.birthDate
            << setw(15) << current->data.medicalCardNumber
            << setw(30) << current->data.diagnosis
            << setw(15) << current->data.lastVisitDate << endl;
        current = current->next;
    }
}

void output_menu(int m) {
    switch (m) {
    case 4: {
        cout << endl << "������� ��� �����: ";
    } break;
    case 5: {
        cout << endl << "������� ��� ���������� �����: ";
    } break;
    case 6: {
        cout << endl << "������� ��� ����� ��� ���������� ������: ";
    } break;
    case 7: {
        cout << endl << "������� ��� ����� ��� �������� ������: ";
    } break;
    default: {
        cout << endl << "������� ����� ��������:";
        cout << endl << "1)������ ������ � ��������";
        cout << endl << "2)������� ���������� � ��������";
        cout << endl << "3)������� ���������� � �������� � ��������� �������";
        cout << endl << "4)������� ����� ���� ���� ������ � ������� ��� ������";
        cout << endl << "5)������� ����.";
        cout << endl << "6)��������� ������ � ����";
        cout << endl << "7)��������� ������ �� �����";
        cout << endl << "8)������� ������ � �������� �� ��� ������";
        cout << endl << "9)���������� ����� �� ���� �����";
        cout << endl << "10)���������� ��������� �� ���� ��������";
        cout << endl << "11)����� �� ���������" << endl;
    } break;
    }
}

void error_initMem() {
    cerr << "������ ��������� ������!" << endl;
}

void error_create() {
    cerr << "������ �������� �����!" << endl;
}

void error_delete(string filename) {
    cerr << "������ �������� ����� " << filename << "!" << endl;
}

void outputError_create(string filename) {
    cerr << endl << "������ �������� ����� " << filename << "!" << endl;
}

void success_del(string filename) {
    cout << "���� " << filename << " ������� ������." << endl;
}

void error_open1() {
    cerr << "������ �������� ����� ��� ������!" << endl;
}

void error_open2() {
    cerr << "������ �������� ����� ��� ������!" << endl;
}

void success_read(string filename) {
    cout << "������ ������� ��������� �� ����� " << filename << endl;
}

void success_save(string filename){
    cout << "������ ������� ��������� � " << filename << endl;
}

void error_choice() {
    cout << endl << "�������� ������� �� 1 �� 8.";
}
