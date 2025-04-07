#define _CRT_SECURE_NO_WARNINGS
#include "input.h"
#include "stack.h"
#include "output.h"
#include "file.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool checkMenu(string str)
{
	if (str.size() > 9)
		return false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i]>'9')
		{
			return false;
		}
	}
	return true;
}

bool check(string str)
{
	if (str.size() > 9)
		return false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
	if (year < 1900 || month < 1 || month > 12 || day < 1) {
		return false;
	}
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && isLeapYear(year)) {
		days[1] = 29;
	}
	return day <= days[month - 1];
}

void input_patient(Stack*& newNode) {	
	newNode = (Stack*)malloc(sizeof(Stack));
	string str;
	bool end;
	int count;
	int day, month, year, dayVisit, monthVisit, yearVisit;;
	do {
		end = false;
		count = 0;
		cout << endl << "������� �.�.�.: ";
		rewind(stdin);
		getline(cin, str);
		if (str.size() >= 30) {
			cerr << endl << "������� ������� ������. ���������� �����.";
			continue;
		}
		for (int i = 0; i < str.size(); i++) {
			if ((str[i] < '�' || str[i] > '�') && (str[i] < '�' || str[i] > '�') && (str[i] != '�' && str[i] != '�')) {
				if ((str[i] != '.') && (str[i] != ' ')) {
					cerr << endl << "�������� ����. ���������� �����.";
					break;
				}
				if (str[i] == '.') {
					if (str[i + 1] == '.') {
						cerr << endl << "�������� ����. ���������� �����.";
						break;
					}
					count++;
				}
			}
			if (count > 2) {
				cerr << endl << "�������� ����. ���������� �����.";
				break;
			}
			if (str.size() - 1 == i)
				end = true;
		}
	} while (!end);
	strcpy(newNode->data.name, str.c_str());
	while (true) {
		do {
			end = false;
			count = 0;
			cout << endl << "������� ���� �������� (��.��.����): ";
			rewind(stdin);
			getline(cin, str);
			if (str.size() != 10) {
				cerr << endl << "�������� ����. ���������� �����.";
				continue;
			}
			for (int i = 0; i < str.size(); i++) {
				if ((str[i] < '0' || str[i] > '9') && (str[i] != '.')) {
					cerr << endl << "�������� ����. ���������� �����.";
					break;
				}
				if (str[i] == '.') {
					if (str[i + 1] == '.') {
						cerr << endl << "�������� ����. ���������� �����.";
						break;
					}
					count++;
				}
				if (count > 2) {
					cerr << endl << "�������� ����. ���������� �����.";
					break;
				}
				if (str.size() - 1 == i)
					end = true;
			}
		} while (!end);
		day = stoi(str.substr(0, 2));
		month = stoi(str.substr(3, 2));
		year = stoi(str.substr(6, 4));
		if (isValidDate(day, month, year)) break;
		else {
			cerr << endl << "������� �������������� ����.";
		}
	}
	strcpy(newNode->data.birthDate, str.c_str());
	int number;
	do {
		number = 0;
		cout << endl << "������� ����� ��������: ";
		cin >> str;
		if (check(str) && str.size() < 10) {
			number = stoi(str);
		}
		else cerr << endl << "������������ ���� (��������� �������� �����).";
	} while (!check(str) || str.size() > 10);
	newNode->data.medicalCardNumber = number;
	do {
		end = false;
		count = 0;
		cout << endl << "������� �������: ";
		rewind(stdin);
		getline(cin, str);
		if (str.size() >= 30) {
			cerr << endl << "������� ������� ������. ���������� �����.";
			continue;
		}
		for (int i = 0; i < str.size(); i++) {
			if ((str[i] < '�' || str[i] > '�') && (str[i] < '�' || str[i] > '�') && (str[i] != '�' && str[i] != '�') && (str[i] < '0' || str[i] > '9')) {
				if (str[i] == ' ') {
					if (str[i + 1] == ' ') {
						cerr << endl << "�������� ����. ���������� �����.";
						break;
					}
					continue;
				}
				cerr << endl << "�������� ����. ���������� �����.";
				break;
			}
			if (str.size() - 1 == i)
				end = true;
		}
	} while (!end);
	strcpy(newNode->data.diagnosis, str.c_str());
	while (true) {
		do {
			end = false;
			count = 0;
			cout << endl << "������� ���� ���������� ������ (��.��.����): ";
			rewind(stdin);
			getline(cin, str);
			if (str.size() != 10) {
				cerr << endl << "�������� ����. ���������� �����.";
				continue;
			}
			for (int i = 0; i < str.size(); i++) {
				if ((str[i] < '0' || str[i] > '9') && (str[i] != '.')) {
					cerr << endl << "�������� ����. ���������� �����.";
					break;
				}
				if (str[i] == '.') {
					if (str[i + 1] == '.') {
						cerr << endl << "�������� ����. ���������� �����.";
						break;
					}
					count++;
				}
				if (count > 2) {
					cerr << endl << "�������� ����. ���������� �����.";
					break;
				}
				if (str.size() - 1 == i)
					end = true;
			}
		} while (!end);
		dayVisit = stoi(str.substr(0, 2));
		monthVisit = stoi(str.substr(3, 2));
		yearVisit = stoi(str.substr(6, 4));
		if (isValidDate(dayVisit, monthVisit, yearVisit)) {
			if (yearVisit < year) {
				cerr << endl << "���� ������ �� ����� ���� ������ ���� ��������.";
			}
			else if (yearVisit == year) {
				if (monthVisit < month) {
					cerr << endl << "���� ������ �� ����� ���� ������ ���� ��������.";
				}
				else if (monthVisit == month && dayVisit < day) {
					cerr << endl << "���� ������ �� ����� ���� ������ ���� ��������.";
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		else {
			cerr << endl << "������� �������������� ����.";
		}
	}
	strcpy(newNode->data.lastVisitDate, str.c_str());
}

void input_filename(string& filename, int m) {	
	switch (m) {
	case 4: {
		output_menu(m);
		cin >> filename;
	} break;
	case 5: {
		output_menu(m);
		cin >> filename;
	} break;
	case 6: {
		output_menu(m);
		cin >> filename;
	} break;
	case 7: {
		output_menu(m);
		cin >> filename;
	} break;
	default: {
		output_menu(0);
	} break;
	}	
}

void input_str(string& str) {
	output_menu(0);
	cin >> str;
}

void input_toDelete(string& str, int& pos) {	
	do {
		pos = 0;
		cout << endl << "������� ����� ������ ��������: ";
		cin >> str;
		if (check(str)) {
			pos = stoi(str);
		}
		else cerr << endl << "������������ ����.";
	} while (!check(str) || pos < 1);
}

void input_choice(string& str, int& choice) {	
	do {
		choice = 0;
		cout << endl << "�������� ������� ���������� (�� ����. - 1, �� ����. - 2): ";
		cin >> str;
		if (check(str)) {
			choice = stoi(str);
		}
		else cerr << endl << "������������ ����.";
	} while (!check(str) || choice < 1 || choice > 2);
}