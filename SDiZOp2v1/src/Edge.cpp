#include "Edge.h"

Edge::Edge()
{
    //ctor
}

Edge::~Edge()
{
    //dtor
}

bool Edge::operator()(const Edge &e1, const Edge &e2)
{
    if(e1.weight > e2.weight)
    {
        return true;
    }
    if(e1.weight < e2.weight)
    {
        return false;
    }
}
