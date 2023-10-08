#include <string>

using namespace std;

#pragma once

/// <summary>
/// §µ§ß§Ú§Ó§Ö§â§ã§Ñ§Ý§î§ß§í§Û §ï§Ý§Ö§Þ§Ö§ß§ä §Õ§Ý§ñ §Ý§ð§Ò§í§ç §ã§á§Ú§ã§Ü§à§Ó §Ý§Ñ§Ò§à§â§Ñ§ä§à§â§ß§à§Û §â§Ñ§Ò§à§ä§í
/// </summary>
struct element
{
	int value;
	element* next;

	element(int value);
	element(int value, element* next);
};

class fifo
{
private:
	element* head;
	element* tail;

public:
	fifo();
	~fifo();

	void add(int _value);
	void pop(int _value);

	element* find(int _value);
	int count(int _value);

	void prints();
	void printf(element* current);
};