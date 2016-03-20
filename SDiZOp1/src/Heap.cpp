#include "Heap.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Heap::Heap()
{
    //ctor
}

void Heap::showHeap(int tab[], int len)
{
 for(int i = 0;i < len;i++)
        {
            cout << tab[i] << " ";
            if(i%11==10)
            {
                cout << endl;
            }
        }
        cout <<endl;
}

void Heap::addNode(int tab[], int &len, int value)
{
    int i = len++;
    int j = (i - 1) / 2;

    while(i > 0 && tab[j] < value)
    {
        tab[i] = tab[j];
        i = j;
        j = (i - 1) / 2;
    }

    tab[i] = value;
}

void Heap::deleteNode(int tab[], int &len)
{
    int i,j,value;

  if(len--)
  {
    value = tab[len];

    i = 0;
    j = 1;

    while(j < len)
    {
        if(j + 1 < len && tab[j + 1] > tab[j])
        {
            j++;
        }
        if(value >= tab[j])
        {
            break;
        }

        tab[i] = tab[j];
        i = j;
        j = 2 * j + 1;
    }

    tab[i] = value;
  }
}

void Heap::searchHeap()
{

}

Heap::~Heap()
{
    //dtor
}
