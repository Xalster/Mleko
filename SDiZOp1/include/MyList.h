#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>

 struct dlistElem
    {
        dlistElem *next;
        dlistElem *prev;
        int data;
    };

class MyList
{
    public:
        dlistElem *head;  // pocz¹tek listy
        dlistElem *tail;  // koniec listy
        int count;  // licznik elementów

        MyList();
        virtual ~MyList();

        void show();
        void addFront(int value);
        void addEnd(int value);
        void insertElem(dlistElem *elem, int value);
        void deleteElem(dlistElem *elem);
        dlistElem *searchList(int value);
        void deleteFront();
        void deleteEnd();



};

#endif // MYLIST_H
