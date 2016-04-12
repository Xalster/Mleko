#include "SpannignTree.h"
#include <iostream>

using namespace std;

SpannignTree::SpannignTree()
{

}

SpannignTree::SpannignTree(int tops, int ed)
{
    Tree = new ListElement *[tops];
    for(int i = 0;i < tops;i++)
    {
        Tree[i] = NULL;
    }
    treesize = tops - 1;
    weight = 0;
    edges = ed;
    ee = new Edge[edges];
    a = 0;
}

SpannignTree::~SpannignTree()
{
    ListElement *elem1, *elem2;
    for(int i = 0;i <= treesize;i++)
    {
        elem1 = Tree[i];
        while(elem1)
        {
            elem2 = elem1;
            elem1 = elem1->next;
            delete elem2;
        }
    }
    delete[] Tree;
}

void SpannignTree::addEdge(Edge e)
{
    ListElement *elem;
    weight += e.weight;
    elem = new ListElement;
    elem->t = e.weight;
    elem->next = Tree[e.bt];
    Tree[e.et] = elem;

    elem = new ListElement;
    elem->t = e.bt;
    elem->weight = e.weight;
    elem->next = Tree[e.et];
    Tree[e.et] = elem;

    ee[a] = e;
    a++;
}

void SpannignTree::show()
{
    cout << endl;
    for(int i = 0;i < a;i++)
    {
        cout << "Krawedz " << i + 1 << ": " << ee[i].bt << "<-->" << ee[i].et << " [" << ee[i].weight << "] " << endl;
    }
    cout << endl << "Waga minimalnego drzewa rozpinajacego = " << weight << endl;
}
