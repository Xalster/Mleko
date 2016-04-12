#include <iostream>
#include <time.h>
#include <cstdlib>
#include <MyArray.h>
#include <MyList.h>
#include <Heap.h>
#include <RBT.h>
#include <windows.h>


using namespace std;

double PCFreq = 0.0;
__int64 timer = 0;

void timerStart()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Błąd!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	timer = li.QuadPart;
}
void timerStop()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operacja zajela: " << (li.QuadPart - timer) / PCFreq << " milisekund" << endl;

}

LARGE_INTEGER startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return start;
}
LARGE_INTEGER endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}


int main()
{
    srand(time(NULL));
    int choice;
    bool tostart = true;
    while(tostart == true)
    {
        tostart = false;
        cout << "Wybierz co chcesz przetestowac" << endl;
        cout << "1. Tablica" << endl << "2. Lista" << endl << "3. Kopiec" << endl << "4. Drzewo RBT" << endl << "5. Wyjdz" <<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                MyArray *myarray = new MyArray();
                tostart = false;
                int tsize;
                while(tostart == false)
                {
                    cout << "Aktualnie w tablicy jest " << myarray->tsize << " elementow" << endl;
                    cout << "Co chcesz zrobic ?" << endl << "1. Wczytaj z pliku" << endl << "2. Usun" << endl;
                    cout << "3. Dodaj" << endl << "4. Wyszukaj" << endl << "5. Wyswietl" << endl;
                    cout << "6. Zniszcz strukture" << endl << "7. Wroc do wyboru struktury" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        {
                            string filename;
                            myarray = new MyArray();
                            cout << "Podaj nazwe pliku" << endl;
                            cin >> filename;
                            cout << endl;
                            myarray->loadFromFile(filename);

                        }break;
                    case 2:
                        {
                            cout << "1. Usun z poczatku" << endl << "2. Usun z wybranego miejsca" << endl << "3. Usun z konca" << endl;
                            cin >> choice;
                            switch (choice)
                            {
                            case 1:
                                {
                                    timerStart();
                                    myarray->deleteFirstElement();
                                    timerStop();

                                }break;
                            case 2:
                                {
                                    int position;
                                    do
                                    {
                                        cout << "Podaj indeks elementu do wyrzucenia" << endl;
                                        cin >> position;
                                        if(position <= 0)
                                        {
                                            cout << "Podaj dodatni indeks!" << endl;
                                        }
                                    }while(position <= 0);
                                    timerStart();
                                    myarray->deleteElement(position);
                                    timerStop();
                                }break;
                            case 3:
                                {
                                    timerStart();
                                    myarray->deleteLastElement();
                                    timerStop();
                                }break;
                            default:
                                {
                                    break;
                                }
                            }
                        }break;
                    case 3:
                        {
                                int value;
                                cout << "1. Dodaj na poczatek" << endl << "2. Dodaj na wybrane miejsce" << endl << "3. Dodaj na koncu" << endl;
                                cin >> choice;
                                switch (choice)
                                {
                                case 1:
                                    {
                                        cout << "Podaj wartosc elementu" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        myarray->addFirstElement(value);
                                        timerStop();
                                        }break;
                                case 2:
                                    {
                                        int position;
                                        do
                                        {
                                            cout << "Podaj indeks elementu" << endl;
                                            cin >> position;
                                            cout << endl;
                                            if(position <= 0)
                                            {
                                                cout << "Podaj dodatni indeks!" << endl;
                                            }
                                            cout << "Podaj wartosc elemntu" << endl;
                                            cin >> value;
                                            cout << endl;
                                        }while(position <= 0);
                                        timerStart();
                                        myarray->addElement(position, value);
                                        timerStop();
                                    }break;
                                case 3:
                                    {
                                        cout << "Podaj wartosc elementu" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        myarray->addLastElement(value);
                                        timerStop();
                                    }break;
                                default:
                                    {
                                        break;
                                    }
                                }
                        }break;
                    case 4:
                        {
                            int value;
                            cout << "Podaj szukana wartosc" << endl;
                            cin >> value;
                            cout << endl;
                            timerStart();
                            myarray->searchTab(value);
                            timerStop();
                        }break;
                    case 5:
                        {
                            myarray->show();
                        }break;
                    case 6:
                        {
                            myarray->~MyArray();
                            myarray = new MyArray();
                        }break;
                    case 7:
                        {
                            delete myarray;
                            tostart = true;
                        }break;
                    default:
                        {
                            break;
                        }
                        }
                    }
                }break;
                    case 2:
                        {
                            int value;
                            MyList *mylist;
                            tostart = false;
                            mylist = new MyList();
                            while(tostart == false)
                            {
                                cout << "Aktualnie lista ma " << mylist->listsize << " elementow" << endl << "Co chcesz zrobic z ta struktura?" <<
                                endl << "1. Wczytaj z pliku "  << endl << "2. Usun" << endl << "3. Dodaj" << endl << "4. Wyszukaj" <<
                                endl << "5. Wyswietl" << endl << "6. Zniszcz strukture" << endl << "7. Wroc do wyboru struktury" << endl;
                                cin >> choice;
                                switch (choice)
                                {
                                case 1:
                                    {
                                        mylist->~MyList();
                                        mylist = new MyList();
                                        string filename;
                                        cout << "Podaj nazwe pliku" << endl;
                                        cin >> filename;
                                        cout << endl;
                                        mylist->loadFromFile(filename);
                                    }break;
                                case 2:
                                    {
                                        cout << "1. Usun z poczatku " << endl << "2. Usun wybrany" << endl << "3. Usun z konca" << endl;
                                        cin >> choice;
                                        switch (choice)
                                        {
                                        case 1:
                                            {
                                                timerStart();
                                                mylist->deleteFirstElement();
                                                timerStop();
                                            }break;
                                        case 2:
                                            {
                                                cout << "Podaj klucz elementu" << endl;
                                                cin >> value;
                                                cout << endl;
                                                timerStart();
                                                mylist->deleteElement(value);
                                                timerStop();
                                            }break;
                                        case 3:
                                            {
                                                timerStart();
                                                mylist->deleteLastElement();
                                                timerStop();
                                            }break;
                                        default:
                                            {
                                                break;
                                            }
                                            }
                                    }break;
                                case 3:
                                    {
                                        cout << "1. Dodaj na poczatek " << endl << "2. Dodaj za wybrany element" << endl << "3. Dodaj na koncu" << endl;
                                        cin >> choice;
                                        cout << endl;
                                        switch (choice)
                                        {
                                        case 1:
                                            {
                                                cout << "Podaj klucz" << endl;
                                                cin >> value;
                                                cout << endl;
                                                timerStart();
                                                mylist->addFirstElement(value);
                                                timerStop();
                                            }break;
                                        case 2:
                                            {
                                                int key;
                                                cout << "Podaj klucz" << endl;
                                                cin >> value;
                                                cout << endl;
                                                cout << "Za ktory element (podaj klucz)" << endl;
                                                cin >> key;
                                                cout << endl;
                                                timerStart();
                                                mylist->addAfterKey(key, value);
                                                timerStop();
                                            }break;
                                        case 3:
                                            {
                                                cout << "Podaj klucz" << endl;
                                                cin >> value;
                                                cout << endl;
                                                timerStart();
                                                mylist->addLastElement(value);
                                                timerStop();
                                            }break;
                                        default:
                                            {
                                                break;
                                            }
                                        }
                                    }break;
                                case 4:
                                    {
                                        cout << "Podaj klucz do wyszukania" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        mylist->searchList(value);
                                        timerStop();
                                    }break;
                                case 5:
                                    {
                                        mylist->show();
                                    }break;
                                case 6:
                                    {
                                        mylist->~MyList();
                                        mylist = new MyList();
                                    }break;
                                case 7:
                                    {
                                        delete mylist;
                                        tostart = true;
                                    }break;
                                default:
                                    {
                                        break;
                                    }
                                }
                            }
                        }break;
                    case 3:
                        {
                            int value;
                            Heap *heap;
                            tostart = false;
                            heap = new Heap();
                            while(tostart == false)
                            {
                                cout << "Kopiec aktualnie ma " << heap->heapsize << " elementow" << endl << "Co chcesz zrobic z ta struktura?" <<
                                endl << "1. Wczytaj z pliku " << endl << "2. Usun korzen" << endl << "3. Dodaj" << endl << "4. Wyszukaj" <<
                                endl << "5. Wyswietl" << endl << "6. Zniszcz strukture" << endl << "7. Wroc do wyboru struktury" << endl;
                                cin >> choice;
                                switch (choice)
                                {
                                case 1:
                                    {
                                        string filename;
                                        cout << "Podaj nazwe pliku" << endl;
                                        cin >> filename;
                                        cout << endl;
                                        heap = new Heap();
                                        heap->loadFromFile(filename);
                                    }break;
                                case 2:
                                    {
                                        timerStart();
                                        heap->deleteRoot();
                                        timerStop();
                                    }break;
                                case 3:
                                    {
                                        cout << "Podaj co chcesz wstawic" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        heap->addNode(value);
                                        timerStop();
                                    }break;
                                case 4:
                                    {
                                        cout << "Podaj czego szukasz" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        heap->searchHeap(value);
                                        timerStop();
                                    }break;
                                case 5:
                                    {
                                        heap->show("", "", 0);
                                        //heap->showTab();
                                    }break;
                                case 6:
                                    {
                                        heap->~Heap();
                                        heap = new Heap();
                                    }break;
                                case 7:
                                    {
                                        delete heap;
                                        tostart = true;
                                    }break;
                                default:
                                    {
                                        break;
                                    }

                                }
                            }
                        }break;
                    case 4:
                        {
                            int value;
                            RBT *rbt = new RBT();
                            tostart = false;
                            while(tostart == false)
                            {
                                cout << "Aktualnie RBT ma " << rbt->rbtsize << " elementow" << endl << "Co chcesz zrobic z ta struktura?" <<
                                endl << "1. Wczytaj z pliku " << endl << "2. Usun" << endl << "3. Dodaj" << endl << "4. Wyszukaj" <<
                                endl << "5. Wyswietl" << endl << "6. Zniszcz strukture" << endl << "7. Wroc do wyboru struktury" << endl;
                                cin >> choice;
                                cout << endl;
                                switch (choice)
                                {
                                case 1:
                                    {
                                        rbt->~RBT();
                                        rbt = new RBT();
                                        string filename;
                                        cout << "Podaj nazwe pliku" << endl;
                                        cin >> filename;
                                        cout << endl;
                                        rbt->loadFromFile(filename);
                                    }break;
                                case 2:
                                    {
                                        cout << "Podaj element do usuniecia" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        rbt->removeNode(value);
                                        timerStop();
                                    }break;
                                case 3:
                                    {
                                        cout << "Podaj wartosc elementu" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        rbt->addNode(value);
                                        timerStop();
                                    }break;
                                case 4:
                                    {
                                        cout << "Podaj element do znalezienia" << endl;
                                        cin >> value;
                                        cout << endl;
                                        timerStart();
                                        rbt->checkElement(value);
                                        timerStop();
                                    }break;
                                case 5:
                                    {
                                        rbt->show("    ", "", rbt->root);
                                    }break;
                                case 6:
                                    {
                                        rbt->~RBT();
                                        rbt = new RBT();
                                    }break;
                                case 7:
                                    {
                                        delete rbt;
                                        tostart = true;
                                    }break;
                                default:
                                    {
                                        break;
                                    }
                                }
                            }
                        }break;
                case 5:
                    {
                        return 0;
                    }break;
                default:
                {
                    break;
                }


            }
        }

    return 0;
}
