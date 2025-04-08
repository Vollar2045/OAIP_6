#include "menu.h"

#include <iostream>
#include <string>
using namespace std;

void showMenu(Stack*& top) {	
	int m = 0, direction = 0;
	string str, filename;	
	do
	{		
		output_menu(0);
		cin >> str;
		cin.ignore();
		if (checkMenu(str)) {
			m = stoi(str);
			switch (m) {
			case 1: {
				addPatient(top);
			} break;			
			case 2: {
				printTab(top);
			} break;
			case 3: {
				input_filename(filename, m);
				ofstream db = new_DB(filename);
				if (!db) {
					error_create();
				}
			} break;
			case 4: {
				input_filename(filename, m);
				remove_DB(filename);
			} break;
			case 5: {
				input_filename(filename, m);
				cin.ignore();
				save_DB(filename, top);
			} break;
			case 6: {
				input_filename(filename, m);
				cin.ignore();
				load_DB(filename, top);
			} break;
			case 7: {
				int pos;
				input_toDelete(pos);
				deletePatient(top, pos);				
			} break;
			case 8: {
				input_direction(direction);
				if (direction == 1) {
					shellSort_medCard(top, true);
				}
				else {
					shellSort_medCard(top, false);
				}
			} break;
			case 9: {				
				input_direction(direction);
				sort_diagnosis(top, direction);
			} break;
			case 10: {
				printHead();
				searchPatients(top);
			}		
			case 12: 
				break;
			}
		}
		else error_choice();
	} while (!checkMenu(str) || m != 12);
	clear(top);	
}