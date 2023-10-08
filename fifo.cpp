#include "fifo.h"
#include <iostream>

using namespace std;

element::element(int value): value(value), next(nullptr) {};
element::element(int vakue, element* next): value(value), next(next) {};

fifo::fifo(): head(nullptr), tail(nullptr) {};
fifo::~fifo()
{
	while (head->next != nullptr)
	{
		element* temp = head;
		head = head->next;

		delete temp;
	}
}

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

void fifo::pop(int _value)
{
	element* currentHead = head;
	while (currentHead->next != nullptr)
	{
		if (currentHead->next->value = _value)
		{
			element* temp = currentHead->next;
			currentHead->next = currentHead->next->next;

			delete temp;
		}
		currentHead = currentHead->next;
	}
}

void fifo::prints()
{
	element* currentHead = head;

	while (currentHead->next != nullptr)
	{
		cout << currentHead->value;
		currentHead = currentHead->next;
	}
}