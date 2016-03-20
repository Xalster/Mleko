#include <iostream>
#include <time.h>
#include <cstdlib>
#include <MyArray.h>
#include <MyList.h>
#include <Heap.h>
#include <RedBlackTree.h>
#include <windows.h>
#include <fstream>
#define MAXN 10

using namespace std;

LARGE_INTEGER startTimer() {
    LARGE_INTEGER start;
    DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
    QueryPerformanceCounter(&start);
    SetThreadAffinityMask(GetCurrentThread(), oldmask);
    return start;
}

LARGE_INTEGER endTimer() {
    LARGE_INTEGER stop;
    DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
    QueryPerformanceCounter(&stop);
    SetThreadAffinityMask(GetCurrentThread(), oldmask);
    return stop;
}

void loadFromFile(char url[])
{
    fstream myfile;
    myfile.open(url, ios_base::in);

    int a, len = 0;
    myfile >> len;
    int *tab = new int[len];
    for(int i = 0;myfile >> a;i++)
    {
        tab[i] = a;
    }
    cout << "Rozmiar:" << len << endl;
    for(int i = 0;i<len;i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << sizeof(*tab);
    delete[] tab;
    myfile.close();
}

int main()
{
    char url[100] = "D:\\Code\\data.txt";

    loadFromFile(url);
    srand(time(NULL));
    /*MyArray* lista1 = new MyArray;
    lista1->len = 0;
    //lista1->len = 10;
    //lista1->randomTab(lista1->tabw, lista1->len);
    lista1->showTab(lista1->tabw, lista1->len);
    LARGE_INTEGER performanceCountStart,performanceCountEnd;
    performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
    lista1->addElement(lista1->tabw, lista1->len, 0, 10);
    performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
    double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    cout << endl << "Time:" <<tm <<endl;
    lista1->showTab(lista1->tabw, lista1->len);
    lista1->searchElement(lista1->tabw, lista1->len, 10);
    lista1->deleteElement(lista1->tabw, lista1->len,5);
    lista1->showTab(lista1->tabw, lista1->len);
    delete lista1;*/
    //lista dwukierunkowa
    /*MyList L;

    L.show();
    for(int i = 0; i <= 5; i++) L.addFront(i);
    L.show();
    for(int i = 6; i <= 10; i++) L.addEnd(i);
    L.show();
    L.insertElem(L.tail->prev, 11);
    L.show();
    //L.insert_after(L.head,'%');
    //L.printl();
    L.deleteFront();
    L.show();
    L.deleteEnd();
    L.show();
    L.deleteElem(L.head->next->next);
    L.show();*/

    /*Heap *kopiec = new Heap;
    kopiec->len = 0;
    kopiec->addNode(kopiec->tabw, kopiec->len,5);
    kopiec->showHeap(kopiec->tabw, kopiec->len);
    kopiec->addNode(kopiec->tabw, kopiec->len,50);
    kopiec->showHeap(kopiec->tabw, kopiec->len);
    kopiec->addNode(kopiec->tabw, kopiec->len,25);
    kopiec->showHeap(kopiec->tabw, kopiec->len);
    kopiec->deleteNode(kopiec->tabw, kopiec->len);
    kopiec->showHeap(kopiec->tabw, kopiec->len);
    delete kopiec;*/

    /*int Tk[MAXN];          // Tablica kluczy wêz³ów
    int i,x,i1,i2;
    RedBlackTree *RBT;         // Obiekt drzewa czerwono-czarnego
    RBT = new RedBlackTree;     // Tworzymy puste drzewo
    for(i = 0; i < MAXN; i++) // Tablicê wype³niamy wartoœciami kluczy
    {
        Tk[i] = i + 1;
    }
    for(i = 0; i < 300; i++)  // Mieszamy tablicê
    {
        i1 = rand() % MAXN;     // Losujemy 2 indeksy
        i2 = rand() % MAXN;
        x = Tk[i1];             // Wymieniamy Tk[i1] <-->. Tk[i2]
        Tk[i1] = Tk[i2];
        Tk[i2] = x;
    }
    for(i = 0; i < MAXN; i++) // Na podstawie tablicy tworzymy drzewo czerwono-czarne
    {
        cout << Tk[i] << " ";
        RBT->insertNode(Tk[i]);
    }
    cout << endl << endl;
    RBT->print();             // Wyœwietlamy zawartoœæ drzewa
    cout << endl << endl;
    RBT->print();            // Wyœwietlamy zawartoœæ drzewa
    delete RBT;*/

    return 0;
}
