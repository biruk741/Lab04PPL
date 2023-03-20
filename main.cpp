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
    cout << (dt.month < 10 ? "0" : "") << dt.month << "/";
    cout << (dt.day < 10 ? "0" : "") << dt.day << "/";
    cout << dt.year << " ";
    cout << (dt.hours < 10 ? "0" : "") << dt.hours << ":";
    cout << (dt.minutes < 10 ? "0" : "") << dt.minutes << ":";
    cout << (dt.seconds < 10 ? "0" : "") << dt.seconds << endl;
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
    cout << "[";
    for (int i = 0; i < list.length; i++) {
        cout << list.elements[i];
        if (i != list.length - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
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

    cout << "-----------------------------" << endl;
    cout << "Now testing ArrayList struct:" << endl;

    // initialize the ArrayList
    ArrayList list;
    init(&list);
    cout << "Initialized the ArrayList." << endl;

    cout << "Adding elements to the arraylist:" << endl;

    for (int i = 0; i < 5; i++) {
        add(&list, i, i + 1);
    }

    // print all the elements of the ArrayList
    cout << "ArrayList elements: ";
    print(list);
    // delete the element at index 2 from the ArrayList
    deleteElement(&list, 2);
    cout << "Deleted the element at index 2 from the ArrayList." << endl;
    // print all the elements of the ArrayList
    cout << "ArrayList elements: ";
    print(list);
    // get the element at index 2 from the ArrayList
    cout << "The element at index 2 of the ArrayList: " << get(&list, 2) << endl;
    // set the element at index 2 of the ArrayList to 6
    set(&list, 2, 6);
    cout << "Set the element at index 2 of the ArrayList to 6." << endl;
    // print all the elements of the ArrayList
    cout << "ArrayList elements: ";
    print(list);
    // create a copy of the ArrayList
    ArrayList newList = copy(&list);
    cout << "Created a copy of the ArrayList." << endl;
    // print all the elements of the copy of the ArrayList
    cout << "All the elements of the copy of the ArrayList: ";
    print(newList);
    // free the memory allocated for the copy of the ArrayList
    free(newList.elements);
    cout << "Freed the memory allocated for the copy of the ArrayList." << endl;
    // trim the capacity of the ArrayList to its length
    trim(&list);
    cout << "Trimmed the capacity of the ArrayList to its length." << endl;
    // print all the elements of the ArrayList
    cout << "ArrayList elements: ";
    cout << "Length: " << list.length <<", Capacity: " << list.capacity<<endl;
    print(list);
    // empty the ArrayList
    empty(&list);
    cout << "Emptied the ArrayList." << endl;
    // print all the elements of the ArrayList
    cout << "ArrayList elements: ";
    print(list);
    // free the memory allocated for the ArrayList
    free(list.elements);
    cout << "Freed the memory allocated for the ArrayList." << endl;

    return 0;
}
