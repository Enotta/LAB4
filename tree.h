#include "element.h"

#pragma once

class tree
{
private:
	node* root; // �����֧ߧ� - ��֧�ӧ�� ��ݧ֧ާ֧ߧ�

	void deleteH(node* nd);

	node* insertH(node* nd, int _value);
	node* removeH(node* nd, int _value);

	node* findMin(node* nd);
	node* findH(node* nd, int _value);

	void printaH(node* nd);
	void printdH(node* nd);

public:
	tree();
	~tree();

	void insert(int _value);
	void remove(int _value);
	node* find(int _value);

	void printa();
	void printd();

	static void display();
};

