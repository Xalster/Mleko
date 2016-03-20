#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
    //ctor
  S.color = 'B';          // Inicjujemy strażnika
  S.up    = &S;
  S.left  = &S;
  S.right = &S;
  root    = &S;           // Korzeń wskazuje strażnika
}

RedBlackTree::~RedBlackTree()
{
    //dtor
    removeTree(root);
}

void RedBlackTree::removeTree(RBTNode * p) // Usuwa rekurencyjnie drzewo
{
    if(p != &S)
    {
        removeTree(p->left);   // usuwamy lewe poddrzewo
        removeTree(p->right);  // usuwamy prawe poddrzewo
        delete p;              // usuwamy sam węzeł
    }
}

void RedBlackTree::print()          // Wypisuje drzewo
{

}

RBTNode* RedBlackTree::findNode(int k) // Wyszukuje wêze³ o kluczu k
{
    RBTNode * p;

    p = root;
    while((p != &S) && (p->key != k))
    {
        if(k < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
        if(p == &S)
        {
            return NULL;
        }
    }
    return p;
}

RBTNode* RedBlackTree::minRBT(RBTNode * p)
{
    if(p != &S)
    {
        while(p->left != &S)
        {
            p = p->left;
        }
    }

    return p;
}

RBTNode* RedBlackTree::succRBT(RBTNode * p)// Wyszukuje następnik p
{
    RBTNode * r;

    if(p != &S)
    {
        if(p->right != &S)
        {
            return minRBT(p->right);
        }
        else
        {
        r = p->up;
        while((r != &S) && (p == r->right))
        {
            p = r;
            r = r->up;
        }
        return r;
        }
    }
  return &S;
}

void RedBlackTree::rotateL(RBTNode * A) // Rotacja w lewo wzglêdem A
{
    RBTNode * B, * p;

    B = A->right;
    if(B != &S)
    {
        p = A->up;
        A->right = B->left;
        if(A->right != &S)
        {
            A->right->up = A;
        }
        B->left = A;
        B->up = p;
        A->up = B;

        if(p != &S)
        {
            if(p->left == A)
            {
                p->left = B;
            }
            else
            {
                p->right = B;
            }
        }
    else
    {
        root = B;
    }
  }
}

void RedBlackTree::rotateR(RBTNode * A) // Rotacja w prawo wzglêdem A
{
    RBTNode * B, * p;

    B = A->left;
    if(B != &S)
    {
        p = A->up;
        A->left = B->right;
    if(A->left != &S)
    {
        A->left->up = A;
    }
    B->right = A;
    B->up = p;
    A->up = B;

    if(p != &S)
    {
        if(p->left == A)
        {
            p->left = B;
        }
        else
        {
            p->right = B;
        }
    }
    else
    {
        root = B;
    }
  }
}

void RedBlackTree::insertNode(int k)   // Wstawia wêze³ o kluczu k
{
    RBTNode * X, * Y;

    X = new RBTNode;        // Tworzymy nowy węzeł
    X->left  = &S;          // Inicjujemy pola
    X->right = &S;
    X->up    = root;
    X ->key   = k;
    if(X->up == &S)
    {
        root = X; // X staje się korzeniem
    }
    else
    while(true)             // Szukamy liścia do zastąpienia przez X
    {
        if(k < X->up->key)
    {
    if(X->up->left == &S)
    {
        X->up->left = X;  // X zastępuje lewy liść
        break;
    }
        X->up = X->up->left;
    }
    else
    {
      if(X->up->right == &S)
      {
        X->up->right = X; // X zastępuje prawy liść
        break;
      }
    X->up = X->up->right;
    }
}
    X->color = 'R';         // Węzeł kolorujemy na czerwono
    while((X != root) && (X->up->color == 'R'))
    {
        if(X->up == X->up->up->left)
    {
        Y = X->up->up->right; // Y -> wujek X

    if(Y->color == 'R')  // Przypadek 1
    {
        X->up->color = 'B';
        Y->color = 'B';
        X->up->up->color = 'R';
        X = X->up->up;
        continue;
    }

    if(X == X->up->right) // Przypadek 2
    {
        X = X->up;
        rotateL(X);
    }

    X->up->color = 'B'; // Przypadek 3
    X->up->up->color = 'R';
    rotateR(X->up->up);
    break;
    }
    else
    {                  // Przypadki lustrzane
        Y = X->up->up->left;

        if(Y->color == 'R') // Przypadek 1
      {
        X->up->color = 'B';
        Y->color = 'B';
        X->up->up->color = 'R';
        X = X->up->up;
        continue;
      }

      if(X == X->up->left) // Przypadek 2
      {
        X = X->up;
        rotateR(X);
      }

      X->up->color = 'B'; // Przypadek 3
      X->up->up->color = 'R';
      rotateL(X->up->up);
      break;
    }
  }
  root->color = 'B';
}

void RedBlackTree::removeNode(RBTNode * X) // Usuwa wêze³ X
{
    RBTNode * W, * Y, * Z;

  if((X->left == &S) || (X->right == &S)) Y = X;
  else                                    Y = succRBT(X);

  if(Y->left != &S) Z = Y->left;
  else              Z = Y->right;

  Z->up = Y->up;

  if(Y->up == &S) root = Z;
  else if(Y == Y->up->left) Y->up->left  = Z;
  else                      Y->up->right = Z;

  if(Y != X) X->key = Y->key;

  if(Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
    while((Z != root) && (Z->color == 'B'))
      if(Z == Z->up->left)
      {
        W = Z->up->right;

        if(W->color == 'R')
        {              // Przypadek 1
          W->color = 'B';
          Z->up->color = 'R';
          rotateL(Z->up);
          W = Z->up->right;
        }

        if((W->left->color == 'B') && (W->right->color == 'B'))
        {              // Przypadek 2
          W->color = 'R';
          Z = Z->up;
          continue;
        }

        if(W->right->color == 'B')
        {              // Przypadek 3
          W->left->color = 'B';
          W->color = 'R';
          rotateR(W);
          W = Z->up->right;
        }

        W->color = Z->up->color; // Przypadek 4
        Z->up->color = 'B';
        W->right->color = 'B';
        rotateL(Z->up);
        Z = root;         // To spowoduje zakończenie pętli
      }
      else
      {                // Przypadki lustrzane
        W = Z->up->left;

        if(W->color == 'R')
        {              // Przypadek 1
          W->color = 'B';
          Z->up->color = 'R';
          rotateR(Z->up);
          W = Z->up->left;
        }

        if((W->left->color == 'B') && (W->right->color == 'B'))
        {              // Przypadek 2
          W->color = 'R';
          Z = Z->up;
          continue;
        }

        if(W->left->color == 'B')
        {              // Przypadek 3
          W->right->color = 'B';
          W->color = 'R';
          rotateL(W);
          W = Z->up->left;
        }

        W->color = Z->up->color;  // Przypadek 4
        Z->up->color = 'B';
        W->left->color = 'B';
        rotateR(Z->up);
        Z = root;         // To spowoduje zakończenie pętli
      }

  Z->color = 'B';

  delete Y;
}
