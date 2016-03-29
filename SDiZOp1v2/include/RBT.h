#ifndef RBT_H
#define RBT_H
#include <string>
#include <iostream>

using namespace std;

class RBTNode
{
public:
    RBTNode *parent, *leftchild, *rightchild;
    int key;
    char color;
};
class RBT
{
private:
    RBTNode warden;
    string cr, cp, cl;
    char black;
    char red;
public:
    RBTNode *root;
    int rbtsize;
    RBT();
    virtual ~RBT();
    void loadFromFile(string filename);
    void deleteTree(RBTNode *node);
    void rotateLeft(RBTNode *node);
    void rotateRight(RBTNode *node);
    void show(string sp, string sn, RBTNode *node);
    void addNode(int key);
    void removeNode(int key);
    bool checkElement(int key);
    RBTNode *searchRBT(int key);
};

#endif // RBT_H
