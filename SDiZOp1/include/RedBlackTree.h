#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>

struct RBTNode
{
  RBTNode * up;
  RBTNode * left;
  RBTNode * right;
  int key;
  char color;
};

class RedBlackTree
{
     private:
    RBTNode S;
    RBTNode * root;
    void printRBT(RBTNode * p);

  public:
    RedBlackTree();
    virtual ~RedBlackTree();
    void removeTree(RBTNode* p); // Usuwa rekurencyjnie drzewo
    void print();          // Wypisuje drzewo
    RBTNode* findNode(int k); // Wyszukuje wêze³ o kluczu k
    RBTNode* succRBT(RBTNode* p);// Wyszukuje następnik p
    RBTNode* minRBT(RBTNode* p);
    void rotateL(RBTNode* A); // Rotacja w lewo wzglêdem A
    void rotateR(RBTNode* A); // Rotacja w prawo wzglêdem A
    void insertNode(int k);   // Wstawia wêze³ o kluczu k
    void removeNode(RBTNode* X); // Usuwa wêze³ X



};

#endif // REDBLACKTREE_H
