#include <string>
#include "element.h"

using namespace std;

#pragma once

class autosort
{
private:
	element_k* head; // §¤§à§Ý§à§Ó§Ñ - §á§Ö§â§Ó§í§Û §ï§Ý§Ö§Þ§Ö§ß§ä
	element_k* tail; // §·§Ó§à§ã§ä -  §á§à§ã§Ý§Ö§Õ§ß§Ú§Û §ï§Ý§Ö§Þ§Ö§ß§ä

public:
	autosort();
	~autosort();

	void add(int _key, int _value);
	void pop(int _value);

	element_k* find(int _value);
	int count(int _value);

	void prints();
	void printf(element_k* current);

	static void display();
};