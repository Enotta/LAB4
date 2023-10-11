#include "fifo.h"
#include "element.h"
#include <iostream>

using namespace std;

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â §Ú §Õ§Ö§ã§ä§â§å§Ü§ä§à§â fifo-§ã§á§Ú§ã§Ü§Ñ
fifo::fifo(): head(nullptr), tail(nullptr) {};
fifo::~fifo()
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	// §±§â§à§ç§à§Õ §à§ä §á§Ö§â§Ó§à§Ô§à §Õ§à §á§à§ã§Ý§Ö§Õ§ß§Ö§Ô§à §Ú §å§Õ§Ñ§Ý§Ö§ß§Ú§Ö §é§Ö§â§Ö§Ù §Ó§â§Ö§Þ§Ö§ß§ß§å§ð §á§Ö§â§Ö§Þ§Ö§ß§ß§å§ð
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

	if (head == nullptr) // §¦§ã§Ý§Ú §á§å§ã§ä
	{
		head = newElem;
	}
	else // §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §é§Ö§â§Ö§Ù §ç§Ó§à§ã§ä
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
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	// §¥§Ó§Ö §á§Ö§â§Þ§Ö§ß§ß§í§Ö §Õ§Ý§ñ §å§Õ§à§Ò§ã§ä§Ó§Ñ §à§Ò§â§Ñ§ë§Ö§ß§Ú§ñ (§Ú§ç §Õ§Ó§Ö §ä§Ñ§Ü §Ü§Ñ§Ü §ã§á§Ú§ã§à§Ü §à§Õ§ß§à§ã§Ó§ñ§Ù§ß§í§Û)
	element* first = head;
	element* second = first->next;

	if (first->value == _value) // §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §Ô§à§Ý§à§Ó§å
	{
		head = second;
		delete first;

		return;
	}

	while (second != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		if (second->value == _value)
		{
			first->next = second->next;
			delete second;

			return;
		}

		first = first->next;
		second = first->next;
	}

	if (second->value == _value) // §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §ç§Ó§à§ã§ä
	{
		tail = first;
		tail->next = nullptr;

		delete second;
	}
}

/// <summary>
/// §¯§Ñ§ç§à§Ø§Õ§Ö§ß§Ú§Ö §á§Ö§â§Ó§à§Ô§à §Ó§ç§à§Ø§Õ§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
element* fifo::find(int _value)
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return nullptr;
	}

	element* current = head;
	while (current != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		if (current->value == _value)
		{
			return current;
		}

		current = current->next;
	}

	if (current->value == _value) // §±§â§à§Ó§Ö§â§Ü§Ñ §ç§Ó§à§ã§ä§Ñ
	{
		return current;
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
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return 0;
	}

	int count = 0;

	element* current = head;
	while (current != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		if (current->value == _value)
		{
			count++;
		}

		current = current->next;
	}

	if (current->value == _value) // §±§â§à§Ó§Ö§â§Ü§Ñ §ç§Ó§à§ã§ä§Ñ
	{
		count++;
	}

	return count;
}

/// <summary>
/// §£§í§Ó§à§Õ §ã§á§Ú§ã§Ü§Ñ §ã §ß§Ñ§é§Ñ§Ý§Ñ §Ú §Õ§à §Ü§à§ß§è§Ñ
/// </summary>
void fifo::prints()
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	element* currentHead = head;

	while (currentHead != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		cout << currentHead->value << " ";
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
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	if (current == nullptr)
	{
		current = head;
	}

	if (current != tail) // §µ§ç§à§Õ §Ó §Ü§à§ß§Ö§è
	{
		printf(current->next);
	}

	if (current != head)
	{
		cout << current->value << " ";
	}
	else
	{
		cout << current->value << endl;
	}
}

/// <summary>
/// §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í
/// </summary>
void fifo::display()
{
	int value;
	fifo* lst = new fifo();

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		lst->add(value);

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	// §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í §Þ§Ö§ä§à§Õ§à§Ó fifo- §Ü§Ý§Ñ§ã§ã§Ñ
	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf(0);

	cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §å§Õ§Ñ§Ý§Ö§ß§Ú§ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		lst->pop(value);

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §å§Õ§Ñ§Ý§Ö§ß§Ú§ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf(0);

	cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->find(value) << endl;

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Õ§ã§é§×§ä§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->count(value) << endl;

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Õ§ã§é§×§ä§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}
	
	delete lst;
}