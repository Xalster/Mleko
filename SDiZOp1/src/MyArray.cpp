#include "MyArray.h"
#include <iostream>
#include <iomanip>

using namespace std;

MyArray::MyArray()
{
    //ctor
}

void MyArray::randomTab(int tab[], int len)
    {
        for(int i = 0;i < len;i++)
        {
            tab[i] = rand()%100;
        }
    }

void MyArray::showTab (int tab[], int len)
    {
        for(int i = 0;i < len;i++)
        {
            cout << tab[i] << setw(2)<< " ";
            if(i%11==10)
            {
                cout << endl;
            }
        }
        cout <<endl;
    }

void MyArray::searchElement(int tab[], int len, int value)
{
    int counter=0;
    for(int i = 0;i<len;i++)
    {
        if(value==tab[i])
            counter++;
    }
    cout << counter << endl;
}
    //dodawanie elementu do tablicy dynamicznej
void MyArray::addElement (int tab[], int &len, int pos, int value)
    {
        len++;
        int *tabn = new int[sizeof(int)* (len + 1)];
        memcpy(tabn, tabw, sizeof(int)*len);
        for(int i = len; i > pos;i--)
            {
                tabn[i] = tabn[i-1];
            }
        tabn[pos] = value;
        memcpy(tabw, tabn, sizeof(int)*(len+1));
        delete[] tabn;
     // return tabw;
    }

    //usuwanie elementu z tablicy dynamicznej
void MyArray::deleteElement (int tab[], int &len, int pos)
    {
        len--;
        int *tabn = new int[sizeof(int)* (len + 1)];
        for(int i = pos; i < len;i++)
            {
                tabw[i] = tabw[i+1];
            }
        memcpy(tabn, tabw, sizeof(int)*(len));
        memcpy(tabw, tabn, sizeof(int)*(len));
        delete[] tabn;
     // return tabw;
    }


MyArray::~MyArray()
{
    //dtor
    delete[] tabw;
}
