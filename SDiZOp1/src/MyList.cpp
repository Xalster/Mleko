#include "MyList.h"
#include <iostream>
#include <iomanip>

using namespace std;

MyList::MyList()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

void MyList::show()
{
    dlistElem *p;
    p = head;
    while(p)
    {
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
}

//Dodawanie na pocz¹tku listy
void MyList::addFront(int value)
{
    dlistElem *p;

    p = new dlistElem;
    p->data = value;
    p->prev = NULL;
    p->next = head;
    head = p;
    count++;
    if(p->next)
        {
            p->next->prev = p;
        }else
        {
            tail = p;
        }
}

//Dodawanie na koniec listy
void MyList::addEnd(int value)
{
    dlistElem *p;

    p = new dlistElem;
    p->data = value;
    p->next = NULL;
    p->prev = tail;
    tail = p;
    count++;
    if(p->prev)
    {
        p->prev->next = p;
    }else
    {
        head = p;
    }
}

//Dodawanie przed wybranym
void MyList::insertElem(dlistElem *elem, int value)
{
    dlistElem *p;

    if(elem == head)
    {
        addFront(value);
    }else
    {
        p = new dlistElem;
        p->data = value;
        p->next = elem;
        p->prev = elem->prev;
        count++;
        elem->prev->next = p;
        elem->prev = p;
    }
}

//usuwanie wybrany element
void MyList::deleteElem(dlistElem *elem)
{
    count--;
    if(elem->prev)
    {
        elem->prev->next = elem->next;
    }else
    {
        head = elem->next;
    }
    if(elem->next)
    {
        elem->next->prev = elem->prev;
    }else
    {
        tail = elem->prev;
    }
    delete elem;
}

//przeszukiwanie listy
dlistElem *MyList::searchList(int value)
{
    dlistElem * p;
    addEnd(value);
    p = head;
    while(p->data != value) p = p->next;
    if(p == tail) p = NULL;
    deleteEnd();
    return p;
}

//usuwanie z pocztaku
void MyList::deleteFront()
{
    if(count)
    {
        deleteElem(head);
    }
}

//usuwanie z koñca
void MyList::deleteEnd()
{
    if(count)
    {
        deleteElem(tail);
    }
}

MyList::~MyList()
{
    //dtor
    while(count) deleteFront();
}
