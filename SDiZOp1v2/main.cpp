#include <iostream>
#include <time.h>
#include <cstdlib>
#include <MyArray.h>
#include <MyList.h>
#include <Heap.h>
#include <RBT.h>
#include <windows.h>


using namespace std;

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
    do
    {
        cout << "Wybierz co chcesz przetestowaæ" << endl;
        cout << "1. Tablica" << endl << "2. Lista" << endl << "3. Kopiec" << endl << "4. Drzewo RBT" << endl << "5. Wyjdz" <<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                MyArray *myarray = new MyArray();
                int tsize;
                do
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
                                    LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                    performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                    myarray->deleteFirstElement();
                                    performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                    double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                    cout << endl << "Time:" << tm <<endl;

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
                                    LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                    performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                    myarray->deleteElement(position);
                                    performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                    double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                    cout << endl << "Time:" <<tm <<endl;
                                }break;
                            case 3:
                                {
                                    LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                    performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                    myarray->deleteLastElement();
                                    performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                    double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                    cout << endl << "Time:" <<tm <<endl;
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
                                        LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                        performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                        myarray->addFirstElement(value);
                                        performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                        double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                        cout << endl << "Time:" <<tm <<endl;
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
                                        LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                        performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                        myarray->addElement(position, value);
                                        performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                        double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                        cout << endl << "Time:" <<tm <<endl;
                                    }break;
                                case 3:
                                    {
                                        cout << "Podaj wartosc elementu" << endl;
                                        cin >> value;
                                        cout << endl;
                                        LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                        performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                        myarray->addLastElement(value);
                                        performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                        double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                        cout << endl << "Time:" <<tm <<endl;
                                    }break;
                                }
                        }break;
                    case 4:
                        {
                            int value;
                            cout << "Podaj szukana wartoœæ" << endl;
                            cin >> value;
                            cout << endl;
                            LARGE_INTEGER performanceCountStart,performanceCountEnd;
                            performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                            myarray->searchTab(value);
                            performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                            double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                            cout << endl << "Time:" <<tm <<endl;
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
                        }break;
                        }
                    }while(choice != 7);
                }break;
                    case 2:
                        {
                            int value;
                            MyList *mylist;
                            mylist = new MyList();
                            do
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
                                                LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                                performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                                mylist->deleteFirstElement();
                                                performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                                double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                                cout << endl << "Time:" <<tm <<endl;
                                            }break;
                                        case 2:
                                            {
                                                cout << "Podaj klucz elementu" << endl;
                                                cin >> value;
                                                cout << endl;
                                                LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                                performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                                mylist->deleteElement(value);
                                                performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                                double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                                cout << endl << "Time:" <<tm <<endl;
                                            }break;
                                        case 3:
                                            {
                                                LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                                performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                                mylist->deleteLastElement();
                                                performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                                double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                                cout << endl << "Time:" <<tm <<endl;
                                            }break;
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
                                                LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                                performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                                mylist->addFirstElement(value);
                                                performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                                double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                                cout << endl << "Time:" <<tm <<endl;
                                            }break;
                                        case 2:
                                            {
                                                int key;
                                                cout << "Podaj klucz" << endl;
                                                cin >> value;
                                                cout << endl;
                                                cout << "Za który element (podaj klucz)" << endl;
                                                cin >> key;
                                                cout << endl;
                                                LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                                performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                                mylist->addAfterKey(key, value);
                                                performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                                double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                                cout << endl << "Time:" <<tm <<endl;
                                            }break;
                                        case 3:
                                            {
                                                cout << "Podaj klucz" << endl;
                                                cin >> value;
                                                cout << endl;
                                                LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                                performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                                mylist->addLastElement(value);
                                                performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                                double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                                cout << endl << "Time:" <<tm <<endl;
                                            }break;
                                        }
                                    }break;
                                case 4:
                                    {
                                        cout << "Podaj klucz do wyszukania" << endl;
                                        cin >> value;
                                        cout << endl;
                                        LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                        performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                        mylist->searchList(value);
                                        performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                        double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                        cout << endl << "Time:" <<tm <<endl;
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
                                    }break;
                                }
                            }while(choice != 7);
                        }break;
                    case 3:
                        {
                            int value;
                            Heap *heap;
                            heap = new Heap();
                            do
                            {
                                cout << "Kopiec aktualnie ma " << heap->heapsize << " elementow" << endl << "Co chcesz zrobic z ta struktura?" <<
                                endl << "1. Zbuduj z pliku " << endl << "2. Usun korzen" << endl << "3. Dodaj" << endl << "4. Wyszukaj" <<
                                endl << "5. Wyswietl" << endl << "6. Zniszcz strukture" << endl << "7. Wroc do wyboru struktury" << endl;
                                cin >> choice;
                                switch (choice)
                                {
                                case 1:
                                    {
                                        string filename;
                                        cout << "Podaj plikl" << endl;
                                        cin >> filename;
                                        cout << endl;
                                        heap = new Heap();
                                        heap->loadFromFile(filename);
                                    }break;
                                case 2:
                                    {
                                        LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                        performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                        heap->deleteRoot();
                                        performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                        double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                        cout << endl << "Time:" <<tm <<endl;
                                    }break;
                                case 3:
                                    {
                                        cout << "Podaj co chcesz wstawic" << endl;
                                        cin >> value;
                                        cout << endl;
                                        LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                        performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                        heap->addNode(value);
                                        performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                        double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                        cout << endl << "Time:" <<tm <<endl;
                                    }break;
                                case 4:
                                    {
                                        cout << "Podaj czego szukasz" << endl;
                                        cin >> value;
                                        cout << endl;
                                        LARGE_INTEGER performanceCountStart,performanceCountEnd;
                                        performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
                                        heap->searchHeap(value);
                                        performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
                                        double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
                                        cout << endl << "Time:" <<tm <<endl;
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
                                        }break;

                                }
                            }while(choice != 7);
                        }break;
                    case 4:
                        {
                            int value;
                            RBT *rbt = new RBT();
                            do
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
                                        cout << "Podaj plik" << endl;
                                        cin >> filename;
                                        cout << endl;
                                        rbt->loadFromFile(filename);
                                    }break;
                                case 2:
                                    {
                                        cout << "Podaj element do usuniecia" << endl;
                                        cin >> value;
                                        cout << endl;
                                        rbt->removeNode(value);
                                    }break;
                                case 3:
                                    {
                                        cout << "Podaj wartosc elementu" << endl;
                                        cin >> value;
                                        cout << endl;
                                        rbt->addNode(value);
                                    }break;
                                case 4:
                                    {
                                        cout << "Podaj element do znalezienia" << endl;
                                        cin >> value;
                                        cout << endl;
                                        rbt->checkElement(value);
                                    }break;
                                case 5:
                                    {
                                        rbt->show("   ", "", rbt->root);
                                    }break;
                                case 6:
                                    {
                                        rbt->~RBT();
                                        rbt = new RBT();
                                    }
                                case 7:
                                    {
                                        delete rbt;
                                    }break;
                                }
                            }while(choice != 7);
                        }break;

            }
        }while(choice < 5);

    return 0;
}
