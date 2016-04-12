#include "MyArray.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

MyArray::MyArray()
{
	tsize = 0;
	int *tab = new int[tsize];
}

MyArray::~MyArray()
{
	delete[] tab;
	tsize = 0;
}

void MyArray::loadFromFile(string filename)
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
        file >> tsize;
        tab = new int[tsize];
        for(int i = 0; file >> tmp;i++)
        {
            tab[i] = tmp;
        }
    }
    file.close();

}

void MyArray::show()
{
    if(tsize == 0)
    {
        cout << "Tablica jest pusta" << endl;
    }
    else
    {
        for(int i = 0;i < tsize;i++)
        {
            cout << tab[i] << setw(5);
        }
        cout << endl;
    }
}

void MyArray::addElement(int position, int value)
{
    if(position < 0 || position >= tsize)
    {
        cout << "Podajesz indeks nie lezacy w zakresie tablicy" << endl;
    }
    else
    {
        tsize++;
        int *stab = new int[tsize];
        for(int i = 0;i < tsize - 1;i++)
        {
            stab[i] = tab[i];
        }
        for(int i = tsize - 1;i > position;i--)
        {
            stab[i] = stab[i - 1];
        }
        stab[position] = value;
        tab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            tab[i] = stab[i];
        }
        delete[] stab;
    }
}

void MyArray::addFirstElement(int value)
{
        tsize++;
        int *stab = new int[tsize];
        for(int i = 0;i < tsize - 1;i++)
        {
            stab[i] = tab[i];
        }
        for(int i = tsize - 1;i > 0;i--)
        {
            stab[i] = stab[i - 1];
        }
        stab[0] = value;
        tab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            tab[i] = stab[i];
        }
        delete[] stab;
}

void MyArray::addLastElement(int value)
{
        tsize++;
        int *stab = new int[tsize];
        for(int i = 0;i < tsize - 1;i++)
        {
            stab[i] = tab[i];
        }
        stab[tsize - 1] = value;
        tab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            tab[i] = stab[i];
        }
        delete[] stab;
}

void MyArray::deleteElement(int position)
{
    if(tsize == 0)
    {
        cout << "Tablica jest pusta, nie ma co usuwaæ" << endl;
    }
    else if(position < 0 || position >= tsize)
    {
        cout << "Podajesz indeks nie le¿¹cy w zakresie tablicy" << endl;
    }
    else
    {
        int *stab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            stab[i] = tab[i];
        }
        for(int i = position;i < tsize-1;i++)
        {
            stab[i] = stab[i+1];
        }
        tsize--;
        tab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            tab[i] = stab[i];
        }
        delete[] stab;
    }
}
void MyArray::deleteFirstElement()
{
    if(tsize == 0)
    {
        cout << "Tablica jest pusta, nie ma co usuwaæ" << endl;
    }
    else
    {
        int *stab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            stab[i] = tab[i];
        }
        tsize--;
        for(int i = 0;i < tsize;i++)
        {
            stab[i] = stab[i + 1];
        }
        tab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            tab[i] = stab[i];
        }
        delete[] stab;
    }
}
void MyArray::deleteLastElement()
{
    if(tsize == 0)
    {
        cout << "Tablica jest pusta, nie ma co usuwaæ" << endl;
    }
    else
    {
        int *stab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            stab[i] = tab[i];
        }
        tsize--;
        stab[tsize] = 0;
        tab = new int[tsize];
        for(int i = 0;i < tsize;i++)
        {
            tab[i] = stab[i];
        }
        delete[] stab;
    }
}

void MyArray::searchTab(int value)
{
    bool is = false;
    for(int i = 0;i < tsize;i++)
    {
        if(tab[i] == value)
        {
            is = true;
            break;
        }
    }
    if(is == false)
    {
        cout << "Brak szukanego elementu w tablicy" << endl;
    }
    else
    {
        cout << "Szukany element jest w tablicy" << endl;
    }
}
