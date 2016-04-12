#include "Heap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

Heap::Heap()
{
    cp = cl = cr = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
    heapsize = 0;
    tab = new int[heapsize];
}

Heap::~Heap()
{
    heapsize = 0;
    delete[] tab;
}

void Heap::loadFromFile(string filename)
{
    int tmp;
    //filename = filename + ".txt";
    const char *filenamec = filename.c_str();
    fstream file;
    file.open(filenamec, ios_base::in);

    if(!file)
    {
        cout << "Nie ma takiego pliku" << endl;
    }
    else
    {
        file >> heapsize;
        tab = new int[heapsize];
        for(int i = 0; file >> tmp;i++)
        {
            tab[i] = tmp;
            makeHeap(tab[i], i);
        }
    }
    file.close();
  //  makeHeap();
}

void Heap::randomHeap(int heapsize)
{
        tab = new int[heapsize];
        for(int i = 0;i < heapsize;i++)
        {
            tab[i] = rand()%100;
            makeHeap(tab[i],i);
        }
}
void Heap::makeHeap(int value, int i)
{
    int j;

    j = (i - 1) / 2;

    while(i > 0 && tab[j] < value)
    {
        tab[i] = tab[j];
        i = j;
        j = (i - 1) / 2;
    }

    tab[i] = value;

}
void Heap::showTab()
{
    for(int i = 0; i < heapsize;i++)
    {
        cout << tab[i] << " ";
    }
}
void Heap::show(string sp, string sn, int value)
{
    if(heapsize == 0)
    {
        cout << "Kopiec jest pusty" << endl;
    }

  if(value < heapsize)
  {
    string txt;
    txt = sp;
    if(sn == cr)
    {
        txt[txt.length() - 2] = ' ';
    }
    show(txt + cp, cr, 2 * value + 2);

    txt = txt.substr(0,sp.length()-2);

    cout << txt << sn << tab[value] << endl;

    txt = sp;
    if(sn == cl)
    {
        txt[txt.length() - 2] = ' ';
    }
    show(txt + cp, cl, 2 * value + 1);
  }
}

bool Heap::searchHeap(int value)
{
    bool is = false;
    for(int i = 0;i <= heapsize;i++)
    {
        if(value == tab[i])
        {
            is = true;
            break;
        }
    }
    if(is == true)
    {
        cout << "Szukany element jest w kopcu" << endl;
    }
    else
    {
        cout << "Szukanego elementu nie ma w kopcu" << endl;
    }
    return is;
}

void Heap::addNode(int value)
{
    int i,j;
    i = heapsize++;
    int *stab = new int[heapsize];
    for(int in = 0;in < heapsize;in++)
    {
        stab[in] = tab[in];
    }
    j = (i - 1) / 2;

    while(i > 0 && stab[j] < value)
    {
        stab[i] = stab[j];
        i = j;
        j = (i - 1) / 2;
    }
    stab[i] = value;
    tab = new int[heapsize];
    for(int in = 0;in < heapsize;in++)
    {
        tab[in] = stab[in];
    }
    delete[] stab;
}

void Heap::deleteRoot()
{
    if(heapsize==0)
    {
        cout << "Kopiec jest pusty" << endl;
    }
    else
    {
        int i,j,value;

        if(heapsize--)
        {
            value = tab[heapsize];

            i = 0;
            j = 1;

            while(j < heapsize)
                {
                    if(j + 1 < heapsize && tab[j + 1] > tab[j])
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
}
