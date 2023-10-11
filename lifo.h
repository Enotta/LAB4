#include <string>
#include "element.h"

using namespace std;

#pragma once

class lifo
{
private:
	element* head; // §¤§à§Ý§à§Ó§Ñ - §á§Ö§â§Ó§í§Û §ï§Ý§Ö§Þ§Ö§ß§ä
	element* tail; // §·§Ó§à§ã§ä -  §á§à§ã§Ý§Ö§Õ§ß§Ú§Û §ï§Ý§Ö§Þ§Ö§ß§ä

public:
	lifo();
	~lifo();

	void add(int _value);
	void pop(int _value);

	element* find(int _value);
	int count(int _value);

	void prints();
	void printf(element* current);

	static void display();
};