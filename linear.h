#include <string>
#include "element.h"

using namespace std;

#pragma once

class linear
{
private:
	element_k2_bi* head;
	element_k2_bi* tail;

public:
	linear();
	~linear();

	void add(int _key1, int _key2, int _value);
	void pop(int _value);

	element_k2_bi* find(int _value);
	int count(int _value);

	void prints();
	void printf();

	static void display();
};