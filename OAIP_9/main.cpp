#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "menu.h"

int main() {   
    system("chcp 1251");   
    system("cls");
    Stack* top = nullptr;
    showMenu(top);    
    return 0;
}