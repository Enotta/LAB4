#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

// ����ߧ����ܧ��� �� �է֧����ܧ��� �է֧�֧ӧ�
tree::tree() : root(nullptr) {};
tree::~tree()
{
    deleteH(root);
    root = nullptr;
}

// ����ާ��ߧڧ� �է֧����ܧ���� �էݧ� ��ҧ�ѧ�֧ߧڧ� �� �ܧ�ߧܧ��ߧ�ާ� ��٧ݧ�
void tree::deleteH(node* nd)
{
    if (nd != nullptr) 
    {
        deleteH(nd->left);
        deleteH(nd->right);
        delete nd;
    }
}

// ����ާ��ߧڧ� �է�ҧѧӧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �էݧ� ��ҧ�ѧ�֧ߧڧ� �� �ܧ�ߧܧ�֧�ߧ�ާ� ��ݧ֧ާ֧ߧ��
node* tree::insertH(node* nd, int _value)
{
    if (nd == nullptr) // ����ݧ� �����
    {
        nd = new node;
        nd->data = _value;
        nd->left = nullptr;
        nd->right = nullptr;
    }
    else if (_value < nd->data) // ������ڧ��ӧܧ� �ҧ�ݧ���/�ާ֧ߧ���
    {
        nd->left = insertH(nd->left, _value);
    }
    else // ������ڧ��ӧܧ� ...
    {
        nd->right = insertH(nd->right, _value);
    }
    return nd;
}

// �����ߧڧ� ��էѧݧ֧ߧڧ� �� ��ҧ�ѧ�֧ߧڧ֧� �� �ܧ�ߧܧ�֧�ߧ�ާ� ��ݧ֧ާ֧ߧ�� (��֧ܧ���ڧӧߧ�)
node* tree::removeH(node* nd, int _value)
{
    if (nd == nullptr)
    {
        return nullptr;
    }
    else if (_value < nd->data) // ������ �ӧݧ֧ӧ� �էݧ� ���ڧ�ܧ� �ߧ�اߧ�ԧ� ��ݧ֧ާ֧ߧ��
    {
        nd->left = removeH(nd->left, _value);
    }
    else if (_value > nd->data) // ������ �ӧ��ѧӧ� �էݧ� ���ڧ�ܧ� �ߧ�اߧ�ԧ� ��ݧ֧ާ֧ߧ��
    {
        nd->right = removeH(nd->right, _value);
    }
    else
    {
        if (nd->left == nullptr && nd->right == nullptr) // ����ݧ� �ߧ֧� �ݧڧ���֧�
        {
            delete nd;
            nd = nullptr;
        }
        else if (nd->left == nullptr) // ����ѧӧ�� �ݧڧ��
        {
            node* temp = nd;
            nd = nd->right;
            delete temp;
        }
        else if (nd->right == nullptr) // ���֧ӧ�� �ݧڧ��
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

// ����ާ��ߧڧ� ���ڧ�ܧ� �� �ߧѧ��ا�է֧ߧڧ�� �ާڧ�. ��ݧ֧ާ֧ߧ��
node* tree::findMin(node* nd)
{
    while (nd->left != nullptr)
    {
        nd = nd->left;
    }
    return nd;
}

//����ާ��ߧڧ� �� �է�ҧѧӧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� ��֧�֧� ��ҧ�ѧ�֧ߧڧ� �� �ܧ�ߧܧ�֧�ߧ�ާ� ��٧ݧ� (��֧ܧ���ڧӧߧ�)
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

// ����ާ��ߧڧ� �ӧ�ӧ�է� �� ��ҧ�ѧ�֧ߧڧ֧� �� �ܧ�ߧܧ�֧�ߧ�ާ� ��٧ݧ� (��֧ܧ���ڧӧߧ�)
void tree::printaH(node* nd)
{
    if (nd != nullptr) 
    {
        printaH(nd->left);
        cout << nd->data << " ";
        printaH(nd->right);
    }
}

// ����ާ��ߧڧ� �ӧ�ӧ�է� �� ��ҧ�ѧ�֧ߧڧ֧� �� �ܧ�ߧܧ�֧�ߧ�ާ� ��٧ݧ� (��֧ܧ���ڧӧߧ�)
void tree::printdH(node* nd)
{
    if (nd != nullptr)
    {
        printdH(nd->right);
        cout << nd->data << " ";
        printdH(nd->left);
    }
}

// ����ҧѧӧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �� �է֧�֧ӧ�
void tree::insert(int _value)
{
    root = insertH(root, _value);
}

// ���էѧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �ڧ� �է֧�֧ӧ�
void tree::remove(int _value) 
{
    root = removeH(root, _value);
}

// ���ѧ��اէ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �� �է֧�֧ӧ�
node* tree::find(int _value)
{
    return findH(root, _value);
}

// ����ӧ�� ��� �ӧ�٧�ѧ��ѧߧڧ�
void tree::printa() {
    printaH(root);
}

// ����ӧ�� ��� ��ҧ�ӧѧߧڧ�
void tree::printd() {
    printdH(root);
}

// ���֧ާ�ԧ���ѧ�ڧ� ��ѧҧ���
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

    cout << endl << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� �ߧѧۧ�� (0 - ���֧ܧ�ѧ�֧ߧڧ� ���ڧ�ܧ�) ";
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

        cout << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� ��էѧݧڧ�� (0 - ���֧ܧ�ѧ�֧ߧڧ� ���ڧ�ܧ�) ";
        cin >> value;
    }

    cout << "���� �ӧ�٧�ѧ��ѧߧڧ�: ";
    bst->printa();
    cout << endl;

    cout << "���� ��ҧ�ӧѧߧڧ�: ";
    bst->printd();
    cout << endl;

    system("pause");

    delete bst;
}