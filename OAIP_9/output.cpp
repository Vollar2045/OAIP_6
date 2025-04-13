#include "output.h"
#include "file.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void printHead() {
    cout << left << setw(40) << "Ф.И.О."
         << setw(15) << "Дата рождения"
         << setw(15) << "Мед. карта №"
         << setw(20) << "Диагноз"
         << setw(15) << "Дата последнего приема" << endl;
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
        cout << "Нет информации о пациентах." << endl;
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
        cout << endl << "Введите имя файла: ";
    } break;
    case 4: {
        cout << endl << "Введите имя удаляемого файла: ";
    } break;
    case 5: {
        cout << endl << "Введите имя файла для сохранения данных: ";
    } break;
    case 6: {
        cout << endl << "Введите имя файла для загрузки данных: ";
    } break;
    default: {
        cout << endl << "Введите номер операции:";
        cout << endl << "1)Ввести данные о пациенте";        
        cout << endl << "2)Вывести информацию о пациенте в табличном формате";
        cout << endl << "3)Создать новый файл базы данных и открыть для записи";
        cout << endl << "4)Удалить файл.";
        cout << endl << "5)Сохранить данные в файл";
        cout << endl << "6)Загрузить данные из файла";
        cout << endl << "7)Редактировать запись о пациенте по его номеру";
        cout << endl << "8)Удалить запись о пациенте по его номеру";
        cout << endl << "9)Сортировка по любому из полей";
        cout << endl << "10)Сортировка Шелла по полю номера мед.карты";
        cout << endl << "11)Сортировка вставками по полю диагноза";
        cout << endl << "12)Фильтр по выбранному полю";
        cout << endl << "13)Поиск по выбранному полю";
        cout << endl << "14)Бинарный поиск по полю номера мед.карты";
        cout << endl << "15)Доп. обработка(одинаковый диагноз по убыванию даты посл.визита";
        cout << endl << "16)Выйти из программы" << endl;
    } break;
    }
}

void error_initMem() {
    cerr << "Ошибка выделения памяти!" << endl;
}

void error_create() {
    cerr << "Ошибка создания файла!" << endl;
}

void error_delete(string filename) {
    cerr << "Ошибка удаления файла " << filename << "!" << endl;
}

void outputError_create(string filename) {
    cerr << endl << "Ошибка создания файла " << filename << "!" << endl;
}

void success_del(string filename) {
    cout << "Файл " << filename << " успешно удален." << endl;
}

void error_open1() {
    cerr << "Ошибка открытия файла для записи!" << endl;
}

void error_open2() {
    cerr << "Ошибка открытия файла для чтения!" << endl;
}

void success_read(string filename) {
    cout << "Данные успешно загружены из файла " << filename << endl;
}

void success_save(string filename){
    cout << "Данные успешно сохранены в " << filename << endl;
}

void error_choice() {
    cout << endl << "Выберите вариант от 1 до 12.";
}
