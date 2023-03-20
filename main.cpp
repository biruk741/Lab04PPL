#include <iostream>
#include <cstring>

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
} dateTimeBigger;

void printDate(dateTime dt) {
    cout << dt.month << "/" << dt.day << "/" << dt.year << " " << dt.hours << ":" << dt.minutes << ":" <<
         dt.seconds << endl;
}

typedef struct {
    int length; // number of elements in the list
    int capacity; // maximum number of elements that the list can hold
    int *elements; // elements of the list
} ArrayList;

// initializes an ArrayList
void init(ArrayList *list) {
    list->length = 0;
    list->capacity = 1;
    list->elements = (int *) malloc(sizeof(int) * list->capacity);
}

// prints all the elements of an ArrayList
void print(ArrayList list) {
    for (int i = 0; i < list.length; ++i) {
        cout << list.elements[i] << endl;
    }
}

// adds an element to an ArrayList at a specified index
void add(ArrayList *list, int index, int element) {
    int len = list->length;
    int cap = list->capacity;
    if (len + 1 > cap) { // if the ArrayList is full, double its capacity
        list->capacity *= 2;
        int *updated = (int *) malloc(sizeof(int) * cap);
        memcpy(updated, list->elements, sizeof(int) * len);
        free(list->elements);
        list->elements = updated;
    }
    for (int i = list->length; i > index; i--) { // shift elements to the right
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = element; // insert the new element
    list->length++;
}

// deletes an element from an ArrayList at a specified index
void deleteElement(ArrayList *list, int index) {
    for (int i = index; i < list->length - 1; i++) { // shift elements to the left
        list->elements[i] = list->elements[i + 1];
    }
    list->length -= 1;
}

// returns the element at a specified index of an ArrayList
int get(ArrayList *list, int index) {
    return list->elements[index];
}

// sets the element at a specified index of an ArrayList to a specified value
void set(ArrayList *list, int index, int element) {
    list->elements[index] = element;
}

// returns a copy of an ArrayList
ArrayList copy(ArrayList *list) {
    ArrayList newList;
    newList.length = list->length;
    newList.capacity = list->capacity;
    newList.elements = (int *) malloc(sizeof(int) * list->capacity);
    memcpy(newList.elements, list->elements, sizeof(int) * list->length);
    return newList;
}

// trims the capacity of an ArrayList to its length
void trim(ArrayList *list) {
    list->capacity = list->length;
    int *newData = (int *) malloc(sizeof(int) * list->capacity);
    memcpy(newData, list->elements, sizeof(int) * list->length);
    free(list->elements);
    list->elements = newData;
}

// empties an ArrayList
void empty(ArrayList *list) {
    free(list->elements);
    list->length = 0;
    list->capacity = 1;
    list->elements = (int *) malloc(sizeof(int) * list->capacity);
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


    cout << sizeof(dateTime) << endl;
    cout << sizeof(dateTimeBigger) << endl;

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
