#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

tree::tree() : root(nullptr) {};
tree::~tree()
{
    deleteH(root);
    root = nullptr;
}

void tree::deleteH(node* nd)
{
    if (nd != nullptr) {
        deleteH(nd->left);
        deleteH(nd->right);
        delete nd;
    }
}

node* tree::insertHelper(node* nd, int value) {
    if (nd == nullptr) {
        nd = new node;
        nd->data = value;
        nd->left = nullptr;
        nd->right = nullptr;
    }
    else if (value < nd->data) {
        nd->left = insertHelper(nd->left, value);
    }
    else {
        nd->right = insertHelper(nd->right, value);
    }
    return nd;
}

node* tree::removeHelper(node* nd, int value) {
    if (nd == nullptr) {
        return nullptr;
    }
    else if (value < nd->data) {
        nd->left = removeHelper(nd->left, value);
    }
    else if (value > nd->data) {
        nd->right = removeHelper(nd->right, value);
    }
    else {
        if (nd->left == nullptr && nd->right == nullptr) {
            delete nd;
            nd = nullptr;
        }
        else if (nd->left == nullptr) {
            node* temp = nd;
            nd = nd->right;
            delete temp;
        }
        else if (nd->right == NULL) {
            node* temp = nd;
            nd = nd->left;
            delete temp;
        }
        else {
            node* temp = findMin(nd->right);
            nd->data = temp->data;
            nd->right = removeHelper(nd->right, temp->data);
        }
    }
    return nd;
}

node* tree::findMin(node* nd) {
    while (nd->left != nullptr) {
        nd = nd->left;
    }
    return nd;
}

void tree::printaHelper(node* nd) {
    if (nd != nullptr) {
        printaHelper(nd->left);
        cout << nd->data << " ";
        printaHelper(nd->right);
    }
}

void tree::printdHelper(node* nd) {
    if (nd != nullptr) {
        printdHelper(nd->right);
        cout << nd->data << " ";
        printdHelper(nd->left);
    }
}

void tree::insert(int _value) {
    root = insertHelper(root, _value);
}

void tree::remove(int _value) {
    root = removeHelper(root, _value);
}

node* tree::find(int _value) {
    return findHelper(root, _value);
}

node* tree::findHelper(node* nd, int value) {
    if (nd == nullptr) {
        return nd;
    }
    else if (nd->data == value) {
        return nd;
    }
    else if (value < nd->data) {
        return findHelper(nd->left, value);
    }
    else {
        return findHelper(nd->right, value);
    }
}

void tree::printa() {
    printaHelper(root);
}

void tree::printd() {
    printdHelper(root);
}

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

    cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §ß§Ñ§Û§ä§Ú (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §á§à§Ú§ã§Ü§Ñ) ";
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

        cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §ß§Ñ§Û§ä§Ú (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §á§à§Ú§ã§Ü§Ñ) ";
        cin >> value;
    }

    cout << "§±§à §Ó§à§Ù§â§Ñ§ã§ä§Ñ§ß§Ú§ð: ";
    bst->printa();
    cout << endl;

    delete bst;
}