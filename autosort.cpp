#include "autosort.h"
#include "element.h"
#include <iostream>

using namespace std;

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â §Ú §Õ§Ö§ã§ä§â§å§Ü§ä§à§â autosort-§ã§á§Ú§ã§Ü§Ñ
autosort::autosort() : head(nullptr), tail(nullptr) {};
autosort::~autosort()
{
	element_k* current = head;
	while (current != tail)
	{
		element_k* temp = current;
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
void autosort::add(int _key, int _value)
{
	element_k* newElem = new element_k(_key, _value);

	if (head == nullptr)
	{
		head = newElem;
		tail = newElem;
		return;
	}
	else if (tail->key < newElem->key)
	{
		tail->next = newElem;
		tail = newElem;
		return;
	}

	element_k* current = head;
	while (current->next != nullptr && current->next->key < _key)
	{
		current = current->next;
	}

	if (current->key >= newElem->key)
	{
		newElem->next = current;
		if (current == head)
		{
			head = newElem;
		}
	}
	else
	{
		newElem->next = current->next;
		current->next = newElem;
	}
}

/// <summary>
/// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ú§Ù §ã§á§Ú§ã§Ü§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
void autosort::pop(int _value)
{
	element_k* first = head;
	element_k* second = first->next;

	if (first->value == _value)
	{
		head = second;
		delete first;

		return;
	}

	while (second != tail)
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

	if (second->value == _value)
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
element_k* autosort::find(int _value)
{
	element_k* current = head;
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
int autosort::count(int _value)
{
	int count = 0;

	element_k* current = head;
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
void autosort::prints()
{
	element_k* currentHead = head;

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
void autosort::printf(element_k* current = nullptr)
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
void autosort::display()
{
	int key;
	int value;
	autosort* lst = new autosort();

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> key;
	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	
	while (key != 0 && value != 0)
	{
		lst->add(key, value);

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> key;
		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	// §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í §Þ§Ö§ä§à§Õ§à§Ó fifo- §Ü§Ý§Ñ§ã§ã§Ñ
	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf(0);

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §å§Õ§Ñ§Ý§Ú§ä§î ";
	cin >> value;
	lst->pop(value);

	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf(0);

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§ä§à§â§í§Û §ç§à§ä§Ú§ä§Ö §ß§Ñ§Û§ä§Ú ";
	cin >> value;
	cout << lst->find(value) << endl;

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §ï§Ý§Ö§Þ§Ö§ß§ä §ã§á§Ú§ã§Ü§Ñ, §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§à §Ü§à§ä§à§â§í§ç §ç§à§ä§Ú§ä§Ö §á§à§ã§é§Ú§ä§Ñ§ä§î ";
	cin >> value;
	cout << lst->count(value) << endl;

	delete lst;
}