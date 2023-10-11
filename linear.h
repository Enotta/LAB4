#include <string>
#include "element.h"

using namespace std;

#pragma once

class linear
{
private:
	element_k2_bi* head; // §¤§à§Ý§à§Ó§Ñ - §á§Ö§â§Ó§í§Û §ï§Ý§Ö§Þ§Ö§ß§ä
	element_k2_bi* tail; // §·§Ó§à§ã§ä -  §á§à§ã§Ý§Ö§Õ§ß§Ú§Û §ï§Ý§Ö§Þ§Ö§ß§ä

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