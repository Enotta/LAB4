#include <string>
#include "element.h"

using namespace std;

#pragma once

class bi_autosort
{
private:
	element_k_bi* head; // §¤§à§Ý§à§Ó§Ñ - §á§Ö§â§Ó§í§Û §ï§Ý§Ö§Þ§Ö§ß§ä
	element_k_bi* tail; // §·§Ó§à§ã§ä -  §á§à§ã§Ý§Ö§Õ§ß§Ú§Û §ï§Ý§Ö§Þ§Ö§ß§ä

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