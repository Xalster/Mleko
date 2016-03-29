#include "MyList.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

MyList::MyList()
{
    head = tail = NULL;
    listsize = 0;
}

MyList::~MyList()
{
    MyListElement *element;

    while(head)
    {
        element = head->next;
        delete head;
        head = element;
    }
    listsize = 0;
}

void MyList::loadFromFile(string filename)
{
    int tmp;
    filename = filename + ".txt";
    const char *filenamec = filename.c_str();
    fstream file;
    file.open(filenamec, ios_base::in);

    if(!file)
    {
        cout << "Nie ma takiego pliku" << endl;
    }
    else
    {
        file >> listsize;
        for(int i = 1;file >> tmp;i++)
        {
            //int key = tmp;
            addLastElement(tmp);
        }
    }
    listsize = listsize / 2;
    file.close();
}
bool MyList::searchList(int value)
{
    bool is = false;
    MyListElement *element;
    element = head;
    for(int i = 0;i <= listsize;i++)
    {
        if(element->key == value)
            {
               is = true;
               break;
            }
            else
            {
                element = element->next;
            }
    }
    if(is == true)
        {
            cout << "Szukana wartosc jest w lisce" << endl;
        }
        else
        {
            cout << "Szukanej wartosci nie ma na liscie" << endl;
        }
    return is;
}

void MyList::addAfterKey(int position, int nkey)
{
    MyListElement *element;
    MyListElement *nelement = new MyListElement();
    if(!(searchList(position)))
    {
        cout << "Brak podanego elementu na liscie" << endl;
    }
    else
    {
        element = head;
        for(int i = 0;i <= listsize;i++)
        {
            if(element->key == position)
            {
                nelement->next = element->next;
                nelement->prev = element;
                if(nelement->next)
                {
                    nelement->next->prev = nelement;
                }
                else
                {
                    tail = nelement;
                }
                nelement->key = nkey;
                listsize++;
                break;

            }
            else
            {
                element = element->next;
            }
        }
    }
}

void MyList::addFirstElement(int nkey)
{
    MyListElement *nelement = new MyListElement();
    nelement->next = head;
    nelement->prev = NULL;
    if(head)
    {
        head->prev = nelement;
    }
    head = nelement;
    if(!tail)
    {
        tail = head;
    }
    nelement->key = nkey;
    listsize++;
}

void MyList::addLastElement(int nkey)
{
    MyListElement *nelement = new MyListElement();
    nelement->prev = tail;
    nelement->next = NULL;
    if(tail)
    {
        tail->next = nelement;
    }
    tail = nelement;
    if(!head)
    {
        head = tail;
    }
    nelement->key = nkey;
    listsize++;
}

void MyList::deleteFirstElement()
{
    if(listsize == 0)
    {
        cout << "Lista jest pusta" << endl;
    }
    else
    {
        head = head->next;
        listsize--;
    }
}

void MyList::deleteLastElement()
{
    if(listsize == 0)
    {
        cout << "Lista jest pusta" << endl;
    }
    else
    {
        tail->prev->next = NULL;
        tail->prev = tail;
        listsize--;
    }
}

void MyList::deleteElement(int key)
{
    MyListElement *element;
    element = head;
    if(listsize == 0)
    {
        cout << "Lista jest pusta" << endl;
    }
    else
    {
        while ((element->next != NULL) && (element->key != key))
        {
            element = element->next;
        }
        if(element->key == key)
        {
            if(element->next)
            {
                element->next->prev = element->prev;
            }
            else
            {
                tail = element->prev;
            }
            if(element->prev)
            {
                element->prev->next = element->next;
            }
            else
            {
                head = element->next;
            }
            listsize--;
        }
        else
        {
            cout << "Brak podanego elementu na lisce" << endl;
        }
    }

}

void MyList::show()
{
    MyListElement *element = new MyListElement();
    int i = 1;
    if(!head)
    {
        cout << "Lista jest pusta" << endl;
    }
    else
    {
        element = head;
        while(element)
        {
            cout << i << ". " << element->key << endl;
            element = element->next;
            i++;
        }
        cout << endl;
    }
    delete element;
}
