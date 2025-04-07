#define _CRT_SECURE_NO_WARNINGS
#include "algorithms.h"
#include "input.h"
#include "stack.h"
#include "output.h"
#include "file.h"
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
                if (compareNumber(gap_node->data.medicalCardNumber,
                    key.medicalCardNumber,
                    ubivanie)) {              
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
        'À','à','Á','á','Â','â','Ã','ã','Ä','ä','Å','å','¨','¸',
        'Æ','æ','Ç','ç','È','è','É','é','Ê','ê','Ë','ë','Ì','ì',
        'Í','í','Î','î','Ï','ï','Ð','ð','Ñ','ñ','Ò','ò','Ó','ó',
        'Ô','ô','Õ','õ','Ö','ö','×','÷','Ø','ø','Ù','ù','Ú','ú',
        'Û','û','Ü','ü','Ý','ý','Þ','þ','ß','ÿ'
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