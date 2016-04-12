#ifndef SPANNIGNTREE_H
#define SPANNIGNTREE_H
#include <ListElement.h>
#include <Edge.h>


class SpannignTree
{
    public:
        SpannignTree();
        SpannignTree(int tops, int edges);
        virtual ~SpannignTree();
        void addEdge(Edge e);
        void show();

    private:
        ListElement **Tree;
        Edge *ee;
        int treesize, weight, edges, a;
};

#endif // SPANNIGNTREE_H
