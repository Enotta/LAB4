#include <string>
#include "element.h"

using namespace std;

#pragma once

class bi_autosort
{
private:
	element_k* head;
	element_k* tail;

public:
	bi_autosort();
	~bi_autosort();

	void add(int _key, int _value);
	void pop(int _value);

	element_k* find(int _value);
	int count(int _value);

	void prints();
	void printf(element_k* current);

	static void display();
};