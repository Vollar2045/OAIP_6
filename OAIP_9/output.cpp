#include "output.h"
#include "file.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void printHead() {
    cout << left << setw(40) << "�.�.�."
         << setw(15) << "���� ��������"
         << setw(15) << "���. ����� �"
         << setw(20) << "�������"
         << setw(15) << "���� ���������� ������" << endl;
    cout << string(125, '-') << endl;
}

void printPatient(Patient& p) {          
    cout << left << setw(40) << p.name
         << setw(15) << p.birthDate
         << setw(15) << p.medicalCardNumber
         << setw(20) << p.diagnosis
         << setw(15) << p.lastVisitDate << endl;
}

void printTab(Stack* top) {
    if (!top) {
        cout << "��� ���������� � ���������." << endl;
        return;
    }
    printHead();
    Stack* current = top;
    while (current) {
        cout << left << setw(40) << current->data.name
            << setw(15) << current->data.birthDate
            << setw(15) << current->data.medicalCardNumber
            << setw(20) << current->data.diagnosis
            << setw(15) << current->data.lastVisitDate << endl;
        current = current->next;
    }
}

void output_menu(int m) {
    switch (m) {
    case 3: {
        cout << endl << "������� ��� �����: ";
    } break;
    case 4: {
        cout << endl << "������� ��� ���������� �����: ";
    } break;
    case 5: {
        cout << endl << "������� ��� ����� ��� ���������� ������: ";
    } break;
    case 6: {
        cout << endl << "������� ��� ����� ��� �������� ������: ";
    } break;
    default: {
        cout << endl << "������� ����� ��������:";
        cout << endl << "1)������ ������ � ��������";        
        cout << endl << "2)������� ���������� � �������� � ��������� �������";
        cout << endl << "3)������� ����� ���� ���� ������ � ������� ��� ������";
        cout << endl << "4)������� ����.";
        cout << endl << "5)��������� ������ � ����";
        cout << endl << "6)��������� ������ �� �����";
        cout << endl << "7)������������� ������ � �������� �� ��� ������";
        cout << endl << "8)������� ������ � �������� �� ��� ������";
        cout << endl << "9)���������� �� ������ �� �����";
        cout << endl << "10)���������� ����� �� ���� ������ ���.�����";
        cout << endl << "11)���������� ��������� �� ���� ��������";
        cout << endl << "12)������ �� ���������� ����";
        cout << endl << "13)����� �� ���������� ����";
        cout << endl << "14)�������� ����� �� ���� ������ ���.�����";
        cout << endl << "15)���. ���������(���������� ������� �� �������� ���� ����.������";
        cout << endl << "16)����� �� ���������" << endl;
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
    cout << endl << "�������� ������� �� 1 �� 12.";
}
