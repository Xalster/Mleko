#include "Stack.h"

Stack::Stack()
{
    s = NULL;
}

Stack::~Stack()
{
    while(s)
    {
        pop();
    }
}

bool Stack::empty()
{
    return !s;
}

int Stack::top()
{
    return s->t;
}

void Stack::pop()
{
    if(s)
    {
        ListElement *elem = s;
        s = s->next;
        delete elem;
    }
}

void Stack::push(int t)
{
    ListElement *elem = new ListElement;
    elem->t = t;
    elem->next = s;
    s = elem;
}
