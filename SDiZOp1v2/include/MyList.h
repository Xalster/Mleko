#ifndef MYLIST_H
#define MYLIST_H
#include <string>

class MyListElement
{
public:
    MyListElement *next, *prev;
    int key;

};
class MyList
{
private:
    MyListElement *head, *tail;
public:
    int listsize;
    MyList();
    virtual ~MyList();
    void loadFromFile(std::string filename);
    bool searchList(int value);
    void addAfterKey(int position, int nkey);
    void addFirstElement(int nkey);
    void addLastElement(int nkey);
    void deleteFirstElement();
    void deleteLastElement();
    void deleteElement(int key);
    void show();

};

#endif // MYLIST_H
