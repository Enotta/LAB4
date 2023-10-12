#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â §Ú §Õ§Ö§ã§ä§â§å§Ü§ä§à§â §Õ§Ö§â§Ö§Ó§Ñ
tree::tree() : root(nullptr) {};
tree::~tree()
{
    deleteH(root);
    root = nullptr;
}

// §±§à§Þ§à§ë§ß§Ú§Ü §Õ§Ö§ã§ä§â§å§Ü§ä§à§â§Ñ §Õ§Ý§ñ §à§Ò§â§Ñ§ë§Ö§ß§Ú§ñ §Ü §Ü§à§ß§Ü§â§ä§ß§à§Þ§å §å§Ù§Ý§å
void tree::deleteH(node* nd)
{
    if (nd != nullptr) 
    {
        deleteH(nd->left);
        deleteH(nd->right);
        delete nd;
    }
}

// §±§à§Þ§à§ë§ß§Ú§Ü §Õ§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Õ§Ý§ñ §à§Ò§â§Ñ§ë§Ö§ß§Ú§ñ §Ü §Ü§à§ß§Ü§â§Ö§ä§ß§à§Þ§å §ï§Ý§Ö§Þ§Ö§ß§ä§å
node* tree::insertH(node* nd, int _value)
{
    if (nd == nullptr) // §¦§ã§Ý§Ú §á§å§ã§ä
    {
        nd = new node;
        nd->data = _value;
        nd->left = nullptr;
        nd->right = nullptr;
    }
    else if (_value < nd->data) // §³§à§â§ä§Ú§â§à§Ó§Ü§Ñ §Ò§à§Ý§î§ê§Ö/§Þ§Ö§ß§î§ê§Ö
    {
        nd->left = insertH(nd->left, _value);
    }
    else // §³§à§â§ä§Ú§â§à§Ó§Ü§Ñ ...
    {
        nd->right = insertH(nd->right, _value);
    }
    return nd;
}

// §±§à§ë§ß§Ú§Ü §å§Õ§Ñ§Ý§Ö§ß§Ú§ñ §ã §à§Ò§â§Ñ§ë§Ö§ß§Ú§Ö§Þ §Ü §Ü§à§ß§Ü§â§Ö§ä§ß§à§Þ§å §ï§Ý§Ö§Þ§Ö§ß§ä§å (§â§Ö§Ü§å§â§ã§Ú§Ó§ß§à)
node* tree::removeH(node* nd, int _value)
{
    if (nd == nullptr)
    {
        return nullptr;
    }
    else if (_value < nd->data) // §µ§ç§à§Õ §Ó§Ý§Ö§Ó§à §Õ§Ý§ñ §á§à§Ú§ã§Ü§Ñ §ß§å§Ø§ß§à§Ô§à §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ
    {
        nd->left = removeH(nd->left, _value);
    }
    else if (_value > nd->data) // §µ§ç§à§Õ §Ó§á§â§Ñ§Ó§à §Õ§Ý§ñ §á§à§Ú§ã§Ü§Ñ §ß§å§Ø§ß§à§Ô§à §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ
    {
        nd->right = removeH(nd->right, _value);
    }
    else
    {
        if (nd->left == nullptr && nd->right == nullptr) // §¦§ã§Ý§Ú §ß§Ö§ä §Ý§Ú§ã§ä§î§Ö§Ó
        {
            delete nd;
            nd = nullptr;
        }
        else if (nd->left == nullptr) // §±§â§Ñ§Ó§í§Û §Ý§Ú§ã§ä
        {
            node* temp = nd;
            nd = nd->right;
            delete temp;
        }
        else if (nd->right == nullptr) // §­§Ö§Ó§í§Û §Ý§Ú§ã§ä
        {
            node* temp = nd;
            nd = nd->left;
            delete temp;
        }
        else
        {
            node* temp = findMin(nd->right);
            nd->data = temp->data;
            nd->right = removeH(nd->right, temp->data);
        }
    }
    return nd;
}

// §±§à§Þ§à§ë§ß§Ú§Ü §á§à§Ú§ã§Ü§Ñ §ã §ß§Ñ§ç§à§Ø§ë§Õ§Ö§ß§Ú§ñ§Þ §Þ§Ú§ß. §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ
node* tree::findMin(node* nd)
{
    while (nd->left != nullptr)
    {
        nd = nd->left;
    }
    return nd;
}

//§±§à§Þ§à§ë§ß§Ú§Ü §Ó §Õ§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ú §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §é§Ö§â§Ö§Ù §à§Ò§â§Ñ§ë§Ö§ß§Ú§Ö §Ü §Ü§à§ß§Ü§â§Ö§ä§ß§à§Þ§å §å§Ù§Ý§å (§â§Ö§Ü§å§â§ã§Ú§Ó§ß§à)
node* tree::findH(node* nd, int _value)
{
    if (nd == nullptr)
    {
        return nd;
    }
    else if (nd->data == _value)
    {
        return nd;
    }
    else if (_value < nd->data)
    {
        return findH(nd->left, _value);
    }
    else
    {
        return findH(nd->right, _value);
    }
}

// §±§à§Þ§à§ë§ß§Ú§Ü §Ó§í§Ó§à§Õ§Ñ §ã §à§Ò§â§Ñ§ë§Ö§ß§Ú§Ö§Þ §Ü §Ü§à§ß§Ü§â§Ö§ä§ß§à§Þ§å §å§Ù§Ý§å (§â§Ö§Ü§å§â§ã§Ú§Ó§ß§à)
void tree::printaH(node* nd)
{
    if (nd != nullptr) 
    {
        printaH(nd->left);
        cout << nd->data << " ";
        printaH(nd->right);
    }
}

// §±§à§Þ§à§ë§ß§Ú§Ü §Ó§í§Ó§à§Õ§Ñ §ã §à§Ò§â§Ñ§ë§Ö§ß§Ú§Ö§Þ §Ü §Ü§à§ß§Ü§â§Ö§ä§ß§à§Þ§å §å§Ù§Ý§å (§â§Ö§Ü§å§â§ã§Ú§Ó§ß§à)
void tree::printdH(node* nd)
{
    if (nd != nullptr)
    {
        printdH(nd->right);
        cout << nd->data << " ";
        printdH(nd->left);
    }
}

// §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §Õ§Ö§â§Ö§Ó§à
void tree::insert(int _value)
{
    root = insertH(root, _value);
}

// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ú§Ù §Õ§Ö§â§Ö§Ó§Ñ
void tree::remove(int _value) 
{
    root = removeH(root, _value);
}

// §¯§Ñ§ç§à§Ø§Õ§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §Õ§Ö§â§Ö§Ó§Ö
node* tree::find(int _value)
{
    return findH(root, _value);
}

// §£§í§Ó§à§Õ §á§à §Ó§à§Ù§â§Ñ§ã§ä§Ñ§ß§Ú§ð
void tree::printa() {
    printaH(root);
}

// §£§í§Ó§à§Õ §á§à §å§Ò§í§Ó§Ñ§ß§Ú§ð
void tree::printd() {
    printdH(root);
}

// §¥§Ö§Þ§à§Ô§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í
void tree::display()
{
    int value;
    tree* bst = new tree;

    cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
    cin >> value;
    while (value != 0)
    {
        bst->insert(value);

        cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
        cin >> value;
    }

    cout << "§±§à §Ó§à§Ù§â§Ñ§ã§ä§Ñ§ß§Ú§ð: ";
    bst->printa();
    cout << endl;

    cout << "§±§à §å§Ò§í§Ó§Ñ§ß§Ú§ð: ";
    bst->printd();
    cout << endl;

    cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §ß§Ñ§Û§ä§Ú (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §á§à§Ú§ã§Ü§Ñ) ";
    cin >> value;
    while (value != 0)
    {
        cout << bst->find(value) << endl;

        cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §ß§Ñ§Û§ä§Ú (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §á§à§Ú§ã§Ü§Ñ) ";
        cin >> value;
    }
    
    cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §å§Õ§Ñ§Ý§Ú§ä§î (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §å§Õ§Ñ§Ý§Ö§ß§Ú§ñ) ";
    cin >> value;
    while (value != 0)
    {
        bst->remove(value);

        cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §å§Õ§Ñ§Ý§Ú§ä§î (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §á§à§Ú§ã§Ü§Ñ) ";
        cin >> value;
    }

    cout << "§±§à §Ó§à§Ù§â§Ñ§ã§ä§Ñ§ß§Ú§ð: ";
    bst->printa();
    cout << endl;

    cout << "§±§à §å§Ò§í§Ó§Ñ§ß§Ú§ð: ";
    bst->printd();
    cout << endl;

    system("pause");

    delete bst;
}