#include "fifo.h"
#include <iostream>

using namespace std;

element::element(int value): value(value), next(nullptr) {};
element::element(int value, element* next): value(value), next(next) {};

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