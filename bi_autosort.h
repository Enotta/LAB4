#include <string>
#include "element.h"

using namespace std;

#pragma once

class bi_autosort
{
private:
	element_k_bi* head;
	element_k_bi* tail;

public:
	bi_autosort();
	~bi_autosort();

	void add(int _key, int _value);
	void pop(int _value);

	element_k_bi* find(int _value);
	int count(int _value);

	void prints();
	void printf();

	static void display();
};