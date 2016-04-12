#ifndef LISTELEMENT_H
#define LISTELEMENT_H


class ListElement
{
    public:
        ListElement *next;
        int t, weight;
        ListElement();
        virtual ~ListElement();

};

#endif // LISTELEMENT_H
