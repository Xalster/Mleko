#ifndef HEAP_H
#define HEAP_H
#include <iostream>

class Heap
{
    public:
        int len;
        int *tabw = new int[len]; //tablica dynamiczna

        Heap();
        virtual ~Heap();
        void showHeap(int tab[], int len);
        void addNode(int tab[],int &len, int value);
        void deleteNode(int tab[], int &len);
        void searchHeap();

};

#endif // HEAP_H
