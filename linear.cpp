#include "linear.h"
#include "element.h"
#include <iostream>

using namespace std;

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â §Ú §Õ§Ö§ã§ä§â§å§Ü§ä§à§â autosort-§ã§á§Ú§ã§Ü§Ñ
linear::linear() : head(nullptr), tail(nullptr) {};
linear::~linear()
{
	element_k2_bi* current = head;
	while (current != tail)
	{
		element_k2_bi* temp = current;
		current = current->next;

		delete temp;
	}

	delete tail;

	cout << "OK" << endl;
}

/// <summary>
/// §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §ã§á§Ú§ã§à§Ü
/// </summary>
/// <param name="_value"></param>
void linear::add(int _key1, int _key2, int _value)
{
	element_k2_bi* newElem = new element_k2_bi(_key1, _key2, _value);

	if (head == nullptr)
	{
		head = newElem;
		tail = newElem;
		return;
	}

	if (tail->key1 < newElem->key1 || (tail->key1 == newElem->key1 && tail->key2 <= newElem->key2))
	{
		tail->next = newElem;
		newElem->previous = tail;
		tail = newElem;
		return;
	}

	element_k2_bi* current = head;
	while (current->next
		!= nullptr && (current->next->key1 < newElem->key1 || (current->next->key1 == newElem->key1 && current->next->key2 <= newElem->key2)))
	{
		current = current->next;
	}

	if (current->key1 > newElem->key1 || (current->key1 > newElem->key1 && current->key2 >= newElem->key2))
	{
		newElem->next = current;
		current->previous = newElem;
		head = newElem;
	}
	else
	{
		newElem->next = current->next;
		current->next->previous = newElem;
		current->next = newElem;
		newElem->previous = current;
	}
}

/// <summary>
/// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ú§Ù §ã§á§Ú§ã§Ü§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
void linear::pop(int _value)
{
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	element_k2_bi* temp;
	element_k2_bi* current = head;

	if (current->value == _value)
	{
		temp = current;
		head = current->next;

		head->previous = nullptr;
		delete temp;

		return;
	}

	while (current != tail)
	{
		if (current->value == _value)
		{
			temp = current;

			current->next->previous = current->previous;
			current->previous->next = current->next;

			delete temp;

			return;
		}

		current = current->next;
	}
}

/// <summary>
/// §¯§Ñ§ç§à§Ø§Õ§Ö§ß§Ú§Ö §á§Ö§â§Ó§à§Ô§à §Ó§ç§à§Ø§Õ§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
element_k2_bi* linear::find(int _value)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	element_k2_bi* current = head;
	while (current != tail)
	{
		if (current->value == _value)
		{
			return current;
		}

		current = current->next;
	}

	if (tail->value == _value)
	{
		return tail;
	}

	return nullptr;
}

/// <summary>
/// §±§à§Õ§ã§é§×§ä §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§Ñ §ï§Ý§Ö§Þ§Ö§ß§ä§à§Ó §Ù§Ñ§Õ§Ñ§ß§ß§à§Ô§à §Ù§ß§Ñ§é§Ö§ß§Ú§ñ
/// </summary>
/// <param name="_value"></param>
int linear::count(int _value)
{
	if (head == nullptr)
	{
		return 0;
	}

	int count = 0;

	element_k2_bi* current = head;
	while (current != tail)
	{
		if (current->value == _value)
		{
			count++;
		}

		current = current->next;
	}

	if (tail->value == _value)
	{
		count++;
	}

	return count;
}

/// <summary>
/// §£§í§Ó§à§Õ §ã§á§Ú§ã§Ü§Ñ §ã §ß§Ñ§é§Ñ§Ý§Ñ §Ú §Õ§à §Ü§à§ß§è§Ñ
/// </summary>
void linear::prints()
{
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	element_k2_bi* currentHead = head;

	while (currentHead != tail)
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
void linear::printf()
{
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	element_k2_bi* current = tail;
	while (current->previous != nullptr)
	{
		cout << current->value << " ";
		current = current->previous;
	}

	cout << current->value << endl;
}

/// <summary>
/// §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í
/// </summary>
void linear::display()
{
	int key1;
	int key2;

	int value;

	linear* lst = new linear();

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é #1 §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> key1;
	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é #2 §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> key2;
	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;

	while (key1 != 0 && key2 != 0 && value != 0)
	{
		lst->add(key1, key2, value);

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é #1 §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> key1;
		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é #2 §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> key2;
		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	// §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í §Þ§Ö§ä§à§Õ§à§Ó fifo- §Ü§Ý§Ñ§ã§ã§Ñ
	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf();

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §å§Õ§Ñ§Ý§Ú§ä§î ";
	cin >> value;
	lst->pop(value);

	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf();

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §ß§Ñ§Û§ä§Ú ";
	cin >> value;
	cout << lst->find(value) << endl;

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§à §Ü§à§ä§à§â§í§ç §ç§à§ä§Ú§ä§Ö §á§à§ã§é§Ú§ä§Ñ§ä§î ";
	cin >> value;
	cout << lst->count(value) << endl;

	delete lst;
}