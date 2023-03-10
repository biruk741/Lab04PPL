#include <iostream>
using namespace std;

typedef struct {
    unsigned int seconds: 6;
    unsigned int minutes: 6;
    unsigned int hours: 5;
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 11;
} dateTime;

typedef struct {
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;
    unsigned int day;
    unsigned int month;
    unsigned int year;
} dateTimeThicc;

void printDate(dateTime dt){
    cout << dt.month << "/" << dt.day << "/" << dt.year << " " << dt.hours << ":" << dt.minutes << ":" <<
    dt.seconds << endl;
}

typedef struct {
    int length;
    int capacity;
    int* elements;
} ArrayList;


ArrayList init(){
    int* mem = (int*) ::malloc(sizeof(int));
    return {
        0,
        1,
        mem
    };
}

void print(ArrayList list){
    for (int i = 0; i < list.length; ++i) {
        cout << list.elements[i] << endl;
    }
}

void add(ArrayList *list, int i){
    if (list->length + 1 <= list->capacity){ // no double

        // todo: read about memcopy lol
    } else { // double

    }
}

int main() {

    // Problem 1:
    // The first loop will "terminate" if n < m because it wouldn't run at all since the condition is never met.
    // The first loop will also terminate if n >= m eventually since it goes down by one each iteration until n=m.

    // For the second loop, if p and q are separate pointers, it will at some point terminate similar to the first loop.
    // However, if p and q point to the same variable, both their values will be decremented equally, meaning *p and *q
    // will always be equal and the loop will run infinitely.

    int n = 100;
    int m = 20;

    int *p = &m;
    int *q = p;

//    while (*p >= *q) { // This will run infinitely.
//        *p = *p - 1;
//    }


    cout << sizeof(dateTime) <<endl;
    cout << sizeof(dateTimeThicc) << endl;

    dateTime today = {
            1,
            36,
            13,
            10,
            3,
            2023
    };

    printDate(today);

    cout << "Hello, World!" << endl;
    return 0;
}
