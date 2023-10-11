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

    cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
    cin >> value;
    while (value != 0)
    {
        bst->insert(value);

        cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
        cin >> value;
    }

    cout << "���� �ӧ�٧�ѧ��ѧߧڧ�: ";
    bst->printa();
    cout << endl;

    cout << "���� ��ҧ�ӧѧߧڧ�: ";
    bst->printd();
    cout << endl;

    cout << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� �ߧѧۧ�� (0 - ���֧ܧ�ѧ�֧ߧڧ� ���ڧ�ܧ�) ";
    cin >> value;
    while (value != 0)
    {
        cout << bst->find(value) << endl;

        cout << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� �ߧѧۧ�� (0 - ���֧ܧ�ѧ�֧ߧڧ� ���ڧ�ܧ�) ";
        cin >> value;
    }
    
    cout << endl << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� ��էѧݧڧ�� (0 - ���֧ܧ�ѧ�֧ߧڧ� ��էѧݧ֧ߧڧ�) ";
    cin >> value;
    while (value != 0)
    {
        bst->remove(value);

        cout << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� �ߧѧۧ�� (0 - ���֧ܧ�ѧ�֧ߧڧ� ���ڧ�ܧ�) ";
        cin >> value;
    }

    cout << "���� �ӧ�٧�ѧ��ѧߧڧ�: ";
    bst->printa();
    cout << endl;

    delete bst;
}