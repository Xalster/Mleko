#include "RBT.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

RBT::RBT()
{
    cp = cl = cr = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
    black = 'B';
    red = 'R';
    warden.parent = &warden;
    warden.leftchild = &warden;
    warden.rightchild = &warden;
    warden.color = black;
    root = &warden;
    rbtsize = 0;
}

RBT::~RBT()
{
    deleteTree(root);
    rbtsize = 0;
}

void RBT::loadFromFile(string filename)
{
    int tmp;
    filename = filename + ".txt";
    const char *filenamec = filename.c_str();
    fstream file;
    file.open(filenamec, ios_base::in);

    if(!file)
    {
        cout << "Nie ma takiego pliku" << endl;
    }
    else
    {
        file >> rbtsize;
        for(int i = 0; file >> tmp;i++)
        {
            addNode(tmp);
        }
    }
    rbtsize = rbtsize / 2;
    file.close();
}

void RBT::deleteTree(RBTNode *node)
{
    if(node != &warden)
    {
        deleteTree(node->leftchild);
        deleteTree(node->rightchild);
        delete node;
    }
}

void RBT::rotateLeft(RBTNode *node)
{
    RBTNode *rightchild, *parent;
    rightchild = node->rightchild;
    if(rightchild != &warden)
    {
        parent = node->parent;
        node->rightchild = rightchild->leftchild;
        if(node->rightchild != &warden)
        {
            node->rightchild->parent = node;
        }
        rightchild->leftchild = node;
        rightchild->parent = parent;
        node->parent = rightchild;
        if(parent != &warden)
        {
            if(parent->leftchild == node)
            {
                parent->leftchild = rightchild;
            }
            else
            {
                parent->rightchild = rightchild;
            }
        }
        else
        {
            root = rightchild;
        }
    }
}

void RBT::rotateRight(RBTNode *node)
{
    RBTNode *leftchild, *parent;
    leftchild = node->leftchild;
    if(leftchild != &warden)
    {
        parent = node->parent;
        node->leftchild = leftchild->rightchild;
        if(node->leftchild != &warden)
        {
            node->leftchild->parent = node;
        }
        leftchild->rightchild = node;
        leftchild->parent = parent;
        node->parent = leftchild;
        if(parent != &warden)
        {
            if(parent->leftchild == node)
            {
                parent->leftchild = leftchild;
            }
            else
            {
                parent->rightchild = leftchild;
            }
        }
        else
        {
            root = leftchild;
        }
    }
}

void RBT::show(string sp, string sn, RBTNode *node)
{
    if (rbtsize == 0)
    {
        cout << "Drzewo RBT jest puste" << endl;
    }
    if(node != &warden)
    {
        string s;
        s = sp;
        if(sn == cr)
        {
            s[s.length() - 2] = ' ';
        }
        show(s + cp, cr, node->rightchild);
        s = s.substr(0, sp.length() - 2);
        cout << sp << sn << node->color << ":" << node->key << endl;
        s = sp;
        if(sn == cl)
        {
            s[s.length() -2] = ' ';
        }
        show(s + cp, cl, node->leftchild);
    }
}

void RBT::addNode(int key)
{
    RBTNode *nelement, *uncle;
    nelement = new RBTNode;
    nelement->leftchild = &warden;
    nelement->rightchild = &warden;
    nelement->parent = root;
    nelement->key = key;
    if(nelement->parent == &warden)
    {
        root = nelement;
    }
    else
    {
        while(true)
        {
            if(key < nelement->parent->key)
            {
                if(nelement->parent->leftchild == &warden)
                {
                    nelement->parent->leftchild = nelement;
                    break;
                }
                nelement->parent = nelement->parent->leftchild;
            }
            if(key >= nelement->parent->key)
            {
                if(nelement->parent->rightchild == &warden)
                {
                    nelement->parent->rightchild = nelement;
                    break;
                }
                nelement->parent = nelement->parent->rightchild;
            }
        }
    }
        nelement->color = red;
        while((nelement != root) && (nelement->parent->color == red))
        {
            if(nelement->parent == nelement->parent->parent->leftchild)
            {
                uncle = nelement->parent->parent->rightchild;
                if(uncle->color == red)
                {
                    nelement->parent->color = black;
                    uncle->color = black;
                    nelement->parent->parent->color = red;
                    nelement = nelement->parent->parent;
                    continue;
                }
                if(nelement == nelement->parent->rightchild)
                {
                    nelement = nelement->parent;
                    rotateLeft(nelement);
                }
                nelement->parent->color = black;
                nelement->parent->parent->color = red;
                rotateRight(nelement->parent->parent);
                break;
            }
            else
            {
                uncle = nelement->parent->parent->leftchild;
                if(uncle->color == red)
                {
                    nelement->parent->color = black;
                    uncle->color = black;
                    nelement->parent->parent->color = red;
                    nelement = nelement->parent->parent;
                    continue;
                }
                if(nelement == nelement->parent->leftchild)
                {
                    nelement = nelement->parent;
                    rotateRight(nelement);
                }
                nelement->parent->color = black;
                nelement->parent->parent->color = red;
                rotateLeft(nelement->parent->parent);
                break;
            }
        }
        root->color = black;
        rbtsize++;
}

void RBT::removeNode(int key)
{
    if(!(checkElement(key)))
    {
        cout << "Brak elementu o podanym kluczu" << endl;
    }
    else if(rbtsize == 0)
    {
        cout << "RBT jest puste" << endl;
    }
    else
    {
        RBTNode *rnode, *uncle, *child;
        rnode = searchRBT(key);
        if((rnode->leftchild == &warden) || (rnode->rightchild == &warden))
        {

        }
        else
        {
            if(rnode != &warden)
            {
                if(rnode->rightchild != &warden)
                {
                    while(rnode->rightchild->leftchild != &warden)
                    {
                        rnode->rightchild = rnode->rightchild->leftchild;
                    }
                    rnode = rnode->rightchild;
                }
                else
                {
                    rnode = rnode->parent;
                    while((rnode != &warden) && (rnode == rnode->rightchild))
                    {
                        rnode = rnode;
                        rnode = rnode->parent;
                    }
                }
            }
            else
            {
                rnode = &warden;
            }
        }
        if(rnode->leftchild != &warden)
        {
            child = rnode->leftchild;
        }
        else
        {
            child = rnode->rightchild;
        }
        child->parent = rnode->parent;
        if(rnode->parent == &warden)
        {
            root = child;
        }
        else if(rnode == rnode->parent->leftchild)
        {
            rnode->parent->rightchild = child;
        }
        else
        {
            rnode->parent->rightchild = child;
        }
        if(rnode != rnode)
        {
            rnode->key = rnode->key;
        }
        if(rnode->color == black)
        {
            while((child != root) && (child->color == black))
            {
                if(child == child->parent->leftchild)
                {
                    uncle = child->parent->rightchild;
                    if(uncle->color == red)
                    {
                        uncle->color = black;
                        child->parent->color = red;
                        rotateLeft(child->parent);
                        uncle = child->parent->rightchild;
                    }
                    if((uncle->leftchild->color == black) && (uncle->rightchild->color == black))
                    {
                        uncle->color = red;
                        child = child->parent;
                        continue;
                    }
                    if(uncle->rightchild->color == black)
                    {
                        uncle->leftchild->color = black;
                        uncle->color =red;
                        rotateRight(uncle);
                        uncle = child->parent->rightchild;
                    }
                    uncle->color = child->parent->color;
                    child->parent->color = black;
                    uncle->rightchild->color = black;
                    rotateLeft(child->parent);
                    child = root;
                }
                else
                {
                    uncle = child->parent->leftchild;
                    if(uncle->color == red)
                    {
                        uncle->color = black;
                        child->parent->color = red;
                        rotateRight(child->parent);
                        uncle = child->parent->leftchild;
                    }
                    if((uncle->leftchild->color == black) && (uncle->rightchild->color == black))
                    {
                        uncle->color = red;
                        child = child->parent;
                        continue;
                    }
                    if(uncle->leftchild->color == black)
                    {
                        uncle->rightchild->color = black;
                        uncle->color = red;
                        rotateLeft(uncle);
                        uncle = child->parent->leftchild;
                    }
                    uncle->color = child->parent->color;
                    child->parent->color = black;
                    uncle->leftchild->color = black;
                    rotateRight(child->parent);
                    child = root;
                }
            }
            child->color = black;
            rbtsize--;
        }
    }
}

bool RBT::checkElement(int key)
{
    RBTNode *node;
    bool is = false;
    node = root;
    while((node != &warden) && (node->key != key))
    {
        if (key < node->key)
        {
            node = node->leftchild;
        }
        else
        {
            node = node->rightchild;
        }
    }
    if(node == &warden)
    {
        is = false;
    }
    else
    {
        is = true;
    }
    if(is)
    {
        cout << "Znaleziono element" << endl;
    }
    else
    {
        cout << "Brak elementu w drzewwie" << endl;
    }
    return is;
}

RBTNode *RBT:: searchRBT(int key)
{
    RBTNode *node;
    node = root;
    while((root != &warden) && (node->key != key))
    {
        if (key < node->key)
        {
            node = node->leftchild;
        }
        else
        {
            node = node->rightchild;
        }
    }
    if(node == &warden)
    {
        return NULL;
    }
    return node;
}
