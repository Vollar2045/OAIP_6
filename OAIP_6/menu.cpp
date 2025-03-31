#include "menu.h"

#include <iostream>
#include <string>
using namespace std;

void showMenu(Stack*& top) {	
	int m = 0;
	string str, filename;	
	do
	{		
		input_str(str);			
		cin.ignore();
		if (checkMenu(str)) {
			m = stoi(str);
			switch (m) {
			case 1: {
				addPatient(top);
			} break;
			case 2: {
				printPatient(top);
			} break;
			case 3: {
				printTab(top);
			} break;
			case 4: {
				input_filename(filename, m);
				ofstream db = new_DB(filename);
				if (!db) {
					error_create();
				}
			} break;
			case 5: {
				input_filename(filename, m);
				remove_DB(filename);
			} break;
			case 6: {
				input_filename(filename, m);
				cin.ignore();
				save_DB(filename, top);
			} break;
			case 7: {
				input_filename(filename, m);
				cin.ignore();
				load_DB(filename, top);
			} break;
			case 8:
				break;
			}
		}
		else error_choice();
	} while (!checkMenu(str) || m != 8);
	clear(top);	
}