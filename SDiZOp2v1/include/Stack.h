#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <ListElement.h>

class Stack
{
    public:
        Stack();
        virtual ~Stack();
        bool empty();
        int top();
        void pop();
        void push(int t);

    private:
        ListElement *s;
};

#endif // STACK_H
