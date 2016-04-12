#ifndef EDGE_H
#define EDGE_H


class Edge
{
    public:
        int bt, et, weight;
        Edge();
        virtual ~Edge();
        bool operator () (const Edge &e1, const Edge &e2);

};

#endif // EDGE_H
