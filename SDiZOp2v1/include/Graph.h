#ifndef GRAPH_H
#define GRAPH_H
#include <ListElement.h>
#include <Edge.h>

class Graph
{
    public:
        Edge *E, *RE;
        int **incidenceMatrix, **undirectedGraphM;
        ListElement **neighbourList, **undirectedGraphL;
        Graph();
        Graph(int t, int m);
        virtual ~Graph();
        void undirectedGraph();
        void randomEdges();
        void randomGraph();
        int getTops();
        int getEdges();
        bool isConnected();
        void DFSMatrix(int t);
        void DFSList(int t);
        void DijkstraList(int t);
        void DijkstraMatrix(int t);
        void PrimList();
        void PrimMatrix();
        void show();

    protected:

    private:
        int tops, egdes, density, reversedEdges;
        ListElement *elem1, *elem2;
};

#endif // GRAPH_H
