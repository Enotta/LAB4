#include "element.h"

#pragma once

class tree
{
private:
	node* root;

	void deleteH(node* nd);

	node* insertHelper(node* nd, int _value);
	node* removeHelper(node* nd, int _value);

	node* findMin(node* nd);
	node* findHelper(node* nd, int _value);

	void printaHelper(node* nd);
	void printdHelper(node* nd);

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

