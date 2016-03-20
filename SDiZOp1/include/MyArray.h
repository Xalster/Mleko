#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class MyArray
{
    public:
        int len;
        int *tabw = new int[len]; //tablica dynamiczna

        MyArray();
        virtual ~MyArray();

        void randomTab(int tab[], int len);
        void showTab (int tab[], int len);
        void searchElement(int tab[], int len, int value);
         //dodawanie elementu do tablicy dynamicznej
        void addElement (int tab[], int &len, int pos, int value);
         //usuwanie elementu z tablicy dynamicznej
        void deleteElement (int tab[], int &len, int pos);


};

#endif // MYARRAY_H
