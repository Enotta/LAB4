#include "fifo.h"
#include <iostream>

using namespace std;

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â§í §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ
element::element(int value): value(value), next(nullptr) {};
element::element(int value, element* next): value(value), next(next) {};

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â §Ú §Õ§Ö§ã§ä§â§å§Ü§ä§à§â fifo-§ã§á§Ú§ã§Ü§Ñ
fifo::fifo(): head(nullptr), tail(nullptr) {};
fifo::~fifo()
{
	element* currentHead = head;
	while (currentHead != tail)
	{
		element* temp = currentHead;
		currentHead = currentHead->next;

		delete temp;
	}

	delete tail;

	cout << "OK" << endl;
}

/// <summary>
/// §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §ã§á§Ú§ã§à§Ü
/// </summary>
/// <param name="_value"></param>
void fifo::add(int _value)
{
	element* newElem = new element(_value);

	if (head == nullptr)
	{
		head = newElem;
	}
	else
	{
		tail->next = newElem;
	}

	tail = newElem;
}

/// <summary>
/// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ú§Ù §ã§á§Ú§ã§Ü§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
void fifo::pop(int _value)
{
	element* currentHead = head;
	while (currentHead != 0)
	{
		if (currentHead->next->value == _value)
		{
			element* temp = currentHead->next;
			currentHead->next = currentHead->next->next;
			
			delete temp;

			break;
		}

		currentHead = currentHead->next;
	}
}

/// <summary>
/// §¯§Ñ§ç§à§Ø§Õ§Ö§ß§Ú§Ö §á§Ö§â§Ó§à§Ô§à §Ó§ç§à§Ø§Õ§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
element* fifo::find(int _value)
{
	element* current = head;
	while (current != tail)
	{
		if (current->value == _value)
		{
			return current;
		}

		current = current->next;
	}

	return nullptr;
}

/// <summary>
/// §±§à§Õ§ã§é§×§ä §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§Ñ §ï§Ý§Ö§Þ§Ö§ß§ä§à§Ó §Ù§Ñ§Õ§Ñ§ß§ß§à§Ô§à §Ù§ß§Ñ§é§Ö§ß§Ú§ñ
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
int fifo::count(int _value)
{
	int count = 0;

	element* current = head;
	while (current != tail)
	{
		if (current->value == _value)
		{
			count++;
		}

		current = current->next;
	}

	return count;
}

/// <summary>
/// §£§í§Ó§à§Õ §ã§á§Ú§ã§Ü§Ñ §ã §ß§Ñ§é§Ñ§Ý§Ñ §Ú §Õ§à §Ü§à§ß§è§Ñ
/// </summary>
void fifo::prints()
{
	element* currentHead = head;

	while (currentHead != tail)
	{
		cout << currentHead->value;
		currentHead = currentHead->next;
	}

	cout << currentHead->value << endl;
}

/// <summary>
/// §£§í§Ó§à§Õ §ã §Ü§à§ß§è§Ñ §Ú §Õ§à §ß§Ñ§é§Ñ§Ý§Ñ (§â§Ö§Ü§å§â§ã§Ú§Ó§ß§à)
/// </summary>
/// <param name="current"></param>
void fifo::printf(element* current = nullptr)
{
	if (current == nullptr)
	{
		current = head;
	}

	if (current != tail)
	{
		printf(current->next);
	}

	if (current != head)
	{
		cout << current->value;
	}
	else
	{
		cout << current->value << endl;
	}
}