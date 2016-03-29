#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <iostream>

using namespace std;

class Heap
{
private:
    int *tab;
    string cr, cp, cl;
public:
    int heapsize;
    Heap();
    virtual ~Heap();
    void loadFromFile(string filename);
    void randomHeap(int heapsize);
    void makeHeap(int value, int i);
    void showTab();
    void show(string sp, string sn, int v);
    bool searchHeap(int value);
    void addNode(int value);
    void deleteRoot();
};

#endif // HEAP_H
