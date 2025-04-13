#define _CRT_SECURE_NO_WARNINGS
#include "algorithms.h"
#include "input.h"
#include "stack.h"
#include "output.h"
#include "file.h"
#include <iostream>
#include <string>
#include <locale>
using namespace std;

bool compareNumber(int a, int b, bool ubivanie) {
    if (ubivanie) {
        return a > b;  
    }
    else {
        return a < b; 
    }
}

void shellSort_medCard(Stack*& top, bool ubivanie) {
    if (!top || !top->next) return; 
    Stack* reversed = nullptr;
    while (top) {
        Stack* node = top;
        top = top->next;
        node->next = reversed;
        reversed = node;
    } 
    int length = 0;
    Stack* temp = reversed;
    while (temp) {
        length++;
        temp = temp->next;
    }   
    for (int gap = length / 2; gap > 0; gap /= 2) {    
        for (int i = gap; i < length; i++) {      
            Stack* current = reversed;
            for (int j = 0; j < i && current; j++) {
                current = current->next;
            }
            if (!current) continue;
            Patient key = current->data;
            int j = i;        
            while (j >= gap) {             
                Stack* gap_node = reversed;
                for (int k = 0; k < j - gap && gap_node; k++) {
                    gap_node = gap_node->next;
                }
                if (!gap_node) break;            
                if (compareNumber(gap_node->data.medicalCardNumber, key.medicalCardNumber, ubivanie)) {              
                    Stack* target = reversed;
                    for (int k = 0; k < j && target; k++) {
                        target = target->next;
                    }
                    if (target) {
                        target->data = gap_node->data;
                    }
                    j -= gap;
                }
                else {
                    break;
                }
            }        
            Stack* target = reversed;
            for (int k = 0; k < j && target; k++) {
                target = target->next;
            }
            if (target) {
                target->data = key;
            }
        }
    }
    while (reversed) {
        Stack* node = reversed;
        reversed = reversed->next;
        node->next = top;
        top = node;
    }
}

int getOrder(char c) {   
    const char russianLetters[] = {
        'А','а','Б','б','В','в','Г','г','Д','д','Е','е','Ё','ё',
        'Ж','ж','З','з','И','и','Й','й','К','к','Л','л','М','м',
        'Н','н','О','о','П','п','Р','р','С','с','Т','т','У','у',
        'Ф','ф','Х','х','Ц','ц','Ч','ч','Ш','ш','Щ','щ','Ъ','ъ',
        'Ы','ы','Ь','ь','Э','э','Ю','ю','Я','я'
    };   
    for (int i = 0; i < sizeof(russianLetters); ++i) {
        if (russianLetters[i] == c) {
            return i;
        }
    }
    return -1; 
}

bool diagnosisCompare(const char* a, const char* b, int choice) {   
    while (*a && *b) {
        int orderA = getOrder(*a);
        int orderB = getOrder(*b);      
        if (orderA != orderB) {
            switch (choice) {
            case 1: {
                return orderA > orderB;
            } break;
            case 2: {
                return orderA < orderB;
            }
            }           
        }    
        ++a;
        ++b;
    }  
    return *a == '\0' && *b != '\0';
}

void sort_diagnosis(Stack*& top, int choice) {
    if (!top || !top->next) return;
    Stack* sorted = nullptr;  
    Stack* temp = nullptr; 
    while (top) {     
        Patient current = pop(top);
        int count = 0;
        while (sorted && diagnosisCompare(sorted->data.diagnosis, current.diagnosis, choice)) {
            push(temp, sorted->data);
            pop(sorted);
            count++;
        }       
        push(sorted, current);       
        while (count > 0) {
            push(sorted, temp->data);
            pop(temp);
            count--;
        }
    }  
    while (sorted) {
        push(top, sorted->data);
        pop(sorted);
    }
}

void shellSort_medCard1(Stack*& top, bool ubivanie) {
    if (!top || !top->next) return;    
    Stack* temp = nullptr;
    while (top) {
        Stack* node = top;
        top = top->next;
        node->next = temp;
        temp = node;
    }  
    int length = 0;
    Stack* counter = temp;
    while (counter) {
        length++;
        counter = counter->next;
    }   
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {          
            Stack* current = temp;
            for (int j = 0; j < i && current; j++) {
                current = current->next;
            }
            if (!current)
                continue;
            Patient key = current->data;
            int j = i;            
            while (j >= gap) {              
                Stack* gap_node = temp;
                for (int k = 0; k < j - gap && gap_node; k++) {
                    gap_node = gap_node->next;
                }
                if (!gap_node)
                    break;
                if (compareNumber(gap_node->data.medicalCardNumber,key.medicalCardNumber, ubivanie)) {
                    Stack* target = temp;
                    for (int k = 0; k < j && target; k++) {
                        target = target->next;
                    }
                    if (target) {
                        target->data = gap_node->data;
                    }
                    j -= gap;
                }
                else {
                    break;
                }
            }          
            Stack* target = temp;
            for (int k = 0; k < j && target; k++) {
                target = target->next;
            }
            if (target) {
                target->data = key;
            }
        }
    } 
    while (temp) {
        Stack* node = temp;
        temp = temp->next;
        node->next = top;
        top = node;
    }
}

void filterPatients(Stack*& top) {
    if (top == nullptr) {
        cerr << endl << "Стек пуст.";
        return;
    }   
    string str;
    int fields[5];
    string stringValues[6];  
    int intValues[6] = { 0 };  
    int fieldCount = 0; 
    while (fieldCount < 5) {
        cout << endl << "Добавить фильтр по полю? (1 - Да, 0 - Нет): ";
        int choice = -1;
        do {
            cin >> str;
            if (check(str)) {
                choice = stoi(str);
            }
        } while (!check(str) || choice < 0 || choice > 1);     
        if (choice == 0) break;
        int fieldChoice;
        input_search(fieldChoice); 
        fields[fieldCount] = fieldChoice;
        switch (fieldChoice) {
        case 1: stringValues[1] = input_name(top, 0); break;
        case 2: stringValues[2] = input_birthdate(top, 0); break;
        case 3: intValues[3] = input_medcardNumber(top, 0); break;
        case 4: stringValues[4] = input_diagnosis(top, 0); break;
        case 5: stringValues[5] = input_lastVisitDate(top, 0); break;
        }
        fieldCount++;
    }
    if (fieldCount == 0) {
        cout << endl << "Фильтрация не выбрана.";
        return;
    }   
    int direction;
    input_direction(direction);
    Stack* buffer = nullptr;
    cout << endl << endl;
    printHead();
    if (direction == 1) {       
        while (top) {
            Patient p = pop(top);
            bool match = true;
            for (int i = 0; i < fieldCount; i++) {
                int field = fields[i];
                switch (field) {
                case 1:
                    if (string(p.name).rfind(stringValues[1], 0) != 0) 
                        match = false;
                    break;
                case 2:
                    if (string(p.birthDate).rfind(stringValues[2], 0) != 0) 
                        match = false;
                    break;
                case 3:
                    if (p.medicalCardNumber != intValues[3])
                        match = false;
                    break;
                case 4:
                    if (string(p.diagnosis).rfind(stringValues[4], 0) != 0)
                        match = false;
                    break;
                case 5:
                    if (string(p.lastVisitDate).rfind(stringValues[5], 0) != 0)
                        match = false;
                    break;
                }
                if (!match) break;
            }
            if (match) printPatient(p);
            push(buffer, p);
        }
        while (buffer)
            push(top, pop(buffer));
    }
    else {       
        while (top)
            push(buffer, pop(top));

        while (buffer) {
            Patient p = pop(buffer);
            bool match = true;

            for (int i = 0; i < fieldCount; i++) {
                int field = fields[i];
                switch (field) {
                case 1:
                    if (string(p.name).rfind(stringValues[1], 0) != 0) match = false;
                    break;
                case 2:
                    if (string(p.birthDate).rfind(stringValues[2], 0) != 0) match = false;
                    break;
                case 3:
                    if (p.medicalCardNumber != intValues[3]) match = false;
                    break;
                case 4:
                    if (string(p.diagnosis).rfind(stringValues[4], 0) != 0) match = false;
                    break;
                case 5:
                    if (string(p.lastVisitDate).rfind(stringValues[5], 0) != 0) match = false;
                    break;
                }
                if (!match) break;
            }
            if (match) printPatient(p);
            push(top, p);
        }
    }
}

void searchPatient(Stack*& top) {
    if (top == nullptr) {
        cerr << endl << "Стек пуст.";
        return;
    }
    int fieldChoice;
    input_search(fieldChoice); 
    string searchStr;
    int searchInt = 0;
    switch (fieldChoice) {
    case 1: {
        searchStr = input_name(top, 0);
    } break;
    case 2: {
        searchStr = input_birthdate(top, 0);
    } break;
    case 3: {
        searchInt = input_medcardNumber(top, 0);
    } break;
    case 4: {
        searchStr = input_diagnosis(top, 0);
    } break;
    case 5: {
        searchStr = input_lastVisitDate(top, 0);
    } break;         
    }
    Stack* buffer = nullptr;
    int position = 1;
    int foundPos = -1;
    Patient foundPatient;
    while (top) {
        Patient p = pop(top);
        bool match = false;
        switch (fieldChoice) {
        case 1: match = string(p.name) == searchStr; break;
        case 2: match = string(p.birthDate) == searchStr; break;
        case 3: match = p.medicalCardNumber == searchInt; break;
        case 4: match = string(p.diagnosis) == searchStr; break;
        case 5: match = string(p.lastVisitDate) == searchStr; break;
        }
        if (match && foundPos == -1) {
            foundPos = position;
            foundPatient = p;
        }
        push(buffer, p);
        position++;
    }   
    while (buffer) {
        push(top, pop(buffer));
    }
    if (foundPos == -1) {
        cout << endl << "Совпадений не найдено.";
        return;
    }    
    cout << endl << "Найдена запись #" << foundPos << ":" << endl;
    printHead();
    printPatient(foundPatient);    
    int action = -1;
    string str;
    do {
        cout << endl << "Что вы хотите сделать?";
        cout << endl << "1 - Редактировать";
        cout << endl << "2 - Удалить";
        cout << endl << "0 - Ничего" << endl;
        cin >> str;
        if (check(str))
            action = stoi(str);
    } while (!check || action < 0 || action > 2);
    if (action == 1) {
        editPatient(top, foundPos);
    }
    else if (action == 2) {
        deletePatient(top, foundPos);
    }
}

void insertSorted(Stack*& sorted, Patient p) {
    Stack* tempStack = nullptr;  
    while (sorted && sorted->data.medicalCardNumber < p.medicalCardNumber) {
        push(tempStack, pop(sorted));
    }
    push(sorted, p);    
    while (tempStack) {
        push(sorted, pop(tempStack));
    }
}

void sortStackByCardNumber(Stack*& top, Stack*& sorted) {
    Stack* temp = nullptr;    
    while (top) {
        Patient p = pop(top);
        push(temp, p);
        insertSorted(sorted, p);
    } 
    while (temp) {
        push(top, pop(temp));
    }
}

int getStackSize(Stack* top) {
    int size = 0;
    while (top) {
        size++;
        top = top->next;
    }
    return size;
}

Patient getElementAt(Stack*& top, int index) {
    Stack* tempStack = nullptr;
    Patient result;
    int i = 0;
    while (top && i <= index) {
        Patient p = pop(top);
        if (i == index) {
            result = p;
        }
        push(tempStack, p);
        i++;
    }  
    while (tempStack) {
        push(top, pop(tempStack));
    }
    return result;
}

void binarySearchByCardNumber(Stack*& top, int searchNumber) {
    if (top == nullptr) {
        cout << "Стек пуст." << endl;
        return;
    }   
    Stack* sorted = nullptr;
    sortStackByCardNumber(top, sorted);
    int left = 0;
    int right = getStackSize(sorted) - 1;
    bool found = false;
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        Patient midPatient = getElementAt(sorted, mid);
        if (midPatient.medicalCardNumber == searchNumber) {
            cout << "Пациенты с номером карты " << searchNumber << " найдены:" << endl;
            printHead();
            found = true;         
            int firstIndex = mid;
            while (firstIndex > 0) {
                Patient leftPatient = getElementAt(sorted, firstIndex - 1);
                if (leftPatient.medicalCardNumber == searchNumber) {
                    firstIndex--;
                }
                else {
                    break;
                }
            }           
            while (firstIndex <= right) {
                Patient current = getElementAt(sorted, firstIndex);
                if (current.medicalCardNumber == searchNumber) {
                    printPatient(current);
                    firstIndex++;
                }
                else {
                    break;
                }
            }
            break;
        }
        else if (midPatient.medicalCardNumber < searchNumber) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Пациент с номером карты " << searchNumber << " не найден." << endl;
    }
}

void sort(Stack*& top) {
    if (top == nullptr) {
        cerr << "Стек пуст." << endl;
        return;
    }
    string str;
    int fieldChoice;
    do {
        cout << endl << "Выберите поле для сортировки:";
        cout << endl << "1 - Имя\n2 - Дата рождения\n3 - Номер медицинской карты\n4 - Диагноз\n5 - Дата последнего визита" << endl;
        cin >> str;
        if (check(str)) {
            fieldChoice = stoi(str);
        }
    } while (!check(str) || fieldChoice < 1 || fieldChoice > 5);
    int direction;
    do {        
        cout << endl << "1 - По возрастанию\n2 - По убыванию";
        cout << endl << "Выберите направление сортировки: ";
        cin >> str;
        if (check(str)) {
            direction = stoi(str);
        }
    } while (!check(str) || direction < 1 || direction > 2);    
    Stack* buffer = nullptr;  
    bool swapped;
    do {
        swapped = false;
        Stack* tempBuffer = nullptr;       
        while (top != nullptr) {
            Patient p1 = pop(top);                    
            if (tempBuffer != nullptr) {
                Patient p2 = pop(tempBuffer);              
                bool match = false;
                switch (fieldChoice) {
                case 1: {
                    if ((direction == 1 && string(p1.name) > string(p2.name)) ||
                        (direction == 2 && string(p1.name) < string(p2.name))) {
                        match = true;
                    }
                    break;
                }
                case 2: { 
                    string date1, date2;
                    date1 = p1.birthDate;
                    date2 = p2.birthDate;
                    int d1, m1, y1, d2, m2, y2;
                    d1 = stoi(date1.substr(0, 2));
                    m1 = stoi(date1.substr(3, 2));
                    y1 = stoi(date1.substr(6, 4));
                    d2 = stoi(date2.substr(0, 2));
                    m2 = stoi(date2.substr(3, 2));
                    y2 = stoi(date2.substr(6, 4));
                    if (y1 != y2)
                        match = direction == 1 ? y1 < y2 : y1 > y2;
                    else if (m1 != m2)
                        match = direction == 1 ? m1 < m2 : m1 > m2;
                    else
                        match = direction == 1 ? d1 < d2 : d1 > d2;
                    break;
                }
                case 3: { 
                    if ((direction == 1 && p1.medicalCardNumber < p2.medicalCardNumber) ||
                        (direction == 2 && p1.medicalCardNumber > p2.medicalCardNumber)) {
                        match = true;
                    }
                    break;
                }
                case 4: { 
                    if ((direction == 1 && string(p1.diagnosis) > string(p2.diagnosis)) ||
                        (direction == 2 && string(p1.diagnosis) < string(p2.diagnosis))) {
                        match = true;
                    }
                    break;
                }
                case 5: { 
                    string date1, date2;
                    date1 = p1.lastVisitDate;
                    date2 = p2.lastVisitDate;
                    int d1, m1, y1, d2, m2, y2;
                    d1 = stoi(date1.substr(0, 2));
                    m1 = stoi(date1.substr(3, 2));
                    y1 = stoi(date1.substr(6, 4));
                    d2 = stoi(date2.substr(0, 2));
                    m2 = stoi(date2.substr(3, 2));
                    y2 = stoi(date2.substr(6, 4));
                    if (y1 != y2)
                        match = direction == 1 ? y1 < y2 : y1 > y2;
                    else if (m1 != m2)
                        match = direction == 1 ? m1 < m2 : m1 > m2;
                    else
                        match = direction == 1 ? d1 < d2 : d1 > d2;
                    break;
                }
                }              
                if (match) {
                    push(tempBuffer, p1);  
                    push(tempBuffer, p2);
                    swapped = true; 
                }
                else {                   
                    push(tempBuffer, p2);
                    push(tempBuffer, p1);
                }
            }
            else {
                push(tempBuffer, p1);
            }              
        }
        while (tempBuffer != nullptr) {
            Patient p = pop(tempBuffer);
            push(top, p);  
        }
    } while (swapped);  
    cout << endl << "Сортировка завершена." << endl;
}

void extra_task(Stack*& top) {
    if (top == nullptr) {
        cerr << "Стек пуст." << endl;
        return;
    }
    string diagnosis = input_diagnosis(top, 0);  
    Stack* buffer = nullptr;
    Stack* matched = nullptr; 
    while (top) {
        Patient p = pop(top);
        if (string(p.diagnosis) == diagnosis) {
            push(matched, p); 
        }
        push(buffer, p); 
    }
    while (buffer) {
        push(top, pop(buffer));
    }
    if (matched == nullptr) {
        cout << "Пациенты с диагнозом " << diagnosis <<  " не найдены." << endl;
        return;
    }  
    bool swapped;
    do {
        swapped = false;
        Stack* temp = nullptr;
        while (matched) {
            Patient p1 = pop(matched);
            if (temp != nullptr) {
                Patient p2 = pop(temp);            
                string date1 = p1.lastVisitDate;
                string date2 = p2.lastVisitDate;
                int d1 = stoi(date1.substr(0, 2));
                int m1 = stoi(date1.substr(3, 2));
                int y1 = stoi(date1.substr(6, 4));
                int d2 = stoi(date2.substr(0, 2));
                int m2 = stoi(date2.substr(3, 2));
                int y2 = stoi(date2.substr(6, 4));
                bool match = false;
                if (y1 != y2) match = y1 > y2;
                else if (m1 != m2) match = m1 > m2;
                else match = d1 > d2;
                if (match) {
                    push(temp, p1);
                    push(temp, p2);
                    swapped = true;
                }
                else {
                    push(temp, p2);
                    push(temp, p1);
                }
            }
            else {
                push(temp, p1);
            }
        }
        while (temp) {
            push(matched, pop(temp));
        }
    } while (swapped);
    cout << endl << "Пациенты с диагнозом " << diagnosis << " (сортированы по дате последнего визита ↓):" << endl;  
    printTab(matched);
    save_DB_txt("filtered_patients.txt", matched);
}