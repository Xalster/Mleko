#ifndef MYARRAY_H
#define MYARRAY_H
#include <string>


class MyArray
{
private:

int *tab;

protected:

public:
    int tsize;

	MyArray();
	virtual ~MyArray();
    void loadFromFile(std::string filename);
    void show();
    void addElement(int position, int value);
    void addFirstElement(int value);
    void addLastElement(int value);
    void deleteElement(int postition);
    void deleteFirstElement();
    void deleteLastElement();
    void searchTab(int value);
};

#endif // MYARRAY_H
